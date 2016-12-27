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

#define ESTSettingDeviceInfoApplicationVersionErrorDomain @"ESTSettingDeviceInfoApplicationVersionErrorDomain"

/**
 *  Describes application version validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingDeviceInfoApplicationVersionError)
{
    /**
     *  Provided application version value is equal to nil.
     */
    ESTSettingDeviceInfoApplicationVersionErrorNilValue,
    /**
     *  Provided application version value is empty string.
     */
    ESTSettingDeviceInfoApplicationVersionErrorEmptyString
};

@class ESTSettingDeviceInfoApplicationVersion;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting ApplicationVersion operation for Device Info packet.
 *
 *  @param applicationVersionSetting ApplicationVersion setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoApplicationVersionCompletionBlock)(ESTSettingDeviceInfoApplicationVersion * _Nullable applicationVersionSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoApplicationVersion represents Device Info ApplicationVersion value.
 */
@interface ESTSettingDeviceInfoApplicationVersion : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param applicationVersion Device Info ApplicationVersion value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)applicationVersion;

/**
 *  Returns current value of Device Info ApplicationVersion setting.
 *
 *  @return Device Info ApplicationVersion value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Device Info ApplicationVersion setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoApplicationVersionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
