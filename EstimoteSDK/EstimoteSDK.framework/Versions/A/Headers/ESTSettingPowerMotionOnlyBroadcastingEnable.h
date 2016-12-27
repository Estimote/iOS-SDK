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

@class ESTSettingPowerMotionOnlyBroadcastingEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting MotionOnlyBroadcastingEnable operation for DeviceInfo packet.
 *
 *  @param enabledSetting MotionOnlyBroadcastingEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerMotionOnlyBroadcastingEnableCompletionBlock)(ESTSettingPowerMotionOnlyBroadcastingEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerMotionOnlyBroadcastingEnable represents DeviceInfo MotionOnlyBroadcastingEnable value.
 */
@interface ESTSettingPowerMotionOnlyBroadcastingEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerMotionOnlyBroadcastingEnable validationErrorForValue:]
 *
 *  @param enabled DeviceInfo MotionOnlyBroadcastingEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of DeviceInfo MotionOnlyBroadcastingEnable setting.
 *
 *  @return DeviceInfo MotionOnlyBroadcastingEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo MotionOnlyBroadcastingEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingPowerMotionOnlyBroadcastingEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized DeviceInfo MotionOnlyBroadcastingEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled MotionOnlyBroadcastingEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingPowerMotionOnlyBroadcastingEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enabled MotionOnlyBroadcastingEnable value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
