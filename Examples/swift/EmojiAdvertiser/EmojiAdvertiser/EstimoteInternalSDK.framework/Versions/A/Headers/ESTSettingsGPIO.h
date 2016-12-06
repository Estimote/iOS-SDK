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

@class ESTSettingGPIONotificationEnable;
@class ESTSettingGPIOConfigPort0;
@class ESTSettingGPIOConfigPort1;
@class ESTSettingGPIOPortsData;
@class ESTDeviceSettingsCollection;


/**
 *  ESTSettingsGPIO represents group of settings related to GPIO features.
 */
@interface ESTSettingsGPIO : NSObject

/**
 *  GPIO Interrupt feature enable setting.
 */
@property (nonatomic, strong, readonly) ESTSettingGPIONotificationEnable *notificationEnable;

/**
 *  GPIO Config setting for Port 0.
 */
@property (nonatomic, strong, readonly) ESTSettingGPIOConfigPort0 *configPort0;

/**
 *  GPIO Config setting for Port 1.
 */
@property (nonatomic, strong, readonly) ESTSettingGPIOConfigPort1 *configPort1;

/**
 *  Current GPIO ports state.
 */
@property (nonatomic, strong, readonly) ESTSettingGPIOPortsData *portsData;

/**
 *  Designated initializer
 *
 *  @param settingsCollection Collection of settings containing GPIO related settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsCollection:(ESTDeviceSettingsCollection *)settingsCollection;

@end

NS_ASSUME_NONNULL_END
