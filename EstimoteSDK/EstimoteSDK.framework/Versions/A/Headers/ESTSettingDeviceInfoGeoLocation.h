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

@class ESTDeviceGeoLocation;
@class ESTSettingDeviceInfoGeoLocation;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting GeoLocation operation for Cloud packet.
 *
 *  @param geoLocationSetting GeoLocation setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingDeviceInfoGeoLocationCompletionBlock)(ESTSettingDeviceInfoGeoLocation * _Nullable geoLocationSetting, NSError * _Nullable error);


/**
 *  ESTSettingDeviceInfoGeoLocation represents Cloud GeoLocation value.
 */
@interface ESTSettingDeviceInfoGeoLocation : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingDeviceInfoGeoLocation validationErrorForValue:]
 *
 *  @param geoLocation Cloud GeoLocation value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTDeviceGeoLocation *)geoLocation;

/**
 *  Returns current value of GeoLocation setting.
 *
 *  @return Cloud GeoLocation value.
 */
- (ESTDeviceGeoLocation *)getValue;

/**
 *  Method allows to read value of initialized Cloud GeoLocation setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingDeviceInfoGeoLocationCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Cloud GeoLocation setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param geoLocation GeoLocation value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTDeviceGeoLocation *)geoLocation completion:(ESTSettingDeviceInfoGeoLocationCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param geoLocation GeoLocation value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTDeviceGeoLocation *)geoLocation;

@end

NS_ASSUME_NONNULL_END
