//
//  ESTViewController.m
//  Examples
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTViewController.h"
#import "ESTBeaconTableVC.h"
#import "ESTCloudBeaconTableVC.h"
#import "ESTDistanceDemoVC.h"
#import "ESTProximityDemoVC.h"
#import "ESTNotificationDemoVC.h"
#import "ESTTemperatureDemoVC.h"
#import "ESTAccelerometerDemoVC.h"
#import "ESTUpdateFirmwareDemoVC.h"
#import "ESTCloudAuthVC.h"

@interface ESTDemoTableViewCell : UITableViewCell

@end

@implementation ESTDemoTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self)
    {
        
    }
    
    return self;
}

@end

@interface ESTViewController()
@property (nonatomic, retain) CLLocationManager *locationManager;
@end

@implementation ESTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    self.title = @"Estimote Demos";
    
    self.tableView.sectionHeaderHeight = 20;
    [self.tableView registerClass:[ESTDemoTableViewCell class] forCellReuseIdentifier:@"DemoCellIdentifier"];
    
    UIBarButtonItem *authButton = [[UIBarButtonItem alloc] initWithTitle:@"Authorize"
                                                                   style:UIBarButtonItemStylePlain
                                                                  target:self
                                                                  action:@selector(authorizeBtnTapped:)];
    self.navigationItem.rightBarButtonItem = authButton;
    
    self.beaconDemoList = @[ @[@"Distance Demo", @"Proximity Demo",@"Notification Demo"],
                             @[@"Temperature Demo", @"Accelerometer Demo"],
                             @[@"Update Firmware Demo", @"My beacons in Cloud Demo"]];
    
    self.locationManager = [[CLLocationManager alloc] init];
    [self.locationManager requestAlwaysAuthorization];
}

-(void)authorizeBtnTapped:(UIButton *)button
{
    ESTCloudAuthVC *cloudVC = [ESTCloudAuthVC new];
    [self.navigationController pushViewController:cloudVC animated:YES];
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.beaconDemoList count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [[self.beaconDemoList objectAtIndex:section] count];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    if(section == 0)
        return @"iBeacon demos";
    if(section == 1)
        return @"Sensor demos";
    if(section == 2)
        return @"Utilities demos";
    
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTDemoTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DemoCellIdentifier" forIndexPath:indexPath];
    cell.textLabel.text = [[self.beaconDemoList objectAtIndex:indexPath.section] objectAtIndex:indexPath.row];
    
    return cell;
}

-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 40;
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UIViewController *demoViewController;
    
    if (indexPath.section == 0)
    {
        switch (indexPath.row)
        {
            case 0:
            {
                demoViewController = [[ESTBeaconTableVC alloc] initWithScanType:ESTScanTypeBeacon
                                                                     completion:^(ESTBeacon *beacon) {
                    
                    ESTDistanceDemoVC *distanceDemoVC = [[ESTDistanceDemoVC alloc] initWithBeacon:beacon];
                    [self.navigationController pushViewController:distanceDemoVC animated:YES];
                }];
                
                break;
            }
            case 1:
            {
                demoViewController = [[ESTBeaconTableVC alloc] initWithScanType:ESTScanTypeBeacon
                                                                     completion:^(ESTBeacon *beacon) {
                    
                    ESTProximityDemoVC *proximityDemoVC = [[ESTProximityDemoVC alloc] initWithBeacon:beacon];
                    [self.navigationController pushViewController:proximityDemoVC animated:YES];
                }];
                
                break;
            }
            case 2:
            {
                demoViewController = [[ESTBeaconTableVC alloc] initWithScanType:ESTScanTypeBeacon
                                                                     completion:^(ESTBeacon *beacon) {
                    
                    ESTNotificationDemoVC *notificationDemoVC = [[ESTNotificationDemoVC alloc] initWithBeacon:beacon];
                    [self.navigationController pushViewController:notificationDemoVC animated:YES];
                }];
                
                break;
            }
            default:
                break;
        }
    }
    else if (indexPath.section == 1)
    {
        switch (indexPath.row)
        {
            case 0:
            {
                demoViewController = [[ESTBeaconTableVC alloc] initWithScanType:ESTScanTypeBeacon
                                                                     completion:^(ESTBeacon *beacon) {
                    
                    ESTTemperatureDemoVC *distanceDemoVC = [[ESTTemperatureDemoVC alloc] initWithBeacon:beacon];
                    [self.navigationController pushViewController:distanceDemoVC animated:YES];
                }];
                
                break;
            }
            case 1:
            {
                demoViewController = [[ESTBeaconTableVC alloc] initWithScanType:ESTScanTypeBeacon
                                                                     completion:^(ESTBeacon *beacon) {
                    
                    ESTAccelerometerDemoVC *proximityDemoVC = [[ESTAccelerometerDemoVC alloc] initWithBeacon:beacon];
                    [self.navigationController pushViewController:proximityDemoVC animated:YES];
                }];
                
                break;
            }
            default:
                break;
        }
    }
    else if (indexPath.section == 2)
    {
        switch (indexPath.row)
        {
            case 0:
            {
                demoViewController = [[ESTBeaconTableVC alloc] initWithScanType:ESTScanTypeBluetooth
                                                                     completion:^(ESTBeacon *beacon) {

                    ESTUpdateFirmwareDemoVC *updateFirmwareVC = [[ESTUpdateFirmwareDemoVC alloc] initWithBeacon:beacon];
                    [self.navigationController pushViewController:updateFirmwareVC animated:YES];
                }];
                break;
            }
            case 1:
            {
                demoViewController = [ESTCloudBeaconTableVC new];
                
                break;
            }
            default:
                break;
        }
    }
    
    if (demoViewController)
    {
        [self.navigationController pushViewController:demoViewController animated:YES];
    }
}

@end
