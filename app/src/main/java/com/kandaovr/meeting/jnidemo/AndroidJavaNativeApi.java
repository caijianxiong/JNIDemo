package com.kandaovr.meeting.jnidemo;

public class AndroidJavaNativeApi {

    public native int init(CallbackJavaHandler javaHandler);

    public native void setBasicType(boolean is, byte b, char c, short st, int it, long lg, float ft, double db);

    public native void setObjectType(String str,ObjectType objectType);

}
