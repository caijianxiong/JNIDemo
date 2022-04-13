//
// Created by cjx on 2022/4/11.
//

#ifndef JNIDEMO_JAVAGLOBALREF_H
#define JNIDEMO_JAVAGLOBALREF_H

#include <jni.h>

class JavaGlobalRef {
public:
    JavaGlobalRef();

private:
    ~JavaGlobalRef();

public:
    static JNIEnv *GetEnv();
    static void releaseGlobalRef();

};


#endif //JNIDEMO_JAVAGLOBALREF_H
