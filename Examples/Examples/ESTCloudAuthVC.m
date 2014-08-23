//
//  ESTCloudAuthVC.m
//  DistanceDemo
//
//  Created by Grzegorz Krukiewicz-Gacek on 17.03.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import "ESTCloudAuthVC.h"
#import "ESTBeaconManager.h"
#import "ESTBeaconVO.h"
#import "ESTViewController.h"

@interface ESTCloudAuthVC () <UITextFieldDelegate>

@property (nonatomic, strong) IBOutlet UITextField *appIdField;
@property (nonatomic, strong) IBOutlet UITextField *appTokenField;
@property (nonatomic, strong) IBOutlet UIButton *loadBeaconsBtn;

@end

@implementation ESTCloudAuthVC

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = @"Estimote Authorization";
    
    self.appIdField.delegate    = self;
    self.appTokenField.delegate = self;
}

-(void)viewWillDisappear:(BOOL)animated
{
    [self.appTokenField resignFirstResponder];
    [self.appIdField resignFirstResponder];
    
    [ESTBeaconManager setupAppID:self.appIdField.text andAppToken:self.appTokenField.text];
}

- (IBAction)dismiss
{
    [self.navigationController popToRootViewControllerAnimated:YES];
}

#pragma mark - TextField delegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return NO;
}

@end
