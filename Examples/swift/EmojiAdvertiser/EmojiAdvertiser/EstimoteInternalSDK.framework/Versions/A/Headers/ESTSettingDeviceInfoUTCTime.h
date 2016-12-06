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

@class ESTSettingDeviceInfoUTCTime;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting UTCTime operation. Works with time interval since 1970, 1 second precision.
 *
 *  @param UTCTime UTCTime setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoUTCTimeCompletionBlock)(ESTSettingDeviceInfoUTCTime * _Nullable UTCTimeSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoUTCTime represents Device UTCTime value.
 */
@interface ESTSettingDeviceInfoUTCTime : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param UTCTime UTCTime value - time interval since 1970. The fraction part (milliseconds) is discarded.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSTimeInterval)UTCTime;

/**
 *  Returns current value of UTCTime setting.
 *
 *  @return Time interval since 1970 (UTC time).
 */
- (NSTimeInterval)getValue;

/**
 *  Method allows to read value of initialized Device UTCTime setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoUTCTimeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Device UTCTime setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param UTCTime UTCTime value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(NSTimeInterval)UTCTime completion:(ESTSettingDeviceInfoUTCTimeCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param UTCTime UTCTime value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSTimeInterval)UTCTime;

@end

NS_ASSUME_NONNULL_END
