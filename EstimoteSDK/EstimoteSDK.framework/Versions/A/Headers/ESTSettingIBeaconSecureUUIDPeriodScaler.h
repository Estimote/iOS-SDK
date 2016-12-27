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

@class ESTSettingIBeaconSecureUUIDPeriodScaler;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting SecureUUIDPeriodScaler operation for iBeacon packet.
 *  The Secure UUID rotation period is equal to 2^scaler seconds.
 *
 *  @param scalerSetting SecureUUIDPeriodScaler setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconSecureUUIDPeriodScalerCompletionBlock)(ESTSettingIBeaconSecureUUIDPeriodScaler * _Nullable scalerSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconSecureUUIDPeriodScaler represents iBeacon SecureUUIDPeriodScaler value.
 */
@interface ESTSettingIBeaconSecureUUIDPeriodScaler : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param scaler iBeacon SecureUUIDPeriodScaler value. The Secure UUID rotation period is equal to 2^scaler seconds.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(uint8_t)scaler;

/**
 *  Returns current value of iBeacon SecureUUIDPeriodScaler setting.
 *
 *  @return iBeacon SecureUUIDPeriodScaler value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized iBeacon SecureUUIDPeriodScaler setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconSecureUUIDPeriodScalerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon SecureUUIDPeriodScaler setting object.
 *  Value provided during initialization will be used as a desired value.
 *  The Secure UUID rotation period is equal to 2^scaler seconds.
 *
 *  @param scaler SecureUUIDPeriodScaler value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint8_t)scaler completion:(ESTSettingIBeaconSecureUUIDPeriodScalerCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
