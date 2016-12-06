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

#define ESTSettingPowerMotionOnlyBroadcastingDelayErrorDomain @"ESTSettingPowerMotionOnlyBroadcastingDelayErrorDomain"

/**
 *  Describes Power MotionOnlyBroadcastingDelay validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingPowerMotionOnlyBroadcastingDelayError)
{
     /**
     *  Provided value is too small.
     */
    ESTSettingPowerMotionOnlyBroadcastingDelayErrorValueTooSmall = 1,
    /**
     *  Provided value is too big.
     */
    ESTSettingPowerMotionOnlyBroadcastingDelayErrorValueTooBig = 2
};

@class ESTSettingPowerMotionOnlyBroadcastingDelay;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting MotionOnlyBroadcastingDelay operation for Power packet.
 *
 *  @param motionOnlyBroadcastingDelay MotionOnlyBroadcastingDelay setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerMotionOnlyBroadcastingDelayCompletionBlock)(ESTSettingPowerMotionOnlyBroadcastingDelay * _Nullable motionOnlyBroadcastingDelaySetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerMotionOnlyBroadcastingDelay represents Power MotionOnlyBroadcastingDelay value.
 */
@interface ESTSettingPowerMotionOnlyBroadcastingDelay : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerMotionOnlyBroadcastingDelay validationErrorForValue:]
 *
 *  @param motionOnlyBroadcastingDelay Power MotionOnlyBroadcastingDelay value in milliseconds.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned int)motionOnlyBroadcastingDelay;

/**
 *  Returns current value of Power MotionOnlyBroadcastingDelay setting in milliseconds.
 *
 *  @return Power MotionOnlyBroadcastingDelay value.
 */
- (unsigned int)getValue;

/**
 *  Method allows to read value of initialized Power MotionOnlyBroadcastingDelay setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingPowerMotionOnlyBroadcastingDelayCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power MotionOnlyBroadcastingDelay setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param motionOnlyBroadcastingDelay MotionOnlyBroadcastingDelay value in milliseconds to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(unsigned int)motionOnlyBroadcastingDelay completion:(ESTSettingPowerMotionOnlyBroadcastingDelayCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param motionOnlyBroadcastingDelay MotionOnlyBroadcastingDelay value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned int)motionOnlyBroadcastingDelay;

@end

NS_ASSUME_NONNULL_END
