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
#import "ESTDefinitions.h"

@class ESTSettingDeviceInfoColor;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Color operation for DeviceInfo packet.
 *
 *  @param Color Color setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoColorCompletionBlock)(ESTSettingDeviceInfoColor * _Nullable ColorSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoColor represents DeviceInfo Color value.
 */
@interface ESTSettingDeviceInfoColor : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingDeviceInfoColor validationErrorForValue:]
 *
 *  @param Color DeviceInfo Color value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTColor)color;

/**
 *  Returns current value of DeviceInfo Color setting.
 *
 *  @return DeviceInfo Color value.
 */
- (ESTColor)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo Color setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoColorCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
