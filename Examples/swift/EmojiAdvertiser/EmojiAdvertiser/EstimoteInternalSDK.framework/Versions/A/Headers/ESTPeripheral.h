//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTDeviceSettingProtocol.h"
#import "ESTDeviceNotificationProtocol.h"

typedef void(^ESTPeripheralDiscoveryCompletionBlock)(NSError *error);

typedef NS_ENUM(NSInteger, ESTPeripheralDiscoveryError)
{
    ESTPeripheralDiscoveryErrorNoServices = 1000,
    ESTPeripheralDiscoveryErrorServicesFailure = 1001,
    ESTPeripheralDiscoveryErrorCharacteristicsFailure = 1002
};


@protocol ESTPeripheral <NSObject>

@required

/**
 * Initialize device with provided CoreBluetooth CBPeripheral
 */
- (id)initWithPeripheral:(CBPeripheral *)peripheral;

/**
 * Discover bluetooth service and characteristics
 */
- (void)discoverServicesAndCharacteristicsWithCompletion:(ESTPeripheralDiscoveryCompletionBlock)completion;

@end

/**
 *  Protocol defining delegate responsible for handling device notification.
 */
@protocol ESTPeripheralNotificationDelegate <NSObject>

@required

/**
 *  Method invoked each time the peripheral receives a device notification, which it was subscribed to before.
 *
 *  @param peripheral   Device peripheral that received a notification.
 *  @param notification Notification instance, same that was used to register.
 *  @param data         Data to fire callback with.
 *
 *  @see -[ESTDeviceLocationBeacon registerNotification:].
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didReceiveNotification:(id<ESTDeviceNotificationProtocol>)notification withData:(NSData *)data;

@end
