//
//  OpencvSupport.h
//  图像判断
//
//  Created by yuwei on 2017/12/17.
//  Copyright © 2017年 于玮. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
@interface OpencvSupport : NSObject
/*
 * 获取直方图
 */
+(UIImage*) getHisto:(UIImage*)image;

+(UIImage*)getEqualize:(UIImage*)image;
@end
