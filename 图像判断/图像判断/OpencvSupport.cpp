//
//  OpencvSupport.cpp
//  图像判断
//
//  Created by yuwei on 2017/12/17.
//  Copyright © 2017年 于玮. All rights reserved.
//

#include "OpencvSupport.hpp"
Mat getHisto(Mat cvImage){
    //把图像分割成3个通道brg
    vector<Mat>bgr;
    split(cvImage, bgr);
    
    //创建256个子区间的直方图
    //值得可能数量为[0,255]
    int numbins = 256;
    //设置范围 bgr ,最后一个值不包含
    float range[] = {0,256};
    const float *histRange = {range};
    Mat b_hist,g_hist,r_hist;
    calcHist(&bgr[0], 1, 0, Mat(), b_hist, 1, &numbins, &histRange);
    calcHist(&bgr[1], 1, 0, Mat(), g_hist, 1, &numbins, &histRange);
    calcHist(&bgr[2], 1, 0, Mat(), r_hist, 1, &numbins, &histRange);
    //绘制直方图
    //将每个图像通道绘线
    int width = 512;
    int height = 300;
    //以灰色为基底创建图像
    Mat histImage(height,width,CV_8UC3,Scalar(20,20,20));
    
    //从0到图像高度归一化直方图
    normalize(b_hist,b_hist,0,height,NORM_MINMAX);
    normalize(g_hist,g_hist,0,height,NORM_MINMAX);
    normalize(r_hist,r_hist,0,height,NORM_MINMAX);
    
    int binStep = cvRound((float)width/(float)numbins);
    for (int i = 1; i<numbins; i++) {
        line(histImage,
             Point(binStep*(i-1),height-cvRound(b_hist.at<float>(i-1))),
             Point(binStep*(i),height-cvRound(b_hist.at<float>(i))),
             Scalar(255,0,0));
        
        line(histImage,
             Point(binStep*(i-1),height-cvRound(g_hist.at<float>(i-1))),
             Point(binStep*(i),height-cvRound(g_hist.at<float>(i))),
             Scalar(0,255,0));
        
        line(histImage,
             Point(binStep*(i-1),height-cvRound(r_hist.at<float>(i-1))),
             Point(binStep*(i),height-cvRound(r_hist.at<float>(i))),
             Scalar(0,0,255));
    }
    return histImage;
    
}


Mat equalizeImage(Mat cvImage){
    if( cvImage.channels() >= 3 )
    {
        Mat ycrcb;
        
        cvtColor(cvImage, ycrcb, COLOR_BGR2YCrCb);
        
        vector<Mat> channels;
        split(ycrcb, channels);
        
        equalizeHist(channels[0], channels[0]);
        
        Mat result;
        merge(channels,ycrcb);
        
        cvtColor(ycrcb, result, COLOR_YCrCb2BGR);
        
        return result;
    }
    
    return Mat();
}
