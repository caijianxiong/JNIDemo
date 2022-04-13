package com.kandaovr.meeting.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("common");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        AndroidJavaNativeApi javaNativeApi = new AndroidJavaNativeApi();
        CallbackJavaHandler javaHandler = new CallbackJavaHandler();

        new Thread(new Runnable() {
            @Override
            public void run() {
                javaNativeApi.init(javaHandler);
                javaNativeApi.setBasicType(true, (byte) 0x2F, 'a', (short) 8, 50, 5000l, 4.0f, 2.55);
            }
        }).start();

    }
}