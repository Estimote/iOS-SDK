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

@class ESTSettingPowerSmartPowerModeEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting SmartPowerModeEnable operation for Power packet.
 *
 *  @param smartPowerModeEnable SmartPowerModeEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerSmartPowerModeEnableCompletionBlock)(ESTSettingPowerSmartPowerModeEnable * _Nullable smartPowerModeEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerSmartPowerModeEnable represents Power SmartPowerModeEnable value.
 */
@interface ESTSettingPowerSmartPowerModeEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerSmartPowerModeEnable validationErrorForValue:]
 *
 *  @param smartPowerModeEnable Power SmartPowerModeEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)smartPowerModeEnable;

/**
 *  Returns current value of Power SmartPowerModeEnable setting.
 *
 *  @return Power SmartPowerModeEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Power SmartPowerModeEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingPowerSmartPowerModeEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power SmartPowerModeEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param smartPowerModeEnable SmartPowerModeEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(BOOL)smartPowerModeEnable completion:(ESTSettingPowerSmartPowerModeEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param smartPowerModeEnable SmartPowerModeEnable value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)smartPowerModeEnable;

@end

NS_ASSUME_NONNULL_END
