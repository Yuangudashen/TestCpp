package com.yuangudashen.testcpp.makecpplib.coustomviews;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.view.View;

/**
 * Created by Administrator on 2017/11/20/020.
 */

public class LineView extends View {

    DoublePoint[] points;

    public void setPoints(DoublePoint[] points) {
        this.points = points;
        initData();
    }

    private int viewWidth;

    private int viewHeight;

    private Paint paint;

    private Path path;

    public LineView(Context context) {
        this(context,null);
    }

    public LineView(Context context, @Nullable AttributeSet attrs) {
        this(context, attrs,0);
    }

    public LineView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);

        points = new DoublePoint[257];

        initPaint();
    }

    private void initPaint() {
        paint = new Paint();
        paint.setAntiAlias(true);
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setStyle(Paint.Style.FILL);
        paint.setColor(Color.RED);
        paint.setStrokeWidth(4);
    }

    private void initData() {
        path = new Path();

        for (int i = 0; i < points.length; i++) {
            DoublePoint point = points[i];
            if(i==0){
                path.moveTo((float)point.x,(float)point.y);
            }else{
                path.lineTo((float)point.x,(float)point.y);
            }
        }
    }


    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
        viewWidth = w;
        viewHeight = h;

        initData();
    }


    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
        int width, height;
        int widthSize = MeasureSpec.getSize(widthMeasureSpec);
        int heightSize = MeasureSpec.getSize(heightMeasureSpec);
        int widthMode = MeasureSpec.getMode(widthMeasureSpec);
        int heightMode = MeasureSpec.getMode(heightMeasureSpec);

        viewWidth = widthSize;
        viewHeight = heightSize;

        if (widthMode == MeasureSpec.EXACTLY) {
            width = widthSize;
        } else {
            width = widthSize / 2;
        }
        if (heightMode == MeasureSpec.EXACTLY) {
            height = heightSize;
        } else {
            height = heightSize / 2;
        }
        setMeasuredDimension(width, height);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        canvas.drawPath(path,paint);

        invalidate();

    }
}
