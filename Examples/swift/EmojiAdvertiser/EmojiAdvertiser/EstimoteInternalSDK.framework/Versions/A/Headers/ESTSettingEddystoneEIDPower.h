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

#define ESTSettingEddystoneEIDPowerErrorDomain @"ESTSettingEddystoneEIDPowerErrorDomain"

/**
 *  Describes EddystoneEID Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneEIDPowerError)
{
    /**
     *  Provided value does not belong to the ESTEddystoneEIDPower enum.
     */
    ESTSettingEddystoneEIDPowerErrorValueNotAllowed = 1
};

@class ESTSettingEddystoneEIDPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for EddystoneEID packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneEIDPowerCompletionBlock)(ESTSettingEddystoneEIDPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for Eddystone UID packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTEddystoneEIDPower)
{
    ESTEddystoneEIDPowerLevel1 = -30,
    ESTEddystoneEIDPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTEddystoneEIDPowerLevel2 = -20,
    ESTEddystoneEIDPowerLevel3 = -16,
    ESTEddystoneEIDPowerLevel4 = -12,
    ESTEddystoneEIDPowerLevel5 = -8,
    ESTEddystoneEIDPowerLevel6 = -4,
    ESTEddystoneEIDPowerLevel7 = 0,
    ESTEddystoneEIDPowerLevel8 = 4,
    ESTEddystoneEIDPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};

/**
 *  ESTSettingEddystoneEIDPower represents EddystoneEID Power value.
 */
@interface ESTSettingEddystoneEIDPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneEIDPower validationErrorForValue:]
 *
 *  @param power EddystoneEID Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTEddystoneEIDPower)power;

/**
 *  Returns current value of EddystoneEID Power setting.
 *
 *  @return EddystoneEID Power value.
 */
- (ESTEddystoneEIDPower)getValue;

/**
 *  Method allows to read value of initialized EddystoneEID Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneEIDPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized EddystoneEID Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTEddystoneEIDPower)power completion:(ESTSettingEddystoneEIDPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTEddystoneEIDPower)power;

@end

NS_ASSUME_NONNULL_END
