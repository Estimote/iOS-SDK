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

#define ESTSettingShakeToConnectEnableErrorDomain @"ESTSettingShakeToConnectEnableErrorDomain"

@class ESTSettingShakeToConnectEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting ShakeToConnectEnable operation for Connectivity packet.
 *
 *  @param shakeToConnectEnableSetting ShakeToConnectEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingShakeToConnectEnableCompletionBlock)(ESTSettingShakeToConnectEnable * _Nullable shakeToConnectEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingShakeToConnectEnable represents Connectivity ShakeToConnectEnable value.
 */
@interface ESTSettingShakeToConnectEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @param shakeToConnectEnable Connectivity ShakeToConnectEnable value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(BOOL)shakeToConnectEnable;

/**
 *  Returns current value of Connectivity ShakeToConnectEnable setting.
 *
 *  @return shakeToConnect ShakeToConnectEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Connectivity ShakeToConnectEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingShakeToConnectEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Connectivity ShakeToConnectEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param shakeToConnectEnable ShakeToConnectEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)shakeToConnectEnable completion:(ESTSettingShakeToConnectEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
