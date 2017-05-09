//
//  SecondViewController.m
//  iEasyReminder
//
//  Created by Ding Orlando on 4/7/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import "DiscoverViewController.h"
#import "ESTBeaconManager.h"
#include <libkern/OSAtomic.h>

@interface ESTBeacon (isEqualToArray)

- (BOOL)isEqual:(id)anObject;

@end

@implementation ESTBeacon (isEqualToArray)

// TODO : logic is incorrect, as ESTBeacon equality should be equal with array
- (BOOL)isEqual:(id)anObject{
    if ([anObject isKindOfClass:[ESTBeacon class]]) {
        ESTBeacon* obj = (ESTBeacon*)anObject;
        return [self isEqualToBeacon:obj];
    }
    return NO;
}

@end

@interface NSArray (isEqualToBeaconArray)

- (BOOL)isEqualToBeaconArray:(id)anObject;

@end

@implementation NSArray (isEqualToBeaconArray)

// TODO : logic is incorrect, as ESTBeacon equality should be equal with array
- (BOOL)isEqualToBeaconArray:(id)anObject{
    if ([anObject isKindOfClass:[NSArray class]]) {
        NSArray* obj = (NSArray*)anObject;
        if ([self count] != [obj count]) {
            return NO;
        }
        else{
            if ([self count] == 0) {
                return YES;
            }
            // TODO : [self count] > 0
            for (int i= 0; i < [self count]; i++) {
                if([self[i] isKindOfClass:[ESTBeacon class]] && [obj[i] isKindOfClass:[ESTBeacon class]]){
                    ESTBeacon *obj1 = (ESTBeacon*)self[i], *obj2 = (ESTBeacon*)obj[i];
                    if (obj1 != obj2) {
                        if ([obj1.major longValue] != [obj2.major longValue]) {
                            return NO;
                        }
                        if ([obj1.minor longValue] != [obj2.minor longValue]) {
                            return NO;
                        }
                        if ([obj1.distance floatValue] != [obj2.distance floatValue]) {
                            return NO;
                        }
                    }
                }
                else{
                    return NO;
                }
            }
            return YES;
        }
    }
    return NO;
}

@end


@interface DiscoverViewTableCell : UITableViewCell

@end

@implementation DiscoverViewTableCell

// TODO : instancetype see http://clang.llvm.org/docs/LanguageExtensions.html#objective-c-features and http://blog.csdn.net/wzzvictory/article/details/16994913
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    self = [super initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:reuseIdentifier];
    if (self) {
        
    }
    return self;
}

@end

@interface DiscoverViewController () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeaconManager *beaconManager;
@property (nonatomic, strong) ESTBeaconRegion *region;
@property (strong, nonatomic) NSArray *sortedBeaconsArray;

- (void) performRefresh: (id)paramSender;
- (NSArray*) convertToSortedBeacons:(NSArray*)curbeaconsArray
                       orginBeacons:(NSArray*)originBeaconsArray
                          isChanged:(bool*)changed;

@end

@implementation DiscoverViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // TODO : initialize for table
//    self.tableView.sectionHeaderHeight = 22;
    [self.tableView registerClass:[DiscoverViewTableCell class] forCellReuseIdentifier:@"DiscoverViewTableCellIdentifier"];
    
    // TODO : for navigationbar and rightButtonItem event, http://iphonedevsdk.com/forum/iphone-sdk-development/16536-uinavigationitem-title-rightbarbuttonitem-color-color-change.html and also http://blog.csdn.net/justinjing0612/article/details/6965919, http://blog.ericd.net/2013/03/26/pull-to-refresh-uitableview/
    self.refreshControl = [[UIRefreshControl alloc]init];
    [self.refreshControl addTarget:self action:@selector(performRefresh:) forControlEvents:UIControlEventValueChanged];
//    self.refreshControl.attributedTitle = [[NSAttributedString alloc] initWithString:@"Pull to refresh"];
//    [self.tableView setContentOffset:CGPointMake(0, -52) animated:NO];
    [self updateDiscoverTableView:true];
//    [self.navigationController.navigationBar setTintColor:[UIColor whiteColor]];
//    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh
//                                                                                          target:self
//                                                                                          action:@selector(performRefresh:)];
}

- (void)updateDiscoverTableView: (bool)manual {
    if (manual) {
        // TODO : Should be replaced with refreshed rotation
        // http://stackoverflow.com/questions/2965737/replace-uibarbuttonitem-with-uiactivityindicatorview
//        UIActivityIndicatorView *activityIndicator = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, self.navigationItem.rightBarButtonItem.width, self.navigationItem.rightBarButtonItem.width)];
//        UIBarButtonItem *activityItem = [[UIBarButtonItem alloc] initWithCustomView:activityIndicator];
//        self.navigationItem.rightBarButtonItem = activityItem;
//        [activityIndicator startAnimating];
//        [self.tableView setContentOffset:CGPointMake(0, -44) animated:YES];
//        [self.tableView setContentOffset:CGPointMake(0, -44) animated:NO];
        [self.refreshControl beginRefreshing];
        self.refreshControl.attributedTitle = [[NSAttributedString alloc] initWithString:@"Updating..."];
        double delayInSeconds = 2.0;
        dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
        dispatch_after(popTime, dispatch_get_main_queue(), ^{
//                [activityIndicator stopAnimating];
            [self.tableView reloadData];
//            [self.tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:YES];
//            [self.tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:NO];
            if (self->isManualRefreshTriggered) {
                OSAtomicCompareAndSwapInt(1, 0, &self->isManualRefreshTriggered);
            }
            [self.refreshControl endRefreshing];
            self.refreshControl.attributedTitle = [[NSAttributedString alloc] initWithString:@"Pull to refresh"];
//            [self.tableView setContentOffset:CGPointMake(0, 0) animated:NO];
//                [self.navigationController.navigationBar setTintColor:[UIColor whiteColor]];
//                self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh
//                                                                                                      target:self
//                                                                                                      action:@selector(performRefresh:)];
        });
//        });
    }
    else{
        [self.tableView reloadData];
//        [self.tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:YES];
//        [self.tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:NO];
    }
}

- (void) performRefresh: (id)paramSender{
    OSAtomicCompareAndSwapInt(0, 1, &self->isManualRefreshTriggered);
    [self updateDiscoverTableView:true];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
    [self.beaconManager startRangingBeaconsInRegion:self.region];
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

// TODO : converted into sorted beaconsArray to see if items is changed or not
// refer to return multi-value http://stackoverflow.com/questions/1692005/returning-multiple-values-from-a-method-in-objective-c
- (NSArray*) convertToSortedBeacons:(NSArray*)curbeaconsArray
                       orginBeacons:(NSArray*)originBeaconsArray
                          isChanged:(bool*)changed{
    return nil;
}

#pragma mark - ESTBeaconManager delegate

- (void)beaconManager:(ESTBeaconManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(ESTBeaconRegion *)region
{
    if (self->isManualRefreshTriggered)
        return;
    NSArray* sortedArray = [beacons sortedArrayUsingComparator:^NSComparisonResult(ESTBeacon* beacon1, ESTBeacon* beacon2) {
        if ([beacon1.major longValue] == [beacon2.major longValue]) {
            if([beacon1.minor longValue] < [beacon2.minor longValue]){
                return (NSComparisonResult)NSOrderedDescending;
            }
        }
        else if([beacon1.major longValue] < [beacon2.major longValue]){
            return (NSComparisonResult)NSOrderedDescending;
        }
        return (NSComparisonResult)NSOrderedAscending;
    }];
    // TODO : as iBeacons implementation, API reuse ESBeacon item, the pointer is the same, so compasion keeps true
//    if (![sortedArray isEqualToBeaconArray:self.sortedBeaconsArray]) {
    self.sortedBeaconsArray = sortedArray;
    [self updateDiscoverTableView:false];
//    }
}

- (void)beaconManager:(ESTBeaconManager *)manager didDiscoverBeacons:(NSArray *)beacons inRegion:(ESTBeaconRegion *)region
{
    if (self->isManualRefreshTriggered)
        return;
    NSArray* sortedArray = [beacons sortedArrayUsingComparator:^NSComparisonResult(ESTBeacon *beacon1, ESTBeacon *beacon2) {
        if ([beacon1.major longValue] == [beacon2.major longValue]) {
            if([beacon1.minor longValue] < [beacon2.minor longValue]){
                return (NSComparisonResult)NSOrderedDescending;
            }
        }
        else if([beacon1.major longValue] < [beacon2.major longValue]){
            return (NSComparisonResult)NSOrderedDescending;
        }
        return (NSComparisonResult)NSOrderedAscending;
    }];
//    if (![sortedArray isEqualToBeaconArray:self.sortedBeaconsArray]) {
    self.sortedBeaconsArray = sortedArray;
    [self updateDiscoverTableView:false];
//    }
}

#pragma mark - Table view section source

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    if(section == 0){
        return @"available iBeacon stations";
    }
    
    return nil;
}

-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 40;
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSInteger iBeaconsCount = 0;
    if (self.sortedBeaconsArray != nil) {
        iBeaconsCount = [self.sortedBeaconsArray count];
    }
    return iBeaconsCount;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    DiscoverViewTableCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DiscoverViewTableCellIdentifier" forIndexPath:indexPath];
    
    /*
     * Fill the table with beacon data.
     */
    ESTBeacon *beacon = [self.sortedBeaconsArray objectAtIndex:indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"Major: %@, Minor: %@", beacon.major, beacon.minor];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Distance: %.2f", [beacon.distance floatValue]];
    cell.imageView.image = [UIImage imageNamed:@"beacon"];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
	return 60;
}

#pragma mark - Table view delegate

//- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
//{
//    ESTBeacon *selectedBeacon = [self.sortedBeaconsArray objectAtIndex:indexPath.row];
//    
//    self.completion(selectedBeacon);
//}

#pragma mark - UIInterfaceOrientationMaskLandscape

-(NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortraitUpsideDown;
}

-(BOOL)shouldAutorotate
{
    return NO;
}

@end
