//
//  ESTBeaconDefinitions.h
//  EstimoteSDK
//
//  Version : 1.2.0
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconUpdateInfo.h"

////////////////////////////////////////////////////////////////////
// Type and class definitions


typedef enum : char
{
    ESTBeaconPowerLevel1 = -30,
    ESTBeaconPowerLevel2 = -20,
    ESTBeaconPowerLevel3 = -16,
    ESTBeaconPowerLevel4 = -12,
    ESTBeaconPowerLevel5 = -8,
    ESTBeaconPowerLevel6 = -4,
    ESTBeaconPowerLevel7 = 0,
    ESTBeaconPowerLevel8 = 4
} ESTBeaconPower;

typedef enum : int
{
    ESTBeaconFirmwareStateBoot,
    ESTBeaconFirmwareStateApp
} ESTBeaconFirmwareState;

typedef enum : int
{
    ESTBeaconFirmwareUpdateNone,
    ESTBeaconFirmwareUpdateAvailable,
    ESTBeaconFirmwareUpdateNotAvailable
} ESTBeaconFirmwareUpdate;

typedef void(^ESTCompletionBlock)(NSError* error);
typedef void(^ESTFirmwareUpdateCompletionBlock)(BOOL updateAvailable, ESTBeaconUpdateInfo* updateInfo, NSError* error);
typedef void(^ESTUnsignedShortCompletionBlock)(unsigned short value, NSError* error);
typedef void(^ESTPowerCompletionBlock)(ESTBeaconPower value, NSError* error);
typedef void(^ESTBoolCompletionBlock)(BOOL value, NSError* error);
typedef void(^ESTStringCompletionBlock)(NSString* value, NSError* error);




////////////////////////////////////////////////////////////////////
// Interface definition

@interface ESTBeaconDefinitions : NSObject

@end
