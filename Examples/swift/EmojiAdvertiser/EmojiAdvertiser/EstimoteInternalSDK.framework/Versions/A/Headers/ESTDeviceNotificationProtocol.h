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


/**
 *  ESTDeviceNotificationProtocol has to be implemented by all notification
 *  classes to be compatible with Estimote device API.
 *
 *  A notification class can be registered with -[ESTBeaconSettingsManager registerNotification:].
 *  Then, its handler block is fired each time the device sents notification data.
 *  
 *  Note that the device has to be in connected state in order for notifications to work.
 */
@protocol ESTDeviceNotificationProtocol <NSObject>

@required

/**
 *  ID of register should be used to deliver value of the setting.
 *
 *  @return NSInteger value representing register ID
 */
- (uint16_t)registerID;

/**
 *  Method invoked when notification data is delivered from the device.
 *
 *  @param data NSData object representing value delivered
 */
- (void)fireHandlerWithData:(NSData *)data;

/**
 *  Lowest firmware version supporting notification.
 *
 *  @return Version of firmware.
 */
- (NSString *)supportedFirmwareVersion;

@end

NS_ASSUME_NONNULL_END
