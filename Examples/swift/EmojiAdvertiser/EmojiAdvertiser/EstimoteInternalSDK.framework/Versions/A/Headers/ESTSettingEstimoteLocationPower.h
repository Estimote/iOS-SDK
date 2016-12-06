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

#define ESTSettingEstimoteLocationPowerErrorDomain @"ESTSettingEstimoteLocationPowerErrorDomain"

/**
 *  Describes Estimote Location Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEstimoteLocationPowerError) {
    /**
     *  Provided value does not belong to the ESTEstimoteLocationPower enum.
     */
    ESTSettingEstimoteLocationPowerErrorValueNotAllowed = 1
};

@class ESTSettingEstimoteLocationPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Broadcasting Power operation for Estimote Location packet.
 *
 *  @param power Broadcasting Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEstimoteLocationPowerCompletionBlock)(ESTSettingEstimoteLocationPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for Estimote Location packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTEstimoteLocationPower)
{
    ESTEstimoteLocationPowerLevel1 = -30,
    ESTEstimoteLocationPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTEstimoteLocationPowerLevel2 = -20,
    ESTEstimoteLocationPowerLevel3 = -16,
    ESTEstimoteLocationPowerLevel4 = -12,
    ESTEstimoteLocationPowerLevel5 = -8,
    ESTEstimoteLocationPowerLevel6 = -4,
    ESTEstimoteLocationPowerLevel7 = 0,
    ESTEstimoteLocationPowerLevel8 = 4,
    ESTEstimoteLocationPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};


/**
 *  ESTSettingEstimoteLocationPower represents Estimote Location Broadcasting Power value.
 */
@interface ESTSettingEstimoteLocationPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEstimoteLocationPower validationErrorForValue:]
 *
 *  @param power Estimote Location Power value.
 *
 *  @return Initialized object. Returns nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(ESTEstimoteLocationPower)power;

/**
 *  Returns current value of Estimote Location Broadcasting Power setting.
 *
 *  @return Estimote Location Broadcasting Power value.
 */
- (ESTEstimoteLocationPower)getValue;

/**
 *  Method allows to read value of initialized Estimote Location Broadcasting Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEstimoteLocationPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Estimote Location Broadcasting Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Broadcasting Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTEstimoteLocationPower)power completion:(ESTSettingEstimoteLocationPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTEstimoteLocationPower)power;

@end

NS_ASSUME_NONNULL_END
