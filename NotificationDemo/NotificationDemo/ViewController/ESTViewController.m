//
//  ESTViewController.m
//  NotificationDemo
//
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTViewController.h"
#import <ESTBeaconManager.h>

static const CGFloat ESTScreenHeight = 480.0f;

@interface ESTViewController () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeaconManager* beaconManager;
@property (nonatomic, strong) UIImageView*      bgImageView;
@property (nonatomic, assign) BOOL              notificationShown;
@property (nonatomic, strong) UIImageView*      productImage;

@end

@implementation ESTViewController

#pragma mark - View Setup

- (void)setupBackgroundImage
{
    self.productImage = [[UIImageView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    [self setProductImage];
    [self.view addSubview:self.productImage];
}

#pragma mark - Manager setup

- (void)setupBeaconManager
{
    // craete manager instance
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    self.beaconManager.avoidUnknownStateBeacons = YES;
    
    // create sample region with major value defined
    ESTBeaconRegion* region = [[ESTBeaconRegion alloc] initRegionWithMajor:1 minor:1 identifier: @"EstimoteSampleRegion"];
    
#pragma message("Update the ESTBeaconRegion with your major / minor number and enable background app refresh in the Settings on your device for the NotificationDemo to work correctly.")
    
    // start looking for estimote beacons in region
    // when beacon ranged beaconManager:didEnterRegion:
    // and beaconManager:didExitRegion: invoked
    [self.beaconManager startMonitoringForRegion:region];
    
    [self.beaconManager requestStateForRegion:region];
}

#pragma mark - View Life Cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self setupBeaconManager];
    [self setupBackgroundImage];
}

#pragma mark - ESTBeaconManagerDelegate Implementation

- (void)beaconManager:(ESTBeaconManager *)manager didDetermineState:(CLRegionState)state forRegion:(ESTBeaconRegion *)region
{
    if(state == CLRegionStateInside)
    {
        [self setProductImage];
    }
    else
    {
        [self setDiscountImage];
    }
}

- (void)beaconManager:(ESTBeaconManager *)manager didEnterRegion:(ESTBeaconRegion *)region
{
    // iPhone/iPad entered beacon zone
    [self setProductImage];
    
    // present local notification
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    notification.alertBody = @"Enter";
    notification.soundName = UILocalNotificationDefaultSoundName;
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

- (void)beaconManager:(ESTBeaconManager *)manager didExitRegion:(ESTBeaconRegion *)region
{
    // iPhone/iPad left beacon zone
    [self setDiscountImage];
    
    // present local notification
    UILocalNotification *notification = [[UILocalNotification alloc] init];
    notification.alertBody = @"The shoes you'd tried on are now 20%% off for you with this coupon";
    notification.soundName = UILocalNotificationDefaultSoundName;
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

#pragma mark - UI Update

- (void)setProductImage
{
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenHeight = screenRect.size.height;
    
    if (screenHeight > ESTScreenHeight)
    {
        [self.productImage setImage:[UIImage imageNamed:@"beforeNotificationBig"]];
    }
    else
    {
        [self.productImage setImage:[UIImage imageNamed:@"beforeNotificationSmall"]];
    }
}

- (void)setDiscountImage
{
    // product image when user inside beacon zone
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    CGFloat screenHeight = screenRect.size.height;
    
    if (screenHeight > ESTScreenHeight)
    {
        [self.productImage setImage:[UIImage imageNamed:@"afterNotificationBig"]];
    }
    else
    {
        [self.productImage setImage:[UIImage imageNamed:@"afterNotificationSmall"]];
    }
}


@end
