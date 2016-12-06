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

@class ESTSettingPowerBatteryLifetime;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BatteryLifetime operation for Power packet.
 *
 *  @param batteryLifetime BatteryLifetime setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerBatteryLifetimeCompletionBlock)(ESTSettingPowerBatteryLifetime * _Nullable batteryLifetimeSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerBatteryLifetime represents Power BatteryLifetime value.
 */
@interface ESTSettingPowerBatteryLifetime : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param batteryLifetime Power BatteryLifetime value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSUInteger)batteryLifetime;

/**
 *  Returns current value of Power BatteryLifetime setting.
 *  Value is provided in days.
 *
 *  @return Power BatteryLifetime value in days.
 */
- (NSUInteger)getValue;

/**
 *  Method allows to read value of initialized Power BatteryLifetime setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingPowerBatteryLifetimeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
