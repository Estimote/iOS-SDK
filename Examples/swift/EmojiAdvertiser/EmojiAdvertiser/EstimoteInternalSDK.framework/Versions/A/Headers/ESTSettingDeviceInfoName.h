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

@class ESTSettingDeviceInfoName;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Name operation for Device Info packet.
 *
 *  @param name Name setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoNameCompletionBlock)(ESTSettingDeviceInfoName * _Nullable nameSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoName represents Device Info Name value.
 */
@interface ESTSettingDeviceInfoName : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingDeviceInfoName validationErrorForValue:]
 *
 *  @param name Device Info Name value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSString *)name;

/**
 *  Returns current value of Device Info Name setting.
 *
 *  @return Device Info Name value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Device Info Name setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoNameCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Device Info Name setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param name Name value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(NSString *)name completion:(ESTSettingDeviceInfoNameCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param name Name value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
