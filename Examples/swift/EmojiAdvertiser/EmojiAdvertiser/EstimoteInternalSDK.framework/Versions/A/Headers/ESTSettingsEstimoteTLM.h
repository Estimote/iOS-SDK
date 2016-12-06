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
#import "ESTSettingEstimoteTLMEnable.h"
#import "ESTSettingEstimoteTLMInterval.h"
#import "ESTSettingEstimoteTLMPower.h"
#import "ESTDeviceSettingsCollection.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingsEstimoteTLM represents group of settings related to Estimote Telemetry packet.
 */
@interface ESTSettingsEstimoteTLM : NSObject

/**
 *  Estimote Telemetry enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteTLMEnable *enable;

/**
 *  Estimote Telemetry advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteTLMInterval *interval;

/**
 *  Estimote Telemetry broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEstimoteTLMPower *power;

/**
 *  Designated initializer
 *
 *  @param settingsCollection Collection of settings containing Estimote Telemetry related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
