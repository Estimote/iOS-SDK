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

@class ESTSettingEstimoteLocationEnable, ESTSettingEstimoteLocationInterval, ESTSettingEstimoteLocationPower, ESTDeviceSettingsCollection;


/**
 *  ESTSettingsEstimoteLocation represents group of settings related to Estimote Location packet.
 */
@interface ESTSettingsEstimoteLocation : NSObject

/**
 *  Estimote enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteLocationEnable *enable;

/**
 *  Estimote advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteLocationInterval *interval;

/**
 *  Estimote broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteLocationPower *power;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing Estimote related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
