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
@class ESTSettingLinkNetworkPower;
@class ESTSettingLinkNetworkEnabled;
@class ESTSettingLinkNetworkInterval;
@class ESTDeviceSettingsCollection;

@interface ESTSettingsLinkNetwork : NSObject

/**
 *  Link Network packet enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingLinkNetworkEnabled *enabled;

/**
 *  Link Network broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingLinkNetworkPower *power;

/**
 *  Link Network advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingLinkNetworkInterval *interval;

/**
 *  Designated initializer
 *
 *  @param settingsCollection Collection of settings containing Link Network related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end
