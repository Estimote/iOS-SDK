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

@class ESTSettingDeviceInfoIndoorLocationIdentifier;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting IndoorLocationIdentifier operation for DeviceInfo packet.
 *
 *  @param indoorLocationIdentifier IndoorLocationIdentifier setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoIndoorLocationIdentifierCompletionBlock)(ESTSettingDeviceInfoIndoorLocationIdentifier * _Nullable indoorLocationIdentifierSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoIndoorLocationIdentifier represents DeviceInfo IndoorLocationIdentifier value.
 */
@interface ESTSettingDeviceInfoIndoorLocationIdentifier : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param indoorLocationIdentifier DeviceInfo IndoorLocationIdentifier value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSString *)indoorLocationIdentifier;

/**
 *  Returns current value of DeviceInfo IndoorLocationIdentifier setting.
 *
 *  @return DeviceInfo IndoorLocationIdentifier value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized DeviceInfo IndoorLocationIdentifier setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoIndoorLocationIdentifierCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
