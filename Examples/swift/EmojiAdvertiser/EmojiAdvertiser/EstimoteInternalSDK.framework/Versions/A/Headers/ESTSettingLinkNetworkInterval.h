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

#define ESTSettingLinkNetworkIntervalErrorDomain @"ESTSettingLinkNetworkIntervalErrorDomain"

/**
 *  Describes Link Network Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingLinkNetworkIntervalError)
{
     /**
     *  Provided value is too small - should be equal or bigger than 100ms.
     */
    ESTSettingLinkNetworkIntervalErrorTooSmall = 1,
    
    /**
     *  Provided value is too big - should be less or equal 10000 ms.
     */
    ESTSettingLinkNetworkIntervalErrorTooBig = 2
};

@class ESTSettingLinkNetworkInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Interval operation for Link Network packet.
 *
 *  @param interval Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingLinkNetworkIntervalCompletionBlock)(ESTSettingLinkNetworkInterval * _Nullable intervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingLinkNetworkInterval represents Link Network Interval value.
 */
@interface ESTSettingLinkNetworkInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingLinkNetworkInterval validationErrorForValue:]
 *
 *  @param interval Link Network Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned short)interval;

/**
 *  Returns current value of Link Network Interval setting.
 *
 *  @return Link Network Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Link Network Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingLinkNetworkIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Link Network Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param interval Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(unsigned short)interval completion:(ESTSettingLinkNetworkIntervalCompletionBlock)completion;

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
