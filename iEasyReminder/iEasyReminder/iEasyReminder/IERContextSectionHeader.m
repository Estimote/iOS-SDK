//
//  IERContextSectionHeader.m
//  iEasyReminder
//
//  Created by Ding Orlando on 6/2/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import "IERContextSectionHeader.h"

typedef enum  {
    topToBottom = 0,
    leftToRight = 1,
    upleftTolowRight = 2,
    uprightTolowLeft = 3,
}GradientType;

@implementation IERContextSectionHeader

- (UIImage*) buttonImageFromColors:(NSArray*)colors ByGradientType:(GradientType)gradientType{
    NSMutableArray *ar = [NSMutableArray array];
    for(UIColor *c in colors) {
        [ar addObject:(id)c.CGColor];
    }
    UIGraphicsBeginImageContextWithOptions(self.frame.size, YES, 1);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSaveGState(context);
    CGColorSpaceRef colorSpace = CGColorGetColorSpace([[colors lastObject] CGColor]);
    CGGradientRef gradient = CGGradientCreateWithColors(colorSpace, (CFArrayRef)ar, NULL);
    CGPoint start;
    CGPoint end;
    switch (gradientType) {
        case 0:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(0.0, self.frame.size.height);
            break;
        case 1:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(self.frame.size.width, 0.0);
            break;
        case 2:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(self.frame.size.width, self.frame.size.height);
            break;
        case 3:
            start = CGPointMake(self.frame.size.width, 0.0);
            end = CGPointMake(0.0, self.frame.size.height);
            break;
        default:
            break;
    }
    CGContextDrawLinearGradient(context, gradient, start, end, kCGGradientDrawsBeforeStartLocation | kCGGradientDrawsAfterEndLocation);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    CGGradientRelease(gradient);
    CGContextRestoreGState(context);
    CGColorSpaceRelease(colorSpace);
    UIGraphicsEndImageContext();
    return image;
}

-(void) awakeFromNib {
    self.layer.borderColor = [UIColor colorWithWhite:0.6 alpha:0.6].CGColor;
    self.layer.borderWidth = 0.5f;
    [super awakeFromNib];
    
    [self.mainButton setBackgroundColor:[UIColor lightTextColor]];
    [self.mainButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    self.mainButton.titleLabel.font = [UIFont boldSystemFontOfSize:[UIFont systemFontSize]];
    [self.mainButton setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];
}

-(IBAction)buttonTapped:(id)sender {
    if(self.buttonTappedHandler)
        self.buttonTappedHandler();
}

- (void) updateColorforCurrentLocation{
    NSMutableArray *colorArray = [@[[UIColor lightGrayColor],[UIColor whiteColor]] mutableCopy];
    UIImage *backImage = [self buttonImageFromColors:colorArray ByGradientType:leftToRight];
    [self.mainButton setBackgroundImage:backImage forState:UIControlStateNormal];
    self.mainButton.layer.cornerRadius = 2;
    self.mainButton.layer.masksToBounds = YES;
    [self.mainButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
}

@end
