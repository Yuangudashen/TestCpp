package com.yuangudashen.testcpp.makecpplib;

/**
 * Created by Administrator on 2017/11/6/006.
 */

public class NativeUtils {

    static {
        System.loadLibrary("algorithm");
    }

    public static final String DB4 = "db4";
    public static final String DB6 = "db6";

    public static native boolean SetWaveltType(String wname);

    public static native boolean SetThresholdFrequency(double frequency);

    public static native int GetPSDValue(double[] data, int dataSize, PsdDataDef psdDataDef);


    public static int dataSize = 311;

    public static double[] data = new double[]{
            0.300
            , 0.628
            , 0.644
            , 0.656
            , 0.638
            , 0.628
            , 0.63
            , 0.63
            , 0.634
            , 0.644
            , 0.67
            , 0.644
            , 0.664
            , 0.64
            , 0.672
            , 0.662
            , 0.658
            , 0.654
            , 0.648
            , 0.668
            , 0.672
            , 0.688
            , 0.698
            , 0.696
            , 0.684
            , 0.682
            , 0.684
            , 0.662
            , 0.662
            , 0.658
            , 0.664
            , 0.648
            , 0.654
            , 0.666
            , 0.676
            , 0.696
            , 0.678
            , 0.692
            , 0.702
            , 0.698
            , 0.682
            , 0.692
            , 0.684
            , 0.684
            , 0.632
            , 0.662
            , 0.664
            , 0.666
            , 0.674
            , 0.684
            , 0.688
            , 0.692
            , 0.682
            , 0.654
            , 0.658
            , 0.684
            , 0.682
            , 0.688
            , 0.682
            , 0.684
            , 0.708
            , 0.688
            , 0.692
            , 0.658
            , 0.682
            , 0.678
            , 0.678
            , 0.684
            , 0.652
            , 0.68
            , 0.658
            , 0.666
            , 0.66
            , 0.684
            , 0.68
            , 0.7
            , 0.684
            , 0.692
            , 0.688
            , 0.686
            , 0.686
            , 0.676
            , 0.672
            , 0.68
            , 0.66
            , 0.678
            , 0.67
            , 0.67
            , 0.684
            , 0.702
            , 0.72
            , 0.75
            , 0.724
            , 0.728
            , 0.742
            , 0.75
            , 0.75
            , 0.734
            , 0.738
            , 0.754
            , 0.728
            , 0.738
            , 0.706
            , 0.72
            , 0.722
            , 0.708
            , 0.69
            , 0.69
            , 0.678
            , 0.692
            , 0.676
            , 0.686
            , 0.682
            , 0.704
            , 0.726
            , 0.602
            , 0.712
            , 0.664
            , 0.64
            , 0.67
            , 0.668
            , 0.69
            , 0.668
            , 0.668
            , 0.692
            , 0.694
            , 0.69
            , 0.7
            , 0.716
            , 0.73
            , 0.714
            , 0.702
            , 0.706
            , 0.718
            , 0.708
            , 0.698
            , 0.704
            , 0.686
            , 0.68
            , 0.686
            , 0.662
            , 0.684
            , 0.68
            , 0.688
            , 0.67
            , 0.694
            , 0.69
            , 0.694
            , 0.694
            , 0.674
            , 0.698
            , 0.682
            , 0.694
            , 0.682
            , 0.692
            , 0.706
            , 0.71
            , 0.708
            , 0.678
            , 0.684
            , 0.68
            , 0.674
            , 0.682
            , 0.676
            , 0.668
            , 0.612
            , 0.604
            , 0.648
            , 0.608
            , 0.61
            , 0.614
            , 0.636
            , 0.648
            , 0.66
            , 0.672
            , 0.686
            , 0.656
            , 0.676
            , 0.692
            , 0.69
            , 0.688
            , 0.68
            , 0.688
            , 0.654
            , 0.678
            , 0.682
            , 0.69
            , 0.69
            , 0.666
            , 0.68
            , 0.684
            , 0.694
            , 0.702
            , 0.688
            , 0.694
            , 0.706
            , 0.71
            , 0.706
            , 0.682
            , 0.688
            , 0.692
            , 0.702
            , 0.678
            , 0.692
            , 0.702
            , 0.714
            , 0.718
            , 0.686
            , 0.724
            , 0.716
            , 0.71
            , 0.68
            , 0.708
            , 0.706
            , 0.712
            , 0.698
            , 0.728
            , 0.73
            , 0.736
            , 0.718
            , 0.732
            , 0.724
            , 0.726
            , 0.696
            , 0.726
            , 0.726
            , 0.724
            , 0.702
            , 0.692
            , 0.724
            , 0.706
            , 0.69
            , 0.722
            , 0.728
            , 0.732
            , 0.676
            , 0.724
            , 0.702
            , 0.686
            , 0.69
            , 0.696
            , 0.694
            , 0.698
            , 0.714
            , 0.724
            , 0.728
            , 0.712
            , 0.716
            , 0.724
            , 0.738
            , 0.724
            , 0.704
            , 0.726
            , 0.72
            , 0.718
            , 0.718
            , 0.696
            , 0.724
            , 0.72
            , 0.722
            , 0.698
            , 0.72
            , 0.716
            , 0.726
            , 0.698
            , 0.714
            , 0.72
            , 0.726
            , 0.702
            , 0.73
            , 0.724
            , 0.74
            , 0.704
            , 0.748
            , 0.752
            , 0.762
            , 0.726
            , 0.748
            , 0.752
            , 0.75
            , 0.722
            , 0.756
            , 0.756
            , 0.752
            , 0.712
            , 0.732
            , 0.722
            , 0.75
            , 0.714
            , 0.756
            , 0.76
            , 0.768
            , 0.728
            , 0.738
            , 0.746
            , 0.754
            , 0.74
            , 0.762
            , 0.762
            , 0.772
            , 0.736
            , 0.762
            , 0.744
            , 0.744
            , 0.722
            , 0.704
            , 0.718
            , 0.676
            , 0.714
            , 0.726
            , 0.74
    };

}