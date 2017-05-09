//
//  MapViewController.m
//  iEasyReminder
//
//  Created by Ding, Orlando on 6/23/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import "MapViewController.h"
#import <MapKit/MapKit.h>

@interface MapViewController ()

@property(nonatomic, strong) MKMapView* mapview;
@property(nonatomic, strong) CLLocation* clocation;

@end

@implementation MapViewController


-(id) initWithClocation: (CLLocation*)clocation{
    self = [super init];
    if (self) {
        self.clocation = clocation;
    }
    return self;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.mapview = [MKMapView new];
    self.mapview.frame = self.view.frame;
    self.mapview.showsUserLocation = YES;
    self.mapview.tintColor = [UIColor colorWithRed:0.358 green:0.544 blue:0.980 alpha:1.000];
    [self.mapview setCenterCoordinate:CLLocationCoordinate2DMake(self.clocation.coordinate.latitude, self.clocation.coordinate.longitude) animated:YES];
    [self.view addSubview:self.mapview];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
