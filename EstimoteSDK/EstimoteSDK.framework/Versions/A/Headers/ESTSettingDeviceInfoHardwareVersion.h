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

#define ESTSettingDeviceInfoHardwareVersionErrorDomain @"ESTSettingDeviceInfoHardwareVersionErrorDomain"

/**
 *  Describes hardware version validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingDeviceInfoHardwareVersionError)
{
    /**
     *  Provided hardware version value is equal to nil.
     */
    ESTSettingDeviceInfoHardwareVersionErrorNilValue,
    /**
     *  Provided hardware version value is empty string.
     */
    ESTSettingDeviceInfoHardwareVersionErrorEmptyString
};

@class ESTSettingDeviceInfoHardwareVersion;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting Hardware Version operation for Device packet.
 *
 *  @param versionSetting HardwareVersion setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoHardwareVersionCompletionBlock)(ESTSettingDeviceInfoHardwareVersion * _Nullable versionSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoHardwareVersion represents Device Hardware Version value.
 */
@interface ESTSettingDeviceInfoHardwareVersion : ESTSettingReadOnly <NSCopying>

/**
 *  Returns current value of Device Hardware Version setting.
 *
 *  @return Device HardwareVersion value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Device HardwareVersion setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoHardwareVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
