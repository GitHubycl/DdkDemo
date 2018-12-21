package com.ycl.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.ycl.ndkdemo.jni.JniCore;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    // Example of a call to a native method
        int a =   new JniCore().add(1,2);
        System.out.print("aaaaaaa"+a);
        Log.e("aaaaaa,",""+a);
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText("111111111"+a);
    }

}
