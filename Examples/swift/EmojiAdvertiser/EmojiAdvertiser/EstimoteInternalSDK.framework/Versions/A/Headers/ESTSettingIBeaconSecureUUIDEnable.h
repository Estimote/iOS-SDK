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

@class ESTSettingIBeaconSecureUUIDEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting SecureUUIDEnable operation for iBeacon packet.
 *
 *  @param enabled SecureUUIDEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconSecureUUIDEnableCompletionBlock)(ESTSettingIBeaconSecureUUIDEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconSecureUUIDEnable represents iBeacon SecureUUIDEnable value.
 */
@interface ESTSettingIBeaconSecureUUIDEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param enabled iBeacon SecureUUIDEnable value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of iBeacon SecureUUIDEnable setting.
 *
 *  @return iBeacon SecureUUIDEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized iBeacon SecureUUIDEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconSecureUUIDEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon SecureUUIDEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled SecureUUIDEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingIBeaconSecureUUIDEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
