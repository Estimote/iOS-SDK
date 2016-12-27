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


@class ESTSettingIBeaconMotionUUIDEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting MotionUUIDEnable operation for iBeacon packet.
 *
 *  @param enabledSetting MotionUUIDEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconMotionUUIDEnableCompletionBlock)(ESTSettingIBeaconMotionUUIDEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconMotionUUIDEnable represents iBeacon MotionUUIDEnable value.
 */
@interface ESTSettingIBeaconMotionUUIDEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingIBeaconMotionUUIDEnable validationErrorForValue:]
 *
 *  @param enabled iBeacon MotionUUIDEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of iBeacon MotionUUIDEnable setting.
 *
 *  @return iBeacon MotionUUIDEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized iBeacon MotionUUIDEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconMotionUUIDEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon MotionUUIDEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled MotionUUIDEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingIBeaconMotionUUIDEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
