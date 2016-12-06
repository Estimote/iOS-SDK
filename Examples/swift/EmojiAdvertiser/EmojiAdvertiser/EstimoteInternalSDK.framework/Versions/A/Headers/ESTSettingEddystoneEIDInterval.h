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

#define ESTSettingEddystoneEIDIntervalErrorDomain @"ESTSettingEddystoneEIDIntervalErrorDomain"

/**
 *  Describes EddystoneEID Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneEIDIntervalError)
{
     /**
     *  Provided value is too small.
     */
    ESTSettingEddystoneEIDIntervalErrorValueTooSmall = 1,
    
    /**
     *  Provided value is too big.
     */
    ESTSettingEddystoneEIDIntervalErrorValueTooBig = 2
};

@class ESTSettingEddystoneEIDInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Interval operation for EddystoneEID packet.
 *
 *  @param interval Interval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneEIDIntervalCompletionBlock)(ESTSettingEddystoneEIDInterval * _Nullable intervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneEIDInterval represents EddystoneEID Interval value.
 */
@interface ESTSettingEddystoneEIDInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneEIDInterval validationErrorForValue:]
 *
 *  @param interval EddystoneEID Interval value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(unsigned short)interval;

/**
 *  Returns current value of EddystoneEID Interval setting.
 *
 *  @return EddystoneEID Interval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized EddystoneEID Interval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneEIDIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized EddystoneEID Interval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param interval Interval value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(unsigned short)interval completion:(ESTSettingEddystoneEIDIntervalCompletionBlock)completion;

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
