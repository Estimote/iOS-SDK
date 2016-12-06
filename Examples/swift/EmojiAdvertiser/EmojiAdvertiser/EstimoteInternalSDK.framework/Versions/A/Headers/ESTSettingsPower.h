//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

@class ESTDeviceSettingsCollection;
@class ESTSettingPowerSmartPowerModeEnable;
@class ESTSettingPowerFlipToSleepEnable;
@class ESTSettingPowerDarkToSleepEnable;
@class ESTSettingPowerDarkToSleepThreshold;
@class ESTSettingPowerBatteryLifetime;
@class ESTSettingPowerMotionOnlyBroadcastingEnable;
@class ESTSettingPowerMotionOnlyBroadcastingDelay;
@class ESTSettingPowerScheduledAdvertisingEnable;
@class ESTSettingPowerScheduledAdvertisingPeriod;
@class ESTSettingPowerBatteryPercentage;
@class ESTSettingPowerBatteryVoltage;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingsPower represents group of settings related to power management.
 */
@interface ESTSettingsPower : NSObject

/**
 *  Battery percentage setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerBatteryPercentage *batteryPercentage;

/**
 *  Battery voltage measured in millivolts.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerBatteryVoltage *batteryVoltage;

/**
 *  Battery lifetime setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerBatteryLifetime *batteryLifetime;

/**
 *  Flip to sleep enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerFlipToSleepEnable *flipToSleepEnable;

/**
 *  Smart Power Mode enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerSmartPowerModeEnable *smartPowerModeEnable;

/**
 *  Dark To Sleep enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerDarkToSleepEnable *darkToSleepEnable;

/**
 *  Dark To Sleep threshold setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerDarkToSleepThreshold *darkToSleepThreshold;

/**
 *  Motion Only Broadcasting enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerMotionOnlyBroadcastingEnable *motionOnlyBroadcastingEnable;

/**
 *  Motion Only Broadcasting delay - time in milliseconds when device stops broadcasting since last movement.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerMotionOnlyBroadcastingDelay *motionOnlyBroadcastingDelay;

/**
 *  Scheduled advertising enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerScheduledAdvertisingEnable *scheduledAdvertisingEnable;

/**
 *  Scheduled advertising period setting.
 */
@property (nonatomic, strong, readonly) ESTSettingPowerScheduledAdvertisingPeriod *scheduledAdvertisingPeriod;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing power related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
