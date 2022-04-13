//
// Created by cjx on 2022/4/11.  C++方法回调Java方法
//

#include "NativeCallbackJavaHandler.h"
#include "JavaGlobalRef.h"
#include "ALog.h"

extern jobject g_objCallbackHandler;
const char *name_onSetBasicTypeOk = "onSetBasicTypeOk"; // g_objCallbackHandler对应Java文件中方法名

void NativeCallbackJavaHandler::onSetBasicTypeOk() {
    alogd("onSetBasicTypeOk");
    JNIEnv *env = JavaGlobalRef::GetEnv(); // 获取Java环境参数 env
    if (g_objCallbackHandler == nullptr) {
        alogd("g_objCallbackHandler is null");
        return;
    }
    // java 方法public void onSetBasicTypeOk(String msg) {}
    jclass cls_handler = env->GetObjectClass(g_objCallbackHandler); // 通过g_objCallbackHandler获取jclass对象
    jmethodID id_onSetBasicTypeOk = env->GetMethodID(cls_handler, name_onSetBasicTypeOk,
                                                     "(Ljava/lang/String;)V"); // "(Ljava/lang/String;)V" Java方法签名

    jstring msg = env->NewStringUTF("hello"); // java 方法传参
    if (id_onSetBasicTypeOk != 0) {
        env->CallVoidMethod(g_objCallbackHandler, id_onSetBasicTypeOk, msg);
    }
    env->DeleteLocalRef(msg);
}
