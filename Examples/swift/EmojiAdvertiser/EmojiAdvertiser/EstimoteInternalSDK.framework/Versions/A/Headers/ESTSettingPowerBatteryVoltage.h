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

@class ESTSettingPowerBatteryVoltage;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BatteryVoltage operation for Power group.
 *
 *  @param voltage BatteryVoltage setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerBatteryVoltageCompletionBlock)(ESTSettingPowerBatteryVoltage * _Nullable voltageSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerBatteryVoltage represents Power BatteryVoltage value.
 */
@interface ESTSettingPowerBatteryVoltage : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param voltage Power BatteryVoltage value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(unsigned short)voltage;

/**
 *  Returns current value of BatteryVoltage setting.
 *
 *  @return Power BatteryVoltage value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized BatteryVoltage setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingPowerBatteryVoltageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
