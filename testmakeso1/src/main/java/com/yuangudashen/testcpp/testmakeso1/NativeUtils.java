package com.yuangudashen.testcpp.testmakeso1;

/**
 * Created by Administrator on 2017/11/10/010.
 */

public class NativeUtils {

    static {
        System.loadLibrary("NativeSample");
    }

    public static native int testAdd(int a,int b);
}
