//
//  OpencvSupport.m
//  图像判断
//
//  Created by yuwei on 2017/12/17.
//  Copyright © 2017年 于玮. All rights reserved.
//

#import "OpencvSupport.h"
#import "opencv2/imgcodecs/ios.h"
#include "OpencvSupport.hpp"
@implementation OpencvSupport
+(UIImage *)getHisto:(UIImage *)image{
    Mat cvImage;
    UIImageToMat(image,cvImage);
    Mat result = getHisto(cvImage);
    return MatToUIImage(result);
   
}

+(UIImage *)getEqualize:(UIImage *)image{
    Mat cvImage;
    UIImageToMat(image,cvImage);
    Mat result = equalizeImage(cvImage);
    return MatToUIImage(result);
}
@end
