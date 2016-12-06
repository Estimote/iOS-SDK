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

#define ESTSettingConnectablePowerErrorDomain @"ESTSettingConnectablePowerErrorDomain"

/**
 *  Describes Connectable Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingConnectablePowerError)
{
     /**
     *  Provided value is not allowed. You should use ESTConnectablePower enum values.
     */
    ESTSettingConnectablePowerErrorValueNotAllowed = 1
};

typedef NS_ENUM(int8_t, ESTConnectablePowerLevel)
{
    ESTConnectablePowerLevel1 = -30,
    ESTConnectablePowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTConnectablePowerLevel2 = -20,
    ESTConnectablePowerLevel3 = -16,
    ESTConnectablePowerLevel4 = -12,
    ESTConnectablePowerLevel5 = -8,
    ESTConnectablePowerLevel6 = -4,
    ESTConnectablePowerLevel7 = 0,
    ESTConnectablePowerLevel8 = 4,
    ESTConnectablePowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};


@class ESTSettingConnectivityPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Connectivity packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingConnectivityPowerCompletionBlock)(ESTSettingConnectivityPower * _Nullable powerSetting, NSError * _Nullable error);


/**
 *  ESTSettingConnectivityPower represents Connectivity Power value.
 */
@interface ESTSettingConnectivityPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingConnectablePower validationErrorForValue:]
 *
 *  @param power Connectivity Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTConnectablePowerLevel)power;

/**
 *  Returns current value of Connectivity Power setting.
 *
 *  @return Connectable Power value.
 */
- (ESTConnectablePowerLevel)getValue;

/**
 *  Method allows to read value of initialized Connectivity Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingConnectivityPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Connectivity Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTConnectablePowerLevel)power completion:(ESTSettingConnectivityPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTConnectablePowerLevel)power;

@end

NS_ASSUME_NONNULL_END
