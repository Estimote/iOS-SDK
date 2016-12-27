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

#define ESTSettingNearableIntervalErrorDomain @"ESTSettingNearableIntervalErrorDomain"

/**
 *  Describes Nearable Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingNearableIntervalError) {
    /**
     *  Provided value is too small.
     */
    ESTSettingNearableIntervalErrorValueTooSmall = 1,
    /**
     *  Provided value is too big.
     */
    ESTSettingNearableIntervalErrorValueTooBig,
    
    /**
     *  Convenience API is unsupported.
     */
    ESTSettingNearableIntervalErrorConvenienceAPIUnsupported
};

@class ESTSettingNearableInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Interval operation for Nearable packet.
 *
 *  @param intervalSetting Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingNearableIntervalCompletionBlock)(ESTSettingNearableInterval * _Nullable intervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingNearableInterval represents Nearable Interval value.
 */
@interface ESTSettingNearableInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingNearableInterval validationErrorForValue:]
 *
 *  @param interval Nearable Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned short)interval;

/**
 *  Returns current value of Nearable Interval setting.
 *
 *  @return Nearable Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Nearable Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingNearableIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Nearable Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param interval Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(unsigned short)interval completion:(ESTSettingNearableIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param interval Interval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)interval;

@end

NS_ASSUME_NONNULL_END
