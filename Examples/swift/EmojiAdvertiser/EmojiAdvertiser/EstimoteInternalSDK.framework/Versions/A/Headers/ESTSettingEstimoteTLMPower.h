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

#define ESTSettingEstimoteTLMPowerErrorDomain @"ESTSettingEstimoteTLMPowerErrorDomain"

/**
 *  Describes Estimote Telemetry Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEstimoteTLMPowerError) {
    /**
     *  Provided value does not belong to the ESTEstimoteTLMPower enum.
     */
    ESTSettingEstimoteTLMPowerErrorValueNotAllowed = 1
};

@class ESTSettingEstimoteTLMPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Estimote Telemetry packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEstimoteTLMPowerCompletionBlock)(ESTSettingEstimoteTLMPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for Estimote Telemetry packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTEstimoteTLMPower)
{
    ESTEstimoteTLMPowerLevel1 = -30,
    ESTEstimoteTLMPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTEstimoteTLMPowerLevel2 = -20,
    ESTEstimoteTLMPowerLevel3 = -16,
    ESTEstimoteTLMPowerLevel4 = -12,
    ESTEstimoteTLMPowerLevel5 = -8,
    ESTEstimoteTLMPowerLevel6 = -4,
    ESTEstimoteTLMPowerLevel7 = 0,
    ESTEstimoteTLMPowerLevel8 = 4,
    ESTEstimoteTLMPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};


/**
 *  ESTSettingEstimoteTLMPower represents Estimote Telemetry Power value.
 */
@interface ESTSettingEstimoteTLMPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEstimoteTLMPower validationErrorForValue:]
 *
 *  @param power Estimote Telemetry Power value.
 *
 *  @return Initialized object. Returns nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(ESTEstimoteTLMPower)power;

/**
 *  Returns current value of Estimote Telemetry Power setting.
 *
 *  @return Estimote Telemetry Power value.
 */
- (ESTEstimoteTLMPower)getValue;

/**
 *  Method allows to read value of initialized Estimote Telemetry Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEstimoteTLMPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Estimote Telemetry Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTEstimoteTLMPower)power completion:(ESTSettingEstimoteTLMPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTEstimoteTLMPower)power;

@end

NS_ASSUME_NONNULL_END
