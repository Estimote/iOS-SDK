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

@class ESTSettingEddystoneUIDEnable, ESTSettingEddystoneUIDNamespace, ESTSettingEddystoneUIDInstance,
       ESTSettingEddystoneUIDInterval, ESTSettingEddystoneUIDPower, ESTDeviceSettingsCollection;


/**
 *  ESTSettingsEddystoneUID represents group of settings related to Eddystone UID packet.
 */
@interface ESTSettingsEddystoneUID : NSObject

/**
 *  Eddystone UID enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneUIDEnable *enable;

/**
 *  Eddystone UID Namespace setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneUIDNamespace *namespaceID;

/**
 *  Eddystone UID instance setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneUIDInstance *instanceID;

/**
 *  Eddystone UID advertising interval setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneUIDInterval *interval;

/**
 *  Eddystone UID broadcasting power setting.
 */
@property (nonatomic, strong, readonly) ESTSettingEddystoneUIDPower *power;

/**
 *  Designated initializer.
 *
 *  @param settingsCollection Collection of settings containing Eddystone UID related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
