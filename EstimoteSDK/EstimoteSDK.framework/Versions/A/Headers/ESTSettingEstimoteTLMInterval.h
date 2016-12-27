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

#define ESTSettingEstimoteTLMIntervalErrorDomain @"ESTSettingEstimoteTLMIntervalErrorDomain"

/**
 *  Describes Estimote Telemetry Advertising Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEstimoteTLMIntervalError) {
    /**
     *  Provided value is too small.
     */
    ESTSettingEstimoteTLMIntervalErrorValueTooSmall = 1,
    /**
     *  Provided value is too big.
     */
    ESTSettingEstimoteTLMIntervalErrorValueTooBig
};

@class ESTSettingEstimoteTLMInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Advertising Interval operation for Estimote Telemetry packet.
 *
 *  @param advertisingIntervalSetting Advertising Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEstimoteTLMIntervalCompletionBlock)(ESTSettingEstimoteTLMInterval * _Nullable advertisingIntervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingEstimoteTLMInterval represents Estimote Telemetry Advertising Interval value.
 */
@interface ESTSettingEstimoteTLMInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *  
 *  @see +[ESTSettingEstimoteTLMInterval validationErrorForValue:]
 *
 *  @param advertisingInterval Estimote Telemetry Advertising Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(unsigned short)advertisingInterval;

/**
 *  Returns current value of Estimote Telemetry Advertising Interval setting.
 *
 *  @return Estimote Telemetry AdvertisingInterval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Estimote Telemetry Advertising Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEstimoteTLMIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Estimote Telemetry Advertising Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param advertisingInterval AdvertisingInterval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(unsigned short)advertisingInterval completion:(ESTSettingEstimoteTLMIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param advertisingInterval Advertising Interval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)advertisingInterval;

@end

NS_ASSUME_NONNULL_END
