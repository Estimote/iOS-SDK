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

@class ESTSettingEddystoneURLEnable, ESTSettingEddystoneURLInterval, ESTSettingEddystoneURLPower,
       ESTSettingEddystoneURLData, ESTDeviceSettingsCollection;


/**
 *  ESTSettingsEddystoneURL represents group of settings related to Eddystone URL packet.
 */
@interface ESTSettingsEddystoneURL : NSObject

/**
 *  Eddystone URL enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneURLEnable *enable;

/**
 *  Eddystone URL advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneURLInterval *interval;

/**
 *  Eddystone URL broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneURLPower *power;

/**
 *  Eddystone URL data setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneURLData *URLData;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing Eddystone URL related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
