//
//  IERLocateStuffViewController.h
//  iEasyReminder
//
//  Created by Ding, Orlando on 6/19/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IERLocateStuffViewController : UIViewController

@property (nonatomic, readwrite) BOOL isInCurrentCity;
@property (nonatomic, strong) NSString* strHostedCity;
@property (nonatomic, strong) NSString* strStuffKey;

//see : UIScrollView Control and page control
@property (nonatomic, strong) IBOutlet UIScrollView* scrollView;
@property (nonatomic, strong) IBOutlet UIPageControl* pageControl;

@end