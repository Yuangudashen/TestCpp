#ifndef TESTCPP_ALGORITHMLIB_H
#define TESTCPP_ALGORITHMLIB_H


typedef double Type;

//PSD计算结果类型
typedef struct _psdDataDef {
    Type psdYValue[257];    //PSD的Y轴坐标
    Type psdXValue[257];    //PSD的X轴坐标
    Type TP;                //TP
    Type VLF;                //VLF
    Type LF;                //LF
    Type HF;                //HF
    Type nLF;                //LF norm
    Type nHF;                //HF norm
    Type LF_HF;                //LF/HF
} psdDataDef;

class CAlgorithmLib {
public:
/*构造函数CAlgorithmLib
  参数:
			第一个: 小波类型 "db4" or "db6" (默认 "db6"))
			第二个: 小波的截止频率 (默认 0.004Hz)
*/
    CAlgorithmLib(const char *_wname = "db6", const Type _Threshold_Frequency = 0.004);

/*计算函数GetPSDValue
  参数:
			第一个: 输入信号
			第二个: 输入信号长度（大于0)
			第三个: 输出结果
  返回值:
			0: 成功
			-1: 输入参数错误
*/
    int GetPSDValue(const Type *const, const int &, psdDataDef &);

/*设置小波类型函数SetWaveltType
  参数:
			第一个: 设置小波类型(db4或db6）
  返回值:
			true: 成功
			false: 输入参数错误
*/
    bool SetWaveltType(const char *_wname);

/*设置小波截止频率函数SetThresholdFrequency
  参数:
			第一个: 需要设置的截止频域 (0~0.5)
  返回值:
			true: 成功
			false: 输入参数错误
*/
    bool SetThresholdFrequency(const Type _frequency);

private:
    //私有变量
    const char *wname;
    Type Threshold_Frequency;
};

//* 下述方法为转动态库定义方法
/*设置小波类型函数SetWaveltType
  参数:
			第一个: 设置小波类型(db4或db6）
  返回值:
			true: 成功
			false: 输入参数错误
*/
bool SetWaveltType(const char *_wname);

/*设置小波截止频率函数SetThresholdFrequency
  参数:
			第一个: 需要设置的截止频域 (0~0.5)
  返回值:
			true: 成功
			false: 输入参数错误
*/
bool SetThresholdFrequency(const Type _frequency);

/*计算函数GetPSDValue
  参数:
			第一个: 输入信号
			第二个: 输入信号长度（大于0)
			第三个: 输出结果
  返回值:
			0: 成功
			-1: 输入参数错误
*/
int GetPSDValue(const Type *const, const int&, psdDataDef&);

#endif