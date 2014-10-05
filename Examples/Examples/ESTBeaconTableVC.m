//
//  ESTBeaconTableVC.m
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTBeaconTableVC.h"
#import "ESTBeaconManager.h"
#import "ESTViewController.h"

@interface ESTBeaconTableVC () <ESTBeaconManagerDelegate>

@property (nonatomic, copy)     void (^completion)(ESTBeacon *);
@property (nonatomic, assign)   ESTScanType scanType;

@property (nonatomic, strong) ESTBeaconManager *beaconManager;
@property (nonatomic, strong) ESTBeaconRegion *region;
@property (nonatomic, strong) NSArray *beaconsArray;

@end

@interface ESTTableViewCell : UITableViewCell

@end
@implementation ESTTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self)
    {
        
    }
    return self;
}
@end

@implementation ESTBeaconTableVC

- (id)initWithScanType:(ESTScanType)scanType completion:(void (^)(ESTBeacon *))completion
{
    self = [super init];
    if (self)
    {
        self.scanType = scanType;
        self.completion = [completion copy];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Select beacon";
    
    [self.tableView registerClass:[ESTTableViewCell class] forCellReuseIdentifier:@"CellIdentifier"];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    
    /* 
     * Creates sample region object (you can additionaly pass major / minor values).
     *
     * We specify it using only the ESTIMOTE_PROXIMITY_UUID because we want to discover all
     * hardware beacons with Estimote's proximty UUID.
     */
    self.region = [[ESTBeaconRegion alloc] initWithProximityUUID:ESTIMOTE_PROXIMITY_UUID
                                                      identifier:@"EstimoteSampleRegion"];

    /*
     * Starts looking for Estimote beacons.
     * All callbacks will be delivered to beaconManager delegate.
     */
    if (self.scanType == ESTScanTypeBeacon)
    {
        [self startRangingBeacons];
    }
    else
    {
        [self.beaconManager startEstimoteBeaconsDiscoveryForRegion:self.region];
    }
}

- (void)beaconManager:(ESTBeaconManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status
{
    if (self.scanType == ESTScanTypeBeacon)
    {
        [self startRangingBeacons];
    }
}

-(void)startRangingBeacons
{
    if ([ESTBeaconManager authorizationStatus] == kCLAuthorizationStatusNotDetermined)
    {
        /*
         * Request permission to use Location Services. (new in iOS 8)
         * We ask for "always" authorization so that the Notification Demo can benefit as well.
         * Also requires NSLocationAlwaysUsageDescription in Info.plist file.
         *
         * For more details about the new Location Services authorization model refer to:
         * https://community.estimote.com/hc/en-us/articles/203393036-Estimote-SDK-and-iOS-8-Location-Services
         */
        [self.beaconManager requestAlwaysAuthorization];
    }
    else if([ESTBeaconManager authorizationStatus] == kCLAuthorizationStatusAuthorized)
    {
        [self.beaconManager startRangingBeaconsInRegion:self.region];
    }
    else if([ESTBeaconManager authorizationStatus] == kCLAuthorizationStatusDenied)
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Location Access Denied"
                                                        message:@"You have denied access to location services. Change this in app settings."
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles: nil];
        
        [alert show];
    }
    else if([ESTBeaconManager authorizationStatus] == kCLAuthorizationStatusRestricted)
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Location Not Available"
                                                        message:@"You have no access to location services."
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles: nil];
        
        [alert show];
    }
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    /*
     *Stops ranging after exiting the view.
     */
    [self.beaconManager stopRangingBeaconsInRegion:self.region];
    [self.beaconManager stopEstimoteBeaconDiscovery];
}

- (void)dismiss
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - ESTBeaconManager delegate

- (void)beaconManager:(ESTBeaconManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(ESTBeaconRegion *)region
{
    self.beaconsArray = beacons;
    
    [self.tableView reloadData];
}

- (void)beaconManager:(ESTBeaconManager *)manager didDiscoverBeacons:(NSArray *)beacons inRegion:(ESTBeaconRegion *)region
{
    self.beaconsArray = beacons;
    
    [self.tableView reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.beaconsArray count];
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CellIdentifier" forIndexPath:indexPath];
    
    /*
     * Fill the table with beacon data.
     */
    ESTBeacon *beacon = [self.beaconsArray objectAtIndex:indexPath.row];
    
    if (self.scanType == ESTScanTypeBeacon)
    {
        cell.textLabel.text = [NSString stringWithFormat:@"Major: %@, Minor: %@", beacon.major, beacon.minor];
        cell.detailTextLabel.text = [NSString stringWithFormat:@"Distance: %.2f", [beacon.distance floatValue]];
    }
    else
    {
        cell.textLabel.text = [NSString stringWithFormat:@"MacAddress: %@", beacon.macAddress];
        cell.detailTextLabel.text = [NSString stringWithFormat:@"RSSI: %ld", (long)beacon.rssi];
        
        if([beacon.major unsignedShortValue] == 24216 && beacon.macAddress == nil)
        {
            NSLog(@"MAc: %@, %i", beacon.macAddress, [beacon.major unsignedShortValue]);
        }
    }
    cell.imageView.image = [UIImage imageNamed:@"beacon"];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
	return 80;
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    ESTBeacon *selectedBeacon = [self.beaconsArray objectAtIndex:indexPath.row];
    
    self.completion(selectedBeacon);
}

@end
