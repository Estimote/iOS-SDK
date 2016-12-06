//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTIMOTE_PROXIMITY_UUID             [[NSUUID alloc] initWithUUIDString:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D"]
#define ESTIMOTE_MACBEACON_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"08D4A950-80F0-4D42-A14B-D53E063516E6"]
#define ESTIMOTE_IOSBEACON_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"8492E75F-4FD6-469D-B132-043FE94921D8"]

#define SAVED_UUIDS_KEY @"SAVED_UUIDS_KEY"

////////////////////////////////////////////////////////////////////
// Type and class definitions

typedef NS_ENUM(char, ESTBeaconPower)
{
    ESTBeaconPowerLevel1 = -30,
    ESTBeaconPowerLevel2 = -20,
    ESTBeaconPowerLevel3 = -16,
    ESTBeaconPowerLevel4 = -12,
    ESTBeaconPowerLevel5 = -8,
    ESTBeaconPowerLevel6 = -4,
    ESTBeaconPowerLevel7 = 0,
    ESTBeaconPowerLevel8 = 4
};

typedef NS_ENUM(int, ESTBeaconBatteryType)
{
    ESTBeaconBatteryTypeUnknown = 0,
    ESTBeaconBatteryTypeCR2450,
    ESTBeaconBatteryTypeCR2477
};


typedef NS_ENUM(NSInteger, ESTBeaconFirmwareState)
{
    ESTBeaconFirmwareStateBoot,
    ESTBeaconFirmwareStateApp
};

typedef NS_ENUM(NSInteger, ESTBeaconPowerSavingMode)
{
    ESTBeaconPowerSavingModeUnknown,
    ESTBeaconPowerSavingModeUnsupported,
    ESTBeaconPowerSavingModeOn,
    ESTBeaconPowerSavingModeOff
};

typedef NS_ENUM(NSInteger, ESTBeaconEstimoteSecureUUID)
{
    ESTBeaconEstimoteSecureUUIDUnknown,
    ESTBeaconEstimoteSecureUUIDUnsupported,
    ESTBeaconEstimoteSecureUUIDOn,
    ESTBeaconEstimoteSecureUUIDOff
};

typedef NS_ENUM(NSInteger, ESTBeaconMotionUUID)
{
    ESTBeaconMotionUUIDUnknown,
    ESTBeaconMotionUUIDUnsupported,
    ESTBeaconMotionUUIDOn,
    ESTBeaconMotionUUIDOff
};
typedef NS_ENUM(NSInteger, ESTBeaconMotionState)
{
    ESTBeaconMotionStateUnknown,
    ESTBeaconMotionStateUnsupported,
    ESTBeaconMotionStateMoving,
    ESTBeaconMotionStateNotMoving
};

typedef NS_ENUM(NSInteger, ESTBeaconTemperatureState)
{
    ESTBeaconTemperatureUnknown,
    ESTBeaconTemperatureUnsupported,
    ESTBeaconTemperatureSupported
};

typedef NS_ENUM(NSInteger, ESTBeaconMotionDetection)
{
    ESTBeaconMotionDetectionUnknown,
    ESTBeaconMotionDetectionUnsupported,
    ESTBeaconMotionDetectionOn,
    ESTBeaconMotionDetectionOff
};

typedef NS_ENUM(NSInteger, ESTBeaconConditionalBroadcasting)
{
    ESTBeaconConditionalBroadcastingUnknown,
    ESTBeaconConditionalBroadcastingUnsupported,
    ESTBeaconConditionalBroadcastingOff,
    ESTBeaconConditionalBroadcastingMotionOnly,
    ESTBeaconConditionalBroadcastingFlipToStop,
};

typedef NS_ENUM(NSInteger, ESTBeaconCharInfoType)
{
    ESTBeaconCharInfoTypeWriteRead,
    ESTBeaconCharInfoTypeWriteOnly
};

typedef void(^ESTPowerCompletionBlock)(ESTBeaconPower value, NSError * _Nullable error);

@interface ESTBeaconDefinitions : NSObject

@end

NS_ASSUME_NONNULL_END
