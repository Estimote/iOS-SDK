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

@class ESTSettingPowerScheduledAdvertisingEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting ScheduledAdvertisingEnable operation for Power packet.
 *
 *  @param enableSetting ScheduledAdvertisingEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerScheduledAdvertisingEnableCompletionBlock)(ESTSettingPowerScheduledAdvertisingEnable * _Nullable enableSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerScheduledAdvertisingEnable represents Power ScheduledAdvertisingEnable value.
 */
@interface ESTSettingPowerScheduledAdvertisingEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerScheduledAdvertisingEnable validationErrorForValue:]
 *
 *  @param enable Power ScheduledAdvertisingEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enable;

/**
 *  Returns current value of Power ScheduledAdvertisingEnable setting.
 *
 *  @return Power ScheduledAdvertisingEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Power ScheduledAdvertisingEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingPowerScheduledAdvertisingEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power ScheduledAdvertisingEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enable ScheduledAdvertisingEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enable completion:(ESTSettingPowerScheduledAdvertisingEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enable ScheduledAdvertisingEnable value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
