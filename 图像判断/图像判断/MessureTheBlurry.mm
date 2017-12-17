//
//  MessureTheBlurry.m
//  图像模糊度判断Demo
//
//  Created by 于玮 on 15/12/25.
//  Copyright © 2015年 于玮. All rights reserved.
//
#import "opencv2/opencv.hpp"
#import "opencv2/imgproc/types_c.h"
#import "opencv2/imgcodecs/ios.h"
#import "opencv2/highgui.hpp"
#import "MessureTheBlurry.h"
using namespace std;
using namespace cv;
@implementation MessureTheBlurry
+(double)messureTheBlurryOfImageName:(NSString *)imageName{
   
    UIImage *image = [UIImage imageNamed:imageName];
    return [self messureTheBlurryOfUIImage:image];
   
    
}

+(double)messureTheBlurryOfUIImage:(UIImage *)image{
    Mat cvImage;
    if (image==nil) {
        NSLog(@"不存在该图片");
        return 0;
    }
    UIImageToMat(image,cvImage);
    Mat gray;
    cvtColor(cvImage,cvImage, CV_RGB2GRAY);//彩色转灰度
    Laplacian(cvImage,gray,cvImage.depth());//laplace变换
    Mat tmp_m1,tmp_sd1;
    //计算均值和方差
    double m1 = 0, sd1 = 0;
    meanStdDev(gray, tmp_m1, tmp_sd1);
    m1 = tmp_m1.at<double>(0, 0);     //均值
    sd1 = tmp_sd1.at<double>(0, 0);       //标准差
    cout << "均值: " << m1 << " , 方差: " << sd1*sd1 << endl;
    return sd1*sd1;
}


@end
