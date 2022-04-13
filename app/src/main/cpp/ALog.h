//
// Created by cjx on 2022/4/12.
//

#ifndef JNIDEMO_ALOG_H
#define JNIDEMO_ALOG_H

#include <android/log.h>

#define LOG_TAG "logtest"
#define alogd(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,__VA_ARGS__);

//#define alogv(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,"[%s]:[%s]:(%d):%s",__FILE_NAME__,__FUNCTION__ ,__LINE__,__VA_ARGS__);
//#define alogd(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,"[%s]:[%s]:(%d) :%s",__FILE_NAME__,__FUNCTION__ ,__LINE__,##__VA_ARGS__);
//#define alogi(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG,"[%s]:[%s]:(%d):%s",__FILE_NAME__,__FUNCTION__ ,__LINE__,__VA_ARGS__);
//#define alogw(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG,"[%s]:[%s]:(%d):%s",__FILE_NAME__,__FUNCTION__ ,__LINE__,__VA_ARGS__);
//#define aloge(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,"[%s]:[%s]:(%d):%s",__FILE_NAME__,__FUNCTION__ ,__LINE__,__VA_ARGS__);




#endif //JNIDEMO_ALOG_H


