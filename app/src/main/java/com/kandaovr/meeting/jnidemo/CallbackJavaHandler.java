package com.kandaovr.meeting.jnidemo;

import android.util.Log;

public class CallbackJavaHandler {
    private String TAG = this.getClass().getSimpleName();

    public void onSetBasicTypeOk(String msg) {
        Log.i(TAG, "onSetBasicTypeOk: java rev");
    }
}
