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

#define ESTSettingNearablePowerErrorDomain @"ESTSettingNearablePowerErrorDomain"

/**
 *  Describes Nearable Power validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingNearablePowerError) {
    /**
     *  Provided value does not belong to the ESTNearablePower enum.
     */
    ESTSettingNearablePowerErrorValueNotAllowed = 1,
    
    /**
     *  Convenience API is unsupported.
     */
    ESTSettingNearablePowerErrorConvenienceAPIUnsupported
};

@class ESTSettingNearablePower;


/**
 *  Available Tx Power levels for Nearable packet.
 *  @see ESTBeaconPower
 */
typedef NS_ENUM(int8_t, ESTNearablePower)
{
    ESTNearablePowerLevel1 = -30,
    ESTNearablePowerLevel2 = -20,
    ESTNearablePowerLevel3 = -16,
    ESTNearablePowerLevel4 = -12,
    ESTNearablePowerLevel5 = -8,
    ESTNearablePowerLevel6 = -4,
    ESTNearablePowerLevel7 = 0,
    ESTNearablePowerLevel8 = 4
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Power operation for Nearable packet.
 *
 *  @param powerSetting Power setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingNearablePowerCompletionBlock)(ESTSettingNearablePower * _Nullable powerSetting, NSError * _Nullable error);


/**
 *  ESTSettingNearablePower represents Nearable Power value.
 */
@interface ESTSettingNearablePower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingNearablePower validationErrorForValue:]
 *
 *  @param power Nearable Power value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTNearablePower)ower;

/**
 *  Returns current value of Nearable Power setting.
 *
 *  @return Nearable Power value.
 */
- (ESTNearablePower)getValue;

/**
 *  Method allows to read value of initialized Nearable Power setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingNearablePowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Nearable Power setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param power Power value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(ESTNearablePower)power completion:(ESTSettingNearablePowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param Power Power value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTNearablePower)Power;

@end

NS_ASSUME_NONNULL_END
