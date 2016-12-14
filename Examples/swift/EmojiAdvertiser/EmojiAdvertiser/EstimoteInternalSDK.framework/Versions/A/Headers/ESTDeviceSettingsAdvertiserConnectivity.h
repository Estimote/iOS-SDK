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

#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTDeviceSettingsAdvertiserConnectivity
 */
@interface ESTDeviceSettingsAdvertiserConnectivity : ESTDeviceSettingsAdvertiser

/**
 *  Indicates if Shake To Configure mode is enabled;
 */
@property (nonatomic, readonly) NSNumber *shakeToConnectEnabled;

@end

NS_ASSUME_NONNULL_END
