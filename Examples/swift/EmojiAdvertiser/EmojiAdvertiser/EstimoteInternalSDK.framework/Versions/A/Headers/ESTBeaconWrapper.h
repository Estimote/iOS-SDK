//
//  ESTBeaconWrapper.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 22/04/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconConnection.h"
#import "ESTBluetoothBeacon.h"


@interface ESTBeaconWrapper : NSObject

@property (nonatomic, strong) ESTBeaconConnection *connection;
@property (nonatomic, strong) CLBeacon *beacon;
@property (nonatomic, strong) ESTBluetoothBeacon *btDevice;

@end
