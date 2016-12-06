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

#define ESTSettingEddystoneTLMIntervalErrorDomain @"ESTSettingEddystoneTLMIntervalErrorDomain"

/**
 *  Describes Eddystone Telemetry Advertising Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneTLMIntervalError) {
    /**
     *  Provided value is too small.
     */
    ESTSettingEddystoneTLMIntervalErrorValueTooSmall = 1,
    /**
     *  Provided value is too big.
     */
    ESTSettingEddystoneTLMIntervalErrorValueTooBig
};

@class ESTSettingEddystoneTLMInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Advertising Interval operation for Eddystone Telemetry packet.
 *
 *  @param advertisingInterval Advertising Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneTLMIntervalCompletionBlock)(ESTSettingEddystoneTLMInterval * _Nullable advertisingIntervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneTLMInterval represents Eddystone Telemetry Advertising Interval value.
 */
@interface ESTSettingEddystoneTLMInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param advertisingInterval Eddystone Telemetry Advertising Interval value.
 *
 *  @return Initialized object.
 */
- (instancetype _Nullable)initWithValue:(unsigned short)advertisingInterval;

/**
 *  Returns current value of Eddystone Telemetry Advertising Interval setting.
 *
 *  @return Eddystone Telemetry Advertising Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Eddystone Telemetry Advertising Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneTLMIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone Telemetry Advertising Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param advertisingInterval Advertising Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(unsigned short)advertisingInterval completion:(ESTSettingEddystoneTLMIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param advertisingInterval AdvertisingInterval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)advertisingInterval;

@end

NS_ASSUME_NONNULL_END
