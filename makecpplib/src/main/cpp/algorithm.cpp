//
// Created by Administrator on 2017/11/7/007.
//


#include "algorithm.h"
using namespace std;

template <class T>

int getArrayLen(T& array)

{//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度

    return (sizeof(array) / sizeof(array[0]));

}


JNIEXPORT jboolean JNICALL
Java_com_yuangudashen_testcpp_makecpplib_NativeUtils_SetWaveltType(JNIEnv *env, jclass type,
                                                                   jstring wname){

    const char *_wname = env->GetStringUTFChars(wname, 0);

    jboolean response = SetWaveltType(_wname);

    env->ReleaseStringUTFChars(wname,_wname);

    return response;
}

JNIEXPORT jboolean JNICALL
Java_com_yuangudashen_testcpp_makecpplib_NativeUtils_SetThresholdFrequency(JNIEnv *env, jclass type,
                                                                           jdouble frequency) {

    // const Type frequency

    jboolean response = (jboolean) SetThresholdFrequency(frequency);

    return response;

}

JNIEXPORT jint JNICALL
Java_com_yuangudashen_testcpp_makecpplib_NativeUtils_GetPSDValue(JNIEnv *env, jclass type,
                                                                 jdoubleArray data, jint dataSize,
                                                                 jobject psdDataDef_){

    jdouble *_data = env->GetDoubleArrayElements(data, false);

    _psdDataDef psdDataDef_c;

    jint _jint = GetPSDValue(_data, dataSize, psdDataDef_c);


    jclass jclass_psdDataDef = env->GetObjectClass(psdDataDef_);

    jfieldID fid_tp,fid_vlf,fid_lf,fid_hf,fid_nlf,fid_nhf,fid_lf_hf,fid_psdYValue,fid_psdXValue;

    fid_tp = env->GetFieldID(jclass_psdDataDef,"TP","D");
    fid_vlf = env->GetFieldID(jclass_psdDataDef,"VLF","D");
    fid_lf = env->GetFieldID(jclass_psdDataDef,"LF","D");
    fid_hf = env->GetFieldID(jclass_psdDataDef,"HF","D");
    fid_nlf = env->GetFieldID(jclass_psdDataDef,"nLF","D");
    fid_nhf = env->GetFieldID(jclass_psdDataDef,"nHF","D");
    fid_lf_hf = env->GetFieldID(jclass_psdDataDef,"LF_HF","D");
    fid_psdYValue = env->GetFieldID(jclass_psdDataDef,"psdYValue","[D");
    fid_psdXValue = env->GetFieldID(jclass_psdDataDef,"psdXValue","[D");

    if(fid_tp == NULL){
        return 1;
    }

    // jdouble j_tp = env->GetDoubleField(psdDataDef_,fid_tp);

    env->SetDoubleField(psdDataDef_,fid_tp,psdDataDef_c.TP);
    env->SetDoubleField(psdDataDef_,fid_vlf,psdDataDef_c.VLF);
    env->SetDoubleField(psdDataDef_,fid_lf,psdDataDef_c.LF);
    env->SetDoubleField(psdDataDef_,fid_hf,psdDataDef_c.HF);
    env->SetDoubleField(psdDataDef_,fid_nlf,psdDataDef_c.nLF);
    env->SetDoubleField(psdDataDef_,fid_nhf,psdDataDef_c.nHF);
    env->SetDoubleField(psdDataDef_,fid_lf_hf,psdDataDef_c.LF_HF);


    jdoubleArray jdArr_psdYValue = (jdoubleArray) env->GetObjectField(psdDataDef_, fid_psdYValue);
    jdoubleArray jdArr_psdXValue = (jdoubleArray) env->GetObjectField(psdDataDef_, fid_psdXValue);

    jdouble *jY = env->GetDoubleArrayElements(jdArr_psdYValue,false);
    jdouble *jX = env->GetDoubleArrayElements(jdArr_psdXValue,false);

    jsize psdYLen = getArrayLen(psdDataDef_c.psdYValue);
    jsize psdXLen = getArrayLen(psdDataDef_c.psdXValue);

    for (int i = 0; i < psdYLen; ++i) {
        jY[i] = psdDataDef_c.psdYValue[i];
    }
    for (int i = 0; i < psdXLen; ++i) {
        jX[i] = psdDataDef_c.psdXValue[i];
    }

    env->SetDoubleArrayRegion(jdArr_psdYValue,0,psdYLen,jY);
    env->SetDoubleArrayRegion(jdArr_psdXValue,0,psdXLen,jX);

    env->SetObjectField(psdDataDef_, fid_psdYValue, jdArr_psdYValue);
    env->SetObjectField(psdDataDef_, fid_psdXValue, jdArr_psdXValue);

    // 释放资源
    env->ReleaseDoubleArrayElements(data, _data, 0);
    env->ReleaseDoubleArrayElements(jdArr_psdYValue,jY,0);
    env->ReleaseDoubleArrayElements(jdArr_psdXValue,jX,0);
    env->DeleteLocalRef(jclass_psdDataDef);

    return _jint;
}



///*设置小波截止频率函数SetThresholdFrequency
//  参数:
//			第一个: 需要设置的截止频域 (0~0.5)
//  返回值:
//			true: 成功
//			false: 输入参数错误
//*/
//bool SetThresholdFrequency(const Type _frequency);
//
///*计算函数GetPSDValue
//  参数:
//			第一个: 输入信号
//			第二个: 输入信号长度（大于0)
//			第三个: 输出结果
//  返回值:
//			0: 成功
//			-1: 输入参数错误
//*/
//int GetPSDValue(const Type* const ,const int&, psdDataDef&);
