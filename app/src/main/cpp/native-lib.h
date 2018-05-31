//
// Created by Administrator on 2017/11/3/003.
//

#ifndef TESTCPP_NATIVE_LIB_H
#define TESTCPP_NATIVE_LIB_H

#include <jni.h>
#include <string>
#include "machine.h"

extern "C" {


extern Machine machine;

JNIEXPORT jstring JNICALL
Java_com_yuangudashen_testcpp_testcpp_NativeUtils_testGetString(
        JNIEnv *env,
        jclass type,jstring str_);

JNIEXPORT jint JNICALL
Java_com_yuangudashen_testcpp_testcpp_NativeUtils_testAdd(
        JNIEnv *env,
        jclass type,
        jint a,
        jint b);

//JNIEXPORT jstring JNICALL
//Java_com_yuangudashen_testcpp_testcpp_NativeUtils_testGetString(JNIEnv *env,jclass type);


}


#endif //TESTCPP_NATIVE_LIB_H


