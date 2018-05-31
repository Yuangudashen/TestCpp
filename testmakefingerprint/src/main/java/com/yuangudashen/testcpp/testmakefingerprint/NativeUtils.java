package com.yuangudashen.testcpp.testmakefingerprint;

/**
 * Created by Administrator on 2018/4/4/004.
 */

public class NativeUtils {

    static {
        System.loadLibrary("fingerprint");
    }

    public static native int main(int argc,String[] argv);
}
