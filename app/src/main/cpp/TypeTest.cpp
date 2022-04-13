//
// Created by cjx on 2022/4/11.
//

#include "TypeTest.h"
#include "ALog.h"

TypeTest::TypeTest() : callbackJavaHandler(nullptr) {
    callbackJavaHandler = new NativeCallbackJavaHandler;
}

TypeTest::~TypeTest() {
    callbackJavaHandler = nullptr;
}

void TypeTest::setBasicType(bool bl, char byte, unsigned short _char, short _short, int _int,
                            long long int _long, float _float, double _double) {
    alogd("setBasicType");
    if (callbackJavaHandler != nullptr) {
        callbackJavaHandler->onSetBasicTypeOk();
    }

}

