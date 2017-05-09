//
//  ColorButton.h
//  iEasyReminder
//
//  Created by Ding Orlando on 4/7/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//
//  see reference in http://code4app.com/ios/渐变色按钮/52d5e3d8cb7e84bd628b6a5c
//

#import <UIKit/UIKit.h>

typedef enum  {
    topToBottom = 0,
    leftToRight = 1,
    upleftTolowRight = 2,
    uprightTolowLeft = 3,
}GradientType;

@interface ColorButton : UIButton


- (id)initWithFrame:(CGRect)frame FromColorArray:(NSMutableArray*)colorArray ByGradientType:(GradientType)gradientType;

@end
