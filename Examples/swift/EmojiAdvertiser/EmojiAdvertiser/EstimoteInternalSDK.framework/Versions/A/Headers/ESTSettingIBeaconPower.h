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

#define ESTSettingIBeaconPowerErrorDomain @"ESTSettingIBeaconPowerErrorDomain"

/**
 *  Describes iBeacon Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingIBeaconPowerError)
{
    /**
     *  Provided value does not belong to the ESTIBeaconPower enum.
     */
    ESTSettingIBeaconPowerErrorValueNotAllowed = 1
};

@class ESTSettingIBeaconPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for iBeacon packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconPowerCompletionBlock)(ESTSettingIBeaconPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for iBeacon packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTIBeaconPower)
{
    ESTIBeaconPowerLevel1 = -30,
    ESTIBeaconPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTIBeaconPowerLevel2 = -20,
    ESTIBeaconPowerLevel3 = -16,
    ESTIBeaconPowerLevel4 = -12,
    ESTIBeaconPowerLevel5 = -8,
    ESTIBeaconPowerLevel6 = -4,
    ESTIBeaconPowerLevel7 = 0,
    ESTIBeaconPowerLevel8 = 4,
    ESTIBeaconPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};


/**
 *  ESTSettingIBeaconPower represents iBeacon Power value.
 */
@interface ESTSettingIBeaconPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingIBeaconPower validationErrorForValue:]
 *
 *  @param power iBeacon Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(ESTIBeaconPower)power;

/**
 *  Returns current value of iBeacon Power setting.
 *
 *  @return iBeacon Power value.
 */
- (ESTIBeaconPower)getValue;

/**
 *  Method allows to read value of initialized iBeacon Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTIBeaconPower)power completion:(ESTSettingIBeaconPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTIBeaconPower)power;

@end

NS_ASSUME_NONNULL_END
