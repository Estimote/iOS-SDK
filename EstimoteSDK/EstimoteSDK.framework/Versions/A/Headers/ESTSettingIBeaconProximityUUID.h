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
#import "ESTSettingReadWrite.h"

#define ESTSettingIBeaconProximityUUIDErrorDomain @"ESTSettingIBeaconIntervalErrorDomain"

/**
 *  Describes iBeacon Advertising Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingIBeaconProximityUUIDError)
{
    /**
     *  Provided value is either missing or is an invalid NSUUID.
     */
    ESTSettingIBeaconProximityUUIDErrorInvalidValue = 1
};

@class ESTSettingIBeaconProximityUUID;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting ProximityUUID operation for iBeacon packet.
 *
 *  @param proximityUUIDSetting ProximityUUID setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconProximityUUIDCompletionBlock)(ESTSettingIBeaconProximityUUID * _Nullable proximityUUIDSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconProximityUUID represents iBeacon ProximityUUID value.
 */
@interface ESTSettingIBeaconProximityUUID : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param proximityUUID iBeacon ProximityUUID value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSUUID *)proximityUUID;

/**
 *  Returns current value of iBeacon ProximityUUID setting.
 *
 *  @return iBeacon ProximityUUID value.
 */
- (NSUUID *)getValue;

/**
 *  Method allows to read value of initialized iBeacon ProximityUUID setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconProximityUUIDCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon ProximityUUID setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param proximityUUID ProximityUUID value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSUUID *)proximityUUID completion:(ESTSettingIBeaconProximityUUIDCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
