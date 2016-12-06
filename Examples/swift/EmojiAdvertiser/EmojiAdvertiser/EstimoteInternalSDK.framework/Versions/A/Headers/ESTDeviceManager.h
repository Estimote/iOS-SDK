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
#import "ESTDeviceLocationBeacon.h"
#import "ESTDeviceNearable.h"
#import "ESTTelemetryNotificationProtocol.h"


NS_ASSUME_NONNULL_BEGIN


@class ESTDeviceManager;

@protocol ESTDeviceManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that one or more Estimote devices were discovered in the vicinity of the iOS device.
 * Actual class of objects depend on filter used to start the manager.
 *
 * @param manager The utility manager object reporting the event.
 * @param beacons An array of ESTDevice subclass objects representing the discovered devices.
 *
 * @see ESTDeviceFilterIBeacon, ESTDeviceFilterTypeUtility.
 */
- (void)deviceManager:(ESTDeviceManager *)manager
    didDiscoverDevices:(NSArray<ESTDevice *> *)devices;

/**
 * Tells the delegate that a discovery error occurred.
 *
 * @param manager The utility manager object reporting the event.
 */
- (void)deviceManagerDidFailDiscovery:(ESTDeviceManager *)manager;

@end

@protocol ESTDeviceFilter;

/**
 * The `ESTDeviceManager` class defines the interface for utility methods related to Estimote devices. 
 * The main functionality allows to discover CoreBluetooth based representation of Estimote Beacon devices.
 *
 * One device manager instance can discover devices only with one filter at a time.
 */

@interface ESTDeviceManager : NSObject

/**
 *  Informs if a filtered or telemetry scan is in progress.
 */
@property (nonatomic, assign, readonly) BOOL isScanning;

/**
 *  Delegate to be informed about scan results every 1 sec.
 */
@property (nonatomic, weak) id<ESTDeviceManagerDelegate> delegate;

/**
 *  Start discovering Estimote devices determined by the filter, using CoreBluetooth. 
 *  One filter can be active per a ESTDeviceManager instance.
 *  If called multiple times only the last provided filter is active.
 *
 *  Causes the delegate to be called with -[ESTDeviceManagerDelegate deviceManager:didDiscoverDevices:] every 1 sec.
 *
 *  @param filter Object conforming to ESTDeviceFilter protocol. Should be
 */
- (void)startDeviceDiscoveryWithFilter:(id<ESTDeviceFilter>)filter;

/**
 *  Stops Estimote device discovery.
 */
- (void)stopDeviceDiscovery;

/**
 *  Use this method to register objects that implement
 *  ESTTelemetryNotificationProtocol to receive updates
 *  about specific telemetry notifications.
 *
 *  @param infos Array of objects conforming to ESTTelemetryNotificationProtocol.
 */
- (void)registerForTelemetryNotifications:(NSArray <ESTTelemetryNotificationProtocol> *)infos;

/**
 *  Use this method to register object that implements
 *  ESTTelemetryNotificationProtocol to receive updates
 *  about specific telemetry notifications.
 *
 *  @param infos Single object conforming to ESTTelemetryNotificationProtocol.
 */
- (void)registerForTelemetryNotification:(id <ESTTelemetryNotificationProtocol>)info;

/**
 *  Use this method to unregister object that implements
 *  ESTTelemetryNotificationProtocol from receiving updates
 *  about specific telemetry notifications.
 *
 *  @param infos Single object conforming to ESTTelemetryNotificationProtocol.
 */
- (void)unregisterForTelemetryNotification:(id <ESTTelemetryNotificationProtocol>)info;


@end

NS_ASSUME_NONNULL_END
