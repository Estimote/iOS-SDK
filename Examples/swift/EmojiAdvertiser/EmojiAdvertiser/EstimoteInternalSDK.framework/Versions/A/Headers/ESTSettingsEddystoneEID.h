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

NS_ASSUME_NONNULL_BEGIN

@class ESTSettingEddystoneEIDEnable, ESTSettingEddystoneEIDPower, ESTSettingEddystoneEIDInterval, ESTDeviceSettingsCollection;

/**
 *  ESTSettingsEddystoneEID represents group of settings realted to Eddystone EID packet.
 */
@interface ESTSettingsEddystoneEID : NSObject

/**
 *  Eddystone EID enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneEIDEnable *enable;

/**
 *  Eddystone EID advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneEIDInterval *interval;

/**
 *  Eddystone EID broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneEIDPower *power;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing Eddystone EID related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
