//
// Created by cjx on 2022/4/11.
//

#include <jni.h>
#include <string>
#include <__locale>
#include "JavaGlobalRef.h"
#include "TypeTest.h"
#include "ALog.h"
#include "android/log.h"

extern JavaVM *g_jvm;
extern jobject g_objCallbackHandler;

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    alogd("JNI_OnLoad set jvm");
    if (g_jvm == nullptr) {
        g_jvm = vm;
        alogd("g_jvm :%p", g_jvm);
    }
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_kandaovr_meeting_jnidemo_AndroidJavaNativeApi_init(
        JNIEnv *env,
        jobject /* this */,
        jobject callBackHandler) {
    alogd("init");
    // save jvm
    if (g_jvm == nullptr) {
        env->GetJavaVM(&g_jvm);
        alogd("init set g_jvm :%p", g_jvm);
    }

    // 保存c++回调Java 的类对象
    if (g_objCallbackHandler == nullptr) {
        alogd("set callback handler");
        g_objCallbackHandler = env->NewGlobalRef(callBackHandler);
        if (g_objCallbackHandler == nullptr) {
            alogd("g_objCallbackHandler is null");
        }
    }
    return 0;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_kandaovr_meeting_jnidemo_AndroidJavaNativeApi_setBasicType(JNIEnv *env, jobject thiz,
                                                                    jboolean is, jbyte b, jchar c,
                                                                    jshort st, jint it, jlong lg,
                                                                    jfloat ft, jdouble db) {
    // TODO: implement setBasicType()
    unsigned char bl = is;
    char _byte = b;
    unsigned short _char = c;
    short _short = st;
    int _int = it;
    long long _long = lg;
    float _float = ft;
    double _double = db;
    alogd("setBasicType boolean:%d, byte:%x, char :%c, short:%hd, int:%d ,long:%lld, float:%f, double:%f",
          is, _byte, _char, _short, _int, _long, _float, _double);

    TypeTest test;
    test.setBasicType(bl, _byte, _char, _short, _int, _long, _float, _double);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_kandaovr_meeting_jnidemo_AndroidJavaNativeApi_setObjectType(JNIEnv *env, jobject thiz,
                                                                     jstring str,
                                                                     jobject object_type) {
    // TODO: implement setObjectType()
    // 1,生成jstring
    const char *c_str = "hello word";
    jstring js = env->NewStringUTF(c_str);

    // 2,jstring 转换成 char *
    const char *c_string = env->GetStringUTFChars(str, 0);
    // 3,释放 char *
    env->ReleaseStringUTFChars(str, c_string);

    // 释放局部变量引用
    env->DeleteLocalRef(js);


    // object 操作
    jclass c_obj = env->GetObjectClass(object_type);
    if (c_obj == nullptr) {
        return;
    }

    jfieldID id_strName = env->GetFieldID(c_obj, "name", "Ljava/lang/String;");
    // 取对象属性值
    jstring j_strName = (jstring) env->GetObjectField(object_type, id_strName);

    // 设置对象属性值
    env->SetObjectField(object_type, id_strName, env->NewStringUTF("张三"));

    // 内部类
    jfieldID id_innerClass = env->GetFieldID(c_obj, "innerClass",
                                             "Lcom/kandaovr/meeting/jnidemo/ObjectType/InnerClass;");
    jobject obj_innerClass = env->GetObjectField(object_type, id_innerClass);

    jclass cls_innerClass = env->GetObjectClass(obj_innerClass);
    // 重复上面步骤获取内部类属性

}