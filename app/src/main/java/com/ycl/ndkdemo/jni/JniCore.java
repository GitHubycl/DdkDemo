package com.ycl.ndkdemo.jni;

/**
 * Created by chengliang.yu on 2018/12/20.
 */

public class JniCore {

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int add(int a,int b);

    public native String getString();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-core");
    }

    public int java_add(int a ,int b){
        return a+b;
    }

}
