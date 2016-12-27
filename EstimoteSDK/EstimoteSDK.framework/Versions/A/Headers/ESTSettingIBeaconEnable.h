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

@class ESTSettingIBeaconEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enable operation for iBeacon packet.
 *
 *  @param iBeaconEnableSetting IBeaconEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconEnableCompletionBlock)(ESTSettingIBeaconEnable * _Nullable iBeaconEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconEnable represents iBeacon Enable value.
 */
@interface ESTSettingIBeaconEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param enabled iBeacon Enable value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of iBeacon Enable setting.
 *
 *  @return iBeacon IBeaconEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized iBeacon Enable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon Enable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled      Enable value to be written to the device.
 *  @param completion   Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingIBeaconEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
