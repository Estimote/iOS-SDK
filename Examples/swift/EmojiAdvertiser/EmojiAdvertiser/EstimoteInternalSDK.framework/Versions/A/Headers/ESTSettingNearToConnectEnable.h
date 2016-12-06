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

#define ESTSettingNearToConnectEnableErrorDomain @"ESTSettingNearToConnectEnableErrorDomain"

@class ESTSettingNearToConnectEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting NearToConnectEnable operation for Power packet.
 *
 *  @param nearToConnectEnableSetting NearToConnectEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingNearToConnectEnableCompletionBlock)(ESTSettingNearToConnectEnable * _Nullable nearToConnectEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingNearToConnectEnable represents Power NearToConnectEnable value.
 */
@interface ESTSettingNearToConnectEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param nearToConnectEnable Power NearToConnectEnable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)nearToConnectEnable;

/**
 *  Returns current value of Power NearToConnectEnable setting.
 *
 *  @return Power NearToConnectEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Power NearToConnectEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingNearToConnectEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power NearToConnectEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param nearToConnectEnable NearToConnectEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)nearToConnectEnable completion:(ESTSettingNearToConnectEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
