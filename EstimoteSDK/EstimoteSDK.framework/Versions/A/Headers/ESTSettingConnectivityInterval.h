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

#define ESTSettingConnectableIntervalErrorDomain @"ESTSettingConnectableIntervalErrorDomain"

/**
 *  Describes Connectivity Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingConnectableIntervalError)
{
     /**
     *  Provided value is too small.
     */
    ESTSettingConnectableIntervalErrorValueTooSmall = 1,
    
    /**
     *  Provided value is too big.
     */
    ESTSettingConnectableIntervalErrorValueTooBig
};

@class ESTSettingConnectivityInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Interval operation for Connectivity packet.
 *
 *  @param intervalSetting Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingConnectivityIntervalCompletionBlock)(ESTSettingConnectivityInterval * _Nullable intervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingConnectivityInterval represents Connectivity Interval value.
 */
@interface ESTSettingConnectivityInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingConnectivityInterval validationErrorForValue:]
 *
 *  @param interval Connectivity Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned short)interval;

/**
 *  Returns current value of Connectivity Interval setting.
 *
 *  @return Connectable Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Connectivity Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingConnectivityIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Connectivity Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param interval Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(unsigned short)interval completion:(ESTSettingConnectivityIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param interval Interval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (nullable NSError *)validationErrorForValue:(unsigned short)interval;

@end

NS_ASSUME_NONNULL_END
