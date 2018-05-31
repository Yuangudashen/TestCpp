package com.yuangudashen.testcpp.makecpplib;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView result_tv = (TextView) findViewById(R.id.result_tv);

        // LineView line_view = (LineView) findViewById(R.id.line_view);

        result_tv.setText("");

        result_tv.append("SetWaveltType -> " + NativeUtils.SetWaveltType(NativeUtils.DB6) + "\n");
        result_tv.invalidate();
        Double frequency = 0.3;
        result_tv.append("SetThresholdFrequency -> " + NativeUtils.SetThresholdFrequency(frequency) + "\n");
        result_tv.invalidate();

        PsdDataDef psdDataDef = new PsdDataDef();

        int result = NativeUtils.GetPSDValue(NativeUtils.data, NativeUtils.dataSize, psdDataDef);

        Log.e(TAG, "GetPSDValue -> " + result);

        result_tv.append("GetPSDValue -> " + result + "\n");


        if (result == 0) {

            double[] psdYValue = psdDataDef.psdYValue;
            double[] psdXValue = psdDataDef.psdXValue;
            double TP = psdDataDef.TP;
            double VLF = psdDataDef.VLF;
            double LF = psdDataDef.LF;
            double HF = psdDataDef.HF;
            double nLF = psdDataDef.nLF;
            double nHF = psdDataDef.nHF;
            double LF_HF = psdDataDef.LF_HF;

            result_tv.append("\n----------------\n");
            result_tv.append("成功" + "\n");

            result_tv.append("TP = "+TP + "\n");
            result_tv.append("VLF = "+VLF + "\n");
            result_tv.append("LF = "+LF + "\n");
            result_tv.append("HF = "+HF + "\n");
            result_tv.append("nLF = "+nLF + "\n");
            result_tv.append("nHF = "+nHF + "\n");
            result_tv.append("LF_HF = "+LF_HF + "\n");

            result_tv.append("psdYValue = \n"+ Arrays.toString(psdYValue) + "\n");
            result_tv.append("psdXValue = \n"+Arrays.toString(psdXValue) + "\n");

//            DoublePoint[] points = new DoublePoint[psdXValue.length];
//            DoublePoint point =null;
//            for (int i = 0; i < psdXValue.length; i++) {
//                point = new DoublePoint();
//                point.x = psdXValue[i];
//                point.y = psdYValue[i];
//                points[i] = point;
//                point = null;
//            }



        } else if (result == -1) {
            result_tv.append("\n----------------\n");
            result_tv.append("输入参数错误" + "\n");
        }
        result_tv.invalidate();


        // Toast.makeText(MainActivity.this,""+NativeUtils.SetWaveltType(NativeUtils.DB6),Toast.LENGTH_SHORT).show();
    }

}
