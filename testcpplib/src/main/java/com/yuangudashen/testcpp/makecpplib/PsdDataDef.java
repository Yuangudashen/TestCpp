package com.yuangudashen.testcpp.makecpplib;

import java.io.Serializable;

/**
 * Created by Administrator on 2017/11/20/020.
 */

public class PsdDataDef implements Serializable {

    public double[] psdYValue = new double[257];    //PSD的Y轴坐标

    public double[] psdXValue = new double[257];    //PSD的X轴坐标

    public double TP = 0;                //TP
    public double VLF = 0;               //VLF
    public double LF = 0;                //LF
    public double HF = 0;                //HF
    public double nLF = 0;               //LF norm
    public double nHF = 0;               //HF norm
    public double LF_HF = 0;             //LF_HF

}