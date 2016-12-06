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
#import "ESTSettingReadOnly.h"

@class ESTSettingDeviceInfoIndoorLocationName;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting IndoorLocationName operation for DeviceInfo packet.
 *
 *  @param name IndoorLocationName setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoIndoorLocationNameCompletionBlock)(ESTSettingDeviceInfoIndoorLocationName * _Nullable nameSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoIndoorLocationName represents DeviceInfo IndoorLocationName value.
 */
@interface ESTSettingDeviceInfoIndoorLocationName : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param name DeviceInfo IndoorLocationName value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)name;

/**
 *  Returns current value of DeviceInfo IndoorLocationName setting.
 *
 *  @return DeviceInfo IndoorLocationName value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo IndoorLocationName setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoIndoorLocationNameCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
