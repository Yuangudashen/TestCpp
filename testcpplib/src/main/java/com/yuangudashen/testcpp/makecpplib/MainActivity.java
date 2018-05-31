package com.yuangudashen.testcpp.makecpplib;

import android.graphics.Color;
import android.graphics.DashPathEffect;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.github.mikephil.charting.charts.LineChart;
import com.github.mikephil.charting.components.Legend;
import com.github.mikephil.charting.components.LimitLine;
import com.github.mikephil.charting.components.XAxis;
import com.github.mikephil.charting.components.YAxis;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.LineData;
import com.github.mikephil.charting.data.LineDataSet;
import com.github.mikephil.charting.interfaces.datasets.ILineDataSet;
import com.github.mikephil.charting.utils.Utils;

import java.util.ArrayList;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";
    private TextView result_tv;
    private LineChart line_chat;
    private DoublePoint[] points;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        result_tv = (TextView) findViewById(R.id.result_tv);
        line_chat = (LineChart) findViewById(R.id.line_chat);

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

            points = new DoublePoint[psdXValue.length];
            DoublePoint point =null;
            for (int i = 0; i < psdXValue.length; i++) {
                point = new DoublePoint();
                point.x = psdXValue[i];
                point.y = psdYValue[i];
                points[i] = point;
                point = null;
            }
            setLineChat();


        } else if (result == -1) {
            result_tv.append("\n----------------\n");
            result_tv.append("输入参数错误" + "\n");
        }
        result_tv.invalidate();
    }


    private void setLineChat() {
        line_chat.setDrawGridBackground(true);

        // no description text
        line_chat.getDescription().setEnabled(false);

        // enable touch gestures
        line_chat.setTouchEnabled(false);

        // enable scaling and dragging
        line_chat.setDragEnabled(false);
        line_chat.setScaleEnabled(true);

        // if disabled, scaling can be done on x- and y-axis separately
        line_chat.setPinchZoom(false);
        line_chat.setMaxVisibleValueCount(150);

        XAxis xAxis = line_chat.getXAxis();
        // xAxis.enableGridDashedLine(10f, 10f, 0f);
        xAxis.setPosition(XAxis.XAxisPosition.BOTTOM);
        xAxis.setLabelCount(12);

//        // Typeface tf = Typeface.createFromAsset(getAssets(), "OpenSans-Regular.ttf");

        LimitLine ll1 = new LimitLine(0.5f);
        ll1.setLineWidth(1f);
        ll1.enableDashedLine(10f, 10f, 0f);
        ll1.setLabelPosition(LimitLine.LimitLabelPosition.RIGHT_BOTTOM);
        ll1.setTextSize(10f);
//        // ll1.setTypeface(tf);
//
//        LimitLine ll2 = new LimitLine(0.0f);
//        ll2.setLineWidth(1f);
//        ll2.enableDashedLine(10f, 10f, 0f);
//        ll2.setLabelPosition(LimitLine.LimitLabelPosition.RIGHT_TOP);
//        ll2.setTextSize(10f);
//        // ll2.setTypeface(tf);

        YAxis leftAxis = line_chat.getAxisLeft();
        leftAxis.removeAllLimitLines(); // reset all limit lines to avoid overlapping lines
        leftAxis.addLimitLine(ll1);
        // leftAxis.addLimitLine(ll2);
        leftAxis.setLabelCount(10);
        leftAxis.setAxisMaximum(0.05f);
        leftAxis.setAxisMinimum(0.0f);
        // leftAxis.setYOffset(10f);
        leftAxis.enableGridDashedLine(10f, 10f, 0f);
        leftAxis.setDrawZeroLine(true);

        // limit lines are drawn behind data (and not on top)
        leftAxis.setDrawLimitLinesBehindData(true);

        line_chat.getAxisRight().setEnabled(false);

        //item_correct_rate_lc.getViewPortHandler().setMaximumScaleY(2f);
        //item_correct_rate_lc.getViewPortHandler().setMaximumScaleX(2f);

        setLineChatData(points);

//        item_correct_rate_lc.setVisibleXRange(20);
//        item_correct_rate_lc.setVisibleYRange(20f, AxisDependency.LEFT);
//        item_correct_rate_lc.centerViewTo(20, 50, AxisDependency.LEFT);

        line_chat.animateX(100);
        //item_correct_rate_lc.invalidate();

        // get the legend (only possible after setting data)
        Legend l = line_chat.getLegend();

        // modify the legend ...
        l.setForm(Legend.LegendForm.LINE);
    }

    public void setLineChatData(DoublePoint[] points) {
        int dataSize = points.length;
        ArrayList<Entry> values = new ArrayList<Entry>();

        for (int i = 0; i < dataSize; i++) {
            values.add(new Entry((float)points[i].x, (float) points[i].y));
        }

        LineDataSet lineDataSet;

        if (line_chat.getData() != null && line_chat.getData().getDataSetCount() > 0) {
            lineDataSet = (LineDataSet) line_chat.getData().getDataSetByIndex(0);
            lineDataSet.setValues(values);
            line_chat.getData().notifyDataChanged();
            line_chat.notifyDataSetChanged();
        } else {
            // create a dataset and give it a type
            lineDataSet = new LineDataSet(values, "PSD-VALUE");
            lineDataSet.setMode(LineDataSet.Mode.CUBIC_BEZIER);

            lineDataSet.setDrawIcons(false);
            lineDataSet.setDrawValues(false);

            // set the line to be drawn like this "- - - - - -"
            lineDataSet.enableDashedLine(10f, 5f, 0f);
            lineDataSet.enableDashedHighlightLine(10f, 5f, 0f);
            lineDataSet.disableDashedLine();
            lineDataSet.setColor(Color.BLACK);
            lineDataSet.setCircleColor(Color.BLACK);
            lineDataSet.setLineWidth(2f);
            lineDataSet.setCircleRadius(1f);
            lineDataSet.setDrawCircleHole(false);
            lineDataSet.setDrawCircles(false);
            lineDataSet.setValueTextSize(9f);
            lineDataSet.setDrawFilled(true);
            lineDataSet.setFormLineWidth(1f);
            lineDataSet.setFormLineDashEffect(new DashPathEffect(new float[]{10f, 5f}, 0f));
            lineDataSet.setFormSize(15.f);

            if (Utils.getSDKInt() >= 18) {
                // fill drawable only supported on api level 18 and above
                Drawable drawable = ContextCompat.getDrawable(this, R.drawable.fade_green);
                lineDataSet.setFillDrawable(drawable);
            } else {
                lineDataSet.setFillColor(Color.BLACK);
            }

            ArrayList<ILineDataSet> dataSets = new ArrayList<ILineDataSet>();
            dataSets.add(lineDataSet); // add the datasets

            // create a data object with the datasets
            LineData data = new LineData(dataSets);

            // set data
            line_chat.setData(data);
        }

    }

}
