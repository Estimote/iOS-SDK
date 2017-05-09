//
//  IERLocateStuffViewController.h
//  iEasyReminder
//
//  Created by Ding, Orlando on 6/19/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CLLocation;

@interface IERLocateStuffViewController : UIViewController<UIScrollViewDelegate>

@property (nonatomic, readwrite) BOOL isInCurrentCity;
@property (nonatomic, strong) NSString* strHostedCity;
@property (nonatomic, strong) NSString* strStuffKey;
@property (nonatomic, strong) CLLocation* clocation;

@end
