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

@class ESTSettingDeviceInfoFirmwareVersion;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting FirmwareVersion operation for DeviceInfo packet.
 *
 *  @param version FirmwareVersion setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoFirmwareVersionCompletionBlock)(ESTSettingDeviceInfoFirmwareVersion * _Nullable versionSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoFirmwareVersion represents DeviceInfo FirmwareVersion value.
 */
@interface ESTSettingDeviceInfoFirmwareVersion : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param version FirmwareVersion value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)version;

/**
 *  Returns current value of DeviceInfo FirmwareVersion setting.
 *
 *  @return DeviceInfo FirmwareVersion value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized FirmwareVersion setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoFirmwareVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
