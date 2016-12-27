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

@class ESTSettingSensorsMotionNotificationEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting MotionNotificationEnable operation for Sensors packet.
 *
 *  @param enabledSetting MotionNotificationEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingSensorsMotionNotificationEnableCompletionBlock)(ESTSettingSensorsMotionNotificationEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingSensorsMotionNotificationEnable represents Sensors MotionNotificationEnable value, AKA MotionDetectionEnable.
 */
@interface ESTSettingSensorsMotionNotificationEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingSensorsMotionNotificationEnable validationErrorForValue:]
 *
 *  @param enabled Sensors MotionNotificationEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of Sensors MotionNotificationEnable setting.
 *
 *  @return Sensors MotionNotificationEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Sensors MotionNotificationEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingSensorsMotionNotificationEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Sensors MotionNotificationEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled MotionNotificationEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingSensorsMotionNotificationEnableCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enabled MotionNotificationEnable value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
