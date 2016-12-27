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

#define ESTSettingEddystoneURLIntervalErrorDomain @"ESTSettingEddystoneURLIntervalErrorDomain"

/**
 *  Describes Eddystone URL Advertising Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneURLIntervalError) {
    /**
     *  Provided value is too small.
     */
    ESTSettingEddystoneURLIntervalErrorValueTooSmall = 1,
    
    /**
     *  Provided value is too big.
     */
    ESTSettingEddystoneURLIntervalErrorValueTooBig
};



@class ESTSettingEddystoneURLInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Interval operation for Eddystone URL packet.
 *
 *  @param advertisingIntervalSetting Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneURLIntervalCompletionBlock)(ESTSettingEddystoneURLInterval * _Nullable advertisingIntervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneURLInterval represents Eddystone URL Advertising Interval value.
 */
@interface ESTSettingEddystoneURLInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *  
 *  @see +[ESTSettingEstimoteLocationInterval validationErrorForValue:]
 *
 *  @param advertisingInterval Eddystone URL Advertising Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(unsigned short)advertisingInterval;

/**
 *  Returns current value of Eddystone URL Advertising Interval setting.
 *
 *  @return Eddystone URL Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Eddystone URL Advertising Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneURLIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone URL Advertising Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param advertisingInterval Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(unsigned short)advertisingInterval completion:(ESTSettingEddystoneURLIntervalCompletionBlock)completion;

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
