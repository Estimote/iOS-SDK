//
//  MapViewController.h
//  iEasyReminder
//
//  Created by Ding, Orlando on 6/23/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import <UIKit/UIKit.h>
@class CLLocation;

@interface MapViewController : UIViewController

-(id) initWithClocation: (CLLocation*)clocation;

@end
