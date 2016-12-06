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

#define ESTSettingEddystoneURLPowerErrorDomain @"ESTSettingEddystoneURLPowerErrorDomain"

/**
 *  Describes EddystoneURL Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneURLPowerError) {
    /**
     *  Provided value does not belong to the ESTEddystoneURLPower enum.
     */
    ESTSettingEddystoneURLPowerErrorValueNotAllowed = 1
};

@class ESTSettingEddystoneURLPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Eddystone URL packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneURLPowerCompletionBlock)(ESTSettingEddystoneURLPower * _Nullable powerSetting, NSError * _Nullable error);

/**
 *  Available Tx Power levels for Eddystone URL packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTEddystoneURLPower)
{
    ESTEddystoneURLPowerLevel1 = -30,
    ESTEddystoneURLPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTEddystoneURLPowerLevel2 = -20,
    ESTEddystoneURLPowerLevel3 = -16,
    ESTEddystoneURLPowerLevel4 = -12,
    ESTEddystoneURLPowerLevel5 = -8,
    ESTEddystoneURLPowerLevel6 = -4,
    ESTEddystoneURLPowerLevel7 = 0,
    ESTEddystoneURLPowerLevel8 = 4,
    ESTEddystoneURLPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};


/**
 *  ESTSettingEddystoneURLPower represents Eddystone URL Power value.
 */
@interface ESTSettingEddystoneURLPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:. 
 *
 *  @see +[ESTSettingEddystoneURLPower validationErrorForValue:]
 *
 *  @param power Eddystone URL Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(ESTEddystoneURLPower)power;

/**
 *  Returns current value of Eddystone URL Power setting.
 *
 *  @return Eddystone URL Power value.
 */
- (ESTEddystoneURLPower)getValue;

/**
 *  Method allows to read value of initialized Eddystone URL Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneURLPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone URL Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTEddystoneURLPower)power completion:(ESTSettingEddystoneURLPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTEddystoneURLPower)power;

@end

NS_ASSUME_NONNULL_END
