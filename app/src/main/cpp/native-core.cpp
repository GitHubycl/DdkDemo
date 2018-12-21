#include <jni.h>
#include <string>
#include "com_ycl_ndkdemo_jni_JniCore.h"

extern "C"
JNIEXPORT jint JNICALL Java_com_ycl_ndkdemo_jni_JniCore_add(JNIEnv *env, jobject, jint a, jint b) {
    std::string hello = "Hello from C++";
    jint c = use_sub_injava(env,a,b);
    return c;
}

JNIEXPORT jstring JNICALL Java_com_ycl_ndkdemo_jni_JniCore_getString(JNIEnv *, jobject){

}

//调用java层的sub方法
jint use_sub_injava(JNIEnv *env,jint a,jint b){
    //获取类引用
    jclass MyClasss = env->FindClass("com/ycl/ndkdemo/jni/JniCore");
    if(0 == MyClasss){
        return -1;
    }
    //获取构造函数
    jmethodID constructor = env->GetMethodID(MyClasss,"<init>","()V");
    if(0 == constructor){
        return -2;
    }
    //创建对象
    jobject obj = env->NewObject(MyClasss,constructor);
    if(0 == obj){
        env->DeleteLocalRef(MyClasss);
        return -3;
    }
    //根据对象调用成员方法
    jmethodID sub = env->GetMethodID(MyClasss,"java_add","(II)I");
    if(0 == sub){
        env->DeleteLocalRef(MyClasss);
        env->DeleteLocalRef(obj);
        return -4;
    }
    return env->CallIntMethod(obj,sub,a,b);
}
