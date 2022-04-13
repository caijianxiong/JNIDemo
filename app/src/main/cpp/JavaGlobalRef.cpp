//
// Created by cjx on 2022/4/11.
//

#include "JavaGlobalRef.h"
#include "ALog.h"

JavaVM *g_jvm = nullptr;
jobject g_objCallbackHandler = nullptr;

JNIEnv *JavaGlobalRef::GetEnv() {
    int status;
    JNIEnv *_jniEnv = NULL;
    status = g_jvm->GetEnv((void **) &_jniEnv, JNI_VERSION_1_6);
    JavaVMAttachArgs args = {JNI_VERSION_1_6, __FUNCTION__, nullptr};

    if (status < 0) {
        status = g_jvm->AttachCurrentThread(&_jniEnv, &args);//获得了可以使用的env
        if (status < 0) {
            _jniEnv = NULL;
        }
    }
    return _jniEnv;
}

void JavaGlobalRef::releaseGlobalRef() {
    if (g_jvm != nullptr) {
        g_jvm->DetachCurrentThread();
        g_jvm->DestroyJavaVM();
        g_jvm = nullptr;
    }
}

JavaGlobalRef::JavaGlobalRef() = default;

JavaGlobalRef::~JavaGlobalRef() = default;
