//
//  OpencvSupport.hpp
//  图像判断
//
//  Created by yuwei on 2017/12/17.
//  Copyright © 2017年 于玮. All rights reserved.
//

#ifndef OpencvSupport_hpp
#define OpencvSupport_hpp
//#import "opencv2/imgproc/types_c.h"
//#import "opencv2/imgcodecs/ios.h"
//#import "opencv2/highgui.hpp"
#import "opencv2/opencv.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;
using namespace cv;
Mat getHisto(Mat cvImage);
Mat equalizeImage(Mat cvImage);
#endif /* OpencvSupport_hpp */
