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

#define ESTSettingLinkNetworkPowerErrorDomain @"ESTSettingLinkNetworkPowerErrorDomain"

/**
 *  Describes Link Network Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingLinkNetworkPowerError)
{
     /**
     *  Provided value does not belong to ESTLinkNetworkPower enum.
     */
    ESTSettingLinkNetworkPowerErrorNotAllowed = 1
};

/**
 *  Available Tx Power levels for Link Network packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTLinkNetworkPower)
{
    ESTLinkNetworkPowerLevel1 = -30,
    ESTLinkNetworkPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTLinkNetworkPowerLevel2 = -20,
    ESTLinkNetworkPowerLevel3 = -16,
    ESTLinkNetworkPowerLevel4 = -12,
    ESTLinkNetworkPowerLevel5 = -8,
    ESTLinkNetworkPowerLevel6 = -4,
    ESTLinkNetworkPowerLevel7 = 0,
    ESTLinkNetworkPowerLevel8 = 4,
    ESTLinkNetworkPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};

@class ESTSettingLinkNetworkPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Link Network packet.
 *
 *  @param power Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingLinkNetworkPowerCompletionBlock)(ESTSettingLinkNetworkPower * _Nullable powerSetting, NSError * _Nullable error);


/**
 *  ESTSettingLinkNetworkPower represents Link Network Power value.
 */
@interface ESTSettingLinkNetworkPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingLinkNetworkPower validationErrorForValue:]
 *
 *  @param power Link Network Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTLinkNetworkPower)power;

/**
 *  Returns current value of Link Network Power setting.
 *
 *  @return Link Network Power value.
 */
- (ESTLinkNetworkPower)getValue;

/**
 *  Method allows to read value of initialized Link Network Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingLinkNetworkPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Link Network Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTLinkNetworkPower)power completion:(ESTSettingLinkNetworkPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(int8_t)power;

@end

NS_ASSUME_NONNULL_END
