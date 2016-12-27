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
#import "ESTGPIOConfig.h"

@class ESTSettingGPIOConfigPort1;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting ConfigPort1 operation for GPIO packet.
 *
 *  @param configSetting ConfigPort1 setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingGPIOConfigPort1CompletionBlock)(ESTSettingGPIOConfigPort1 * _Nullable configSetting, NSError * _Nullable error);


/**
 *  ESTSettingGPIOConfigPort1 represents GPIO ConfigPort1 value.
 */
@interface ESTSettingGPIOConfigPort1 : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGPIOConfigPort1 validationErrorForValue:]
 *
 *  @param config GPIO ConfigPort1 value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (nullable instancetype)initWithValue:(ESTGPIOConfig)config;

/**
 *  Returns current value of GPIO ConfigPort1 setting.
 *
 *  @return GPIO ConfigPort1 value.
 */
- (ESTGPIOConfig)getValue;

/**
 *  Method allows to read value of initialized GPIO ConfigPort1 setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGPIOConfigPort1CompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GPIO ConfigPort1 setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param config ConfigPort1 value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTGPIOConfig)config completion:(ESTSettingGPIOConfigPort1CompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param config ConfigPort1 value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTGPIOConfig)config;

@end

NS_ASSUME_NONNULL_END
