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

@class ESTSettingPowerBatteryPercentage;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BatteryPercentage operation for Power packet.
 *
 *  @param batteryPercentage BatteryPercentage setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerBatteryPercentageCompletionBlock)(ESTSettingPowerBatteryPercentage * _Nullable batteryPercentageSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerBatteryPercentage represents Power BatteryPercentage value.
 */
@interface ESTSettingPowerBatteryPercentage : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param batteryPercentage Power BatteryPercentage value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSUInteger)batteryPercentage;

/**
 *  Returns current value of Power BatteryPercentage setting.
 *
 *  @return Power BatteryPercentage value.
 */
- (NSUInteger)getValue;

/**
 *  Method allows to read value of initialized Power BatteryPercentage setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingPowerBatteryPercentageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
