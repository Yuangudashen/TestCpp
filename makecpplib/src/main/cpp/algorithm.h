//
// Created by Administrator on 2017/11/7/007.
//

#ifndef TESTCPP_ALGORITHM_H
#define TESTCPP_ALGORITHM_H

#include <jni.h>
#include <string>
#include "algorithmlib.h"


extern "C" {

JNIEXPORT jboolean JNICALL
Java_com_yuangudashen_testcpp_makecpplib_NativeUtils_SetWaveltType(JNIEnv *env, jclass type,
                                                                   jstring wname);

JNIEXPORT jboolean JNICALL
Java_com_yuangudashen_testcpp_makecpplib_NativeUtils_SetThresholdFrequency(JNIEnv *env, jclass type,
                                                                           jdouble frequency);
JNIEXPORT jint JNICALL
Java_com_yuangudashen_testcpp_makecpplib_NativeUtils_GetPSDValue(JNIEnv *env, jclass type,
                                                                 jdoubleArray data, jint dataSize,
                                                                 jobject psdDataDef_);
}




#endif //TESTCPP_ALGORITHM_H
