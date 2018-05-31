#include "native-lib.h"

//定义一个全局变量
Machine machine;

/**
 * C字符串转java字符串
 */
jstring strToJstring(JNIEnv *env, const char *pStr) {
    int strLen = strlen(pStr);
    jclass jstrObj = env->FindClass("java/lang/String");
    jmethodID methodId = env->GetMethodID(jstrObj, "<init>", "([BLjava/lang/String;)V");
    jbyteArray byteArray = env->NewByteArray(strLen);
    jstring encode = env->NewStringUTF("utf-8");
    env->SetByteArrayRegion(byteArray, 0, strLen, (jbyte *) pStr);
    return (jstring) env->NewObject(jstrObj, methodId, byteArray, encode);
}

/**
 * jstring -> UTF-8
 */
char *jstringToUTF8(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes",
                                     "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);

        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);

    return rtn;
}

JNIEXPORT jstring JNICALL
Java_com_yuangudashen_testcpp_testcpp_NativeUtils_testGetString(JNIEnv *env, jclass type, jstring str_) {
    char *ch = jstringToUTF8(env, str_);
    return env->NewStringUTF(ch);
}


JNIEXPORT jint JNICALL
Java_com_yuangudashen_testcpp_testcpp_NativeUtils_testAdd(JNIEnv *env, jclass type, jint a, jint b) {
    return machine.testAdd(a,b);
}
