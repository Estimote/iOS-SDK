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

#define ESTSettingEddystoneUIDPowerErrorDomain @"ESTSettingEddystoneUIDPowerErrorDomain"

/**
 *  Describes Eddystone UID Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneUIDPowerError) {
    /**
     *  Provided value does not belong to the ESTEddystoneUIDPower enum.
     */
    ESTSettingEddystoneUIDPowerErrorValueNotAllowed = 1
};

@class ESTSettingEddystoneUIDPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Eddystone UID packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneUIDPowerCompletionBlock)(ESTSettingEddystoneUIDPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for Eddystone UID packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTEddystoneUIDPower)
{
    ESTEddystoneUIDPowerLevel1 = -30,
    ESTEddystoneUIDPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTEddystoneUIDPowerLevel2 = -20,
    ESTEddystoneUIDPowerLevel3 = -16,
    ESTEddystoneUIDPowerLevel4 = -12,
    ESTEddystoneUIDPowerLevel5 = -8,
    ESTEddystoneUIDPowerLevel6 = -4,
    ESTEddystoneUIDPowerLevel7 = 0,
    ESTEddystoneUIDPowerLevel8 = 4,
    ESTEddystoneUIDPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};


/**
 *  ESTSettingEddystoneUIDPower represents Eddystone UID Power value.
 */
@interface ESTSettingEddystoneUIDPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEstimoteLocationPower validationErrorForValue:]
 *
 *  @param power Eddystone UID Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(ESTEddystoneUIDPower)power;

/**
 *  Returns current value of Eddystone UID Power setting.
 *
 *  @return Eddystone UID Power value.
 */
- (ESTEddystoneUIDPower)getValue;

/**
 *  Method allows to read value of initialized Eddystone UID Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneUIDPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone UID Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTEddystoneUIDPower)power completion:(ESTSettingEddystoneUIDPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTEddystoneUIDPower)power;

@end

NS_ASSUME_NONNULL_END
