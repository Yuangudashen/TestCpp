#include "algorithmlib.h"
#include "dwt.h"
#include "spline3interp.h"
#include "classicalpse.h"
#include <string>

using namespace splab;

//构造函数（默认_wname为db6，Threshold_Frequency为0.004Hz）
CAlgorithmLib::CAlgorithmLib(const char* _wname , const Type _Threshold_Frequency)
		:wname(_wname),Threshold_Frequency(_Threshold_Frequency)
{
}

//设置小波类型(db4或db6）
bool CAlgorithmLib::SetWaveltType(const char* _wname)
{
	if(strcmp(_wname,"db4")==0)
		wname = "db4";
	else if(strcmp(_wname,"db6")==0)
		wname = "db6";
	else
		return false;
	return true;
}

//设置小波分解层数计算过程中的截止频率
bool CAlgorithmLib::SetThresholdFrequency(const Type _frequency)
{
	if(_frequency<=0 || _frequency>=0.5)
		return false;
	else
		Threshold_Frequency = _frequency;
	return true;
}

/*
计算PSD频域相关参数
参数说明：
in：输入信号
in_len：输入信号长度
out：输出结果
返回值：	-1：输入参数有误
		0：成功
*/
int CAlgorithmLib::GetPSDValue(const Type* const in,const int &in_len, psdDataDef &out)
{
	/******************************** [ IN ] *******************************/
	if(in_len <= 0)
		return -1;
	//复制原始输入信号 s
	Vector<Type> s(in_len,in);
	//计算信号s的长度len
	int len = s.size();
	//计算信号s的和T（相当于RR的总时间）
	Type T = sum(s);
	/******************************** [ DWT ] ********************************/
	//计算DWT的阶数level
	int level = (int)floor(log(len/(2*T*Threshold_Frequency))/log(2.0));
	//初始化DWT算法类 (wname默认: db6)
	DWT<Type> discreteWT(wname);
	//对信号s进行level阶小波分解
	Vector<Type> coefs = discreteWT.dwt( s, level );
	//获取逼近分量的个数
	int appcoef_len = discreteWT.getApprox(coefs).size();
	//将逼近分量全部设为0
	discreteWT.setApprox(Vector<Type>(appcoef_len,0.0),coefs);
	/******************************** [ IDWT ] *******************************/
	level = 0;
	//进行小波重构得到去除基线后信号y（level必须为0）
	Vector<Type> y = discreteWT.idwt( coefs, level );
	/******************************** [ SPLINE ] *****************************/
	//计算信号y的时间坐标x
	Vector<Type> x(len,0.0);
	x[0] = s[0];
	for(int i = 1; i<len; i++)
		x[i] = x[i-1] + s[i];
	//计算插值后的信号y1的长度（插值使用0.5s时间间隔）
	int new_len = (int)(T*2-1);
	//计算插值后的信号y1的时间坐标x1
	Vector<Type> x1(new_len,0.0);
	x1[0] = x[0];
	for(int i = 1; i<new_len; i++)
		x1[i] = x1[i-1] + 0.5;	//0.5s时间间隔
	//用信号y初始化三次插值算法类
	Spline3Interp<Type> poly( x, y);
	//计算插值函数系数
	poly.calcCoefs();
	//计算插值后信号y1
	Vector<Type> y1 = poly.evaluate(x1);
	/******************************** [ PSD ] *******************************/
	//计算分段段数layer
	int layer = y1.size()/512;
	if(layer < 1)
		layer = 1;
	//初始化hanning窗函数，放大倍数为1
	Vector<Type> wn;
	if(layer > 1)	//如果分段数 > 1, 使用1024的窗
		wn = window( "Hanning", 1024, Type(1.0) );
	else			//否则使用和y1长度一致的窗
		wn = window( "Hanning", y1.size(), Type(1.0) );
	//初始化hrv功率谱密度Ps
	Vector<Type> Ps(1024,(Type)0);
	if(layer > 1)	//如果分段数 > 1, 分段处理
	{
		//分段计数
		int col = 0;
		while(layer > 1)
		{
			Vector<Type> temp(1024,Type(0));
			//每次取信号y1的位置0,512,1024,1536...开始的1024个数据
			for(int i = 0; i < 1024; i++)
				temp[i] = y1[col*512+i];
			//计算每段的PSD，并累加
			Ps += periodogramPSE( temp, wn, 1024 );
			//循环计数
			col++;
			layer--;
		}
		//累加后的PSD除以分段数和y1的长度
		Ps /= (Type)(col*y1.size());
	}
	else			//如果分段数== 1， 则对y1进行补0到1024长度后进行PSD计算
	{
		Ps = periodogramPSE( y1, wn, 1024 )/((Type)y1.size());
	}
	/************************ [ 0.01Hz -> Highpass Filter ] *****************/
	//高频滤波系数（开始的6个点）
	Type HighPassFilter[] =
			{	0.437747378654260,0.645280156992463,
		        0.824852033946074,1.08108503540703,
		        1.19634897459946,0.971383376473972
			};
	//高通滤波 频域相乘
	for(int i = 0; i< 6; i++)
		Ps[i] *= HighPassFilter[i];
	/******************************** [ OUT ] *******************************/
	//将功率谱密度Ps赋值给out的y坐标
	for(int i = 0; i < 257; i++)
		out.psdYValue[i] = Ps[i];
	//计算out的x坐标（0~0.5Hz,共257个点)
	out.psdXValue[0] = 0;
	for(int i = 1; i < 257; i++)
		out.psdXValue[i] = out.psdXValue[i-1] + 0.5/256;
	//计算TP（0~0.4Hz）
	Type TP = 0;
	for(int i = 1; i < 206; i++)
		TP += (Ps[i]+Ps[i-1])*0.25/256;
	out.TP = TP*1000000;
	//梯形面积法计算VLF（0~0.04Hz 不包含直流分量）
	Type VLF = 0;
	for(int i = 1; i < 21; i++)
		VLF += (Ps[i]+Ps[i-1])*0.25/256;
	out.VLF = VLF*1000000;
	//梯形面积法计算LF（0.04~0.15Hz）
	Type LF = 0;
	for(int i = 21; i < 79; i++)
		LF += (Ps[i]+Ps[i-1])*0.25/256;
	out.LF = LF*1000000;
	//梯形面积法计算HF（0.15~0.4Hz）
	Type HF = 0;
	for(int i = 79; i < 206; i++)
		HF += (Ps[i]+Ps[i-1])*0.25/256;
	out.HF = HF*1000000;
	//计算LF norm
	out.nLF = LF / (TP - VLF)*100;
	//计算HF norm
	out.nHF = HF / (TP - VLF)*100;
	//计算LF/HF
	out.LF_HF = LF / HF;
	return 0;
}


//* 下述方法为转动态库定义方法
//设置小波类型(db4或db6）
bool SetWaveltType(const char* _wname)
{
	//定义算法库类（截止频率默认0.004Hz）
	CAlgorithmLib Algorithm;
	//使用db6小波
	return Algorithm.SetWaveltType(_wname);
}

//设置小波分解层数计算过程中的截止频率
bool SetThresholdFrequency(const Type _frequency)
{
	//定义算法库类（截止频率默认0.004Hz）
	CAlgorithmLib Algorithm;
	//使用db6小波
	return Algorithm.SetThresholdFrequency(_frequency);
}

/*
计算PSD频域相关参数
参数说明：
in：输入信号
in_len：输入信号长度
out：输出结果
返回值：	-1：输入参数有误
		0：成功
*/
int GetPSDValue(const Type* const in,const int &in_len, psdDataDef &out)
{
	//定义算法库类（截止频率默认0.004Hz）
	CAlgorithmLib Algorithm;
	//使用db6小波
	return Algorithm.GetPSDValue(in,in_len,out);
}