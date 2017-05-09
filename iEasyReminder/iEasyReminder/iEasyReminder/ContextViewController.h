//
//  FirstViewController.h
//  iEasyReminder
//
//  Created by Ding Orlando on 4/7/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <QuartzCore/QuartzCore.h>

@interface ContextViewController : UITableViewController<CLLocationManagerDelegate>{
    CLLocationManager* _cllocationManager;
    CLGeocoder *_geocoder;
    __weak CLPlacemark* _clplacemark;
}

@end
