package com.yuangudashen.testcpp.testmakeso1;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);




        Toast.makeText(this,""+NativeUtils.testAdd(5,10), Toast.LENGTH_SHORT).show();
    }
}
