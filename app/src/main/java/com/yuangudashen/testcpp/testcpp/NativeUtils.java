package com.yuangudashen.testcpp.testcpp;

public class NativeUtils {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native static String testGetString(String str);

    // public native static String testGetString();


    public native static int testAdd(int a,int b);
}
