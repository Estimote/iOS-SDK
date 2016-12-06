//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ESTSettingIBeaconMajor;
@class ESTSettingIBeaconEnable;
@class ESTSettingIBeaconMinor;
@class ESTSettingIBeaconProximityUUID;
@class ESTSettingIBeaconSecureUUIDPeriodScaler;
@class ESTSettingIBeaconSecureUUIDEnable;
@class ESTDeviceSettingsCollection;
@class ESTSettingIBeaconPower;
@class ESTSettingIBeaconInterval;
@class ESTSettingIBeaconNonStrictMode;
@class ESTSettingIBeaconMotionUUID;
@class ESTSettingIBeaconMotionUUIDEnable;


/**
 *  ESTSettingsIBeacon represents group of settings related to Apple iBeacon packet.
 */
@interface ESTSettingsIBeacon : NSObject

/**
 *  iBeacon enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconEnable *enable;

/**
 *  iBeacon power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconPower *power;

/**
 *  iBeacon interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconInterval *interval;

/**
 *  iBeacon Proximity UUID setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconProximityUUID *proximityUUID;

/**
 *  iBeacon Motion Proximity UUID Enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconMotionUUIDEnable *motionUUIDEnable;

/**
 *  iBeacon Motion Proximity UUID setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconMotionUUID *motionUUID;

/**
 *  iBeacon Major setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconMajor *major;

/**
 *  iBeacon Minor setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconMinor *minor;

/**
 *  iBeacon Secure UUID rotation period scaler. The rotation period is equal to 2^scaler seconds.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconSecureUUIDPeriodScaler *secureUUIDPeriodScaler;

/**
 *  iBeacon Secure UUID enabled setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconSecureUUIDEnable *secureUUIDEnable;

/**
 *  iBeacon Non Strict Mode enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingIBeaconNonStrictMode *nonStrictModeEnable;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing iBeacon related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
