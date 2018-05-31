package com.yuangudashen.testcpp.testcpp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);

        Toast.makeText(MainActivity.this,NativeUtils.testGetString("--------")+"|<->|"+NativeUtils.testAdd(5,10),Toast.LENGTH_SHORT).show();
//

        tv.setText(NativeUtils.testGetString("--------")+"|<->|"+NativeUtils.testAdd(5,10));
    }
}
