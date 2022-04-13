//
// Created by cjx on 2022/4/11.
//

#ifndef JNIDEMO_TYPETEST_H
#define JNIDEMO_TYPETEST_H
#include "NativeCallbackJavaHandler.h"


class TypeTest {

public:
    TypeTest();
    ~TypeTest();

public:
    void setBasicType(bool bl,
                      char byte,
                      unsigned short _char,
                      short _short,
                      int _int,
                      long long _long,
                      float _float,
                      double _double);

private:
    NativeCallbackJavaHandler* callbackJavaHandler;


};


#endif //JNIDEMO_TYPETEST_H
