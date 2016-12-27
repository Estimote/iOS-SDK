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
#import "ESTBluetoothBeacon.h"
#import "ESTDeviceNearable.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ESTUtilityManagerState)
{
    ESTUtilityManagerStateIdle,
    ESTUtilityManagerStateScanning
};

@class ESTUtilityManager;

@protocol ESTUtilityManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that one or more beacons were discovered in the vicinity of the device.
 *
 * @param manager The utility manager object reporting the event.
 * @param beacons An array of `<ESTBluetoothBeacon>` objects representing the beacons discovered.
 */
- (void)utilityManager:(ESTUtilityManager *)manager
    didDiscoverBeacons:(NSArray<ESTBluetoothBeacon *> *)beacons;

/**
 * Tells the delegate that one or more beacons were discovered in the vicinity of the device.
 *
 * @param manager The utility manager object reporting the event.
 * @param nearables An array of `<ESTDeviceNearable>` objects representing the nearables discovered.
 */
- (void)utilityManager:(ESTUtilityManager *)manager
    didDiscoverNearables:(NSArray<ESTDeviceNearable *> *)nearables;

/**
 * Tells the delegate that beacons discovery error occurred.
 *
 * @param manager The utility manager object reporting the event.
 */
- (void)utilityManagerDidFailDiscovery:(ESTUtilityManager *)manager;

@end

/**
 * The `ESTUtilityManager` class defines the interface for utility methods related to Estimote Beacons. The main functionality
 * allows to discover CoreBluetooth based representation of Estimote Beacon devices.
 */

@interface ESTUtilityManager : NSObject

 /**
 *  Current state of Utility manager
 */
@property (nonatomic, assign, readonly) ESTUtilityManagerState state;

/**
 *  Delegate object.
 */
@property (nonatomic, weak) id<ESTUtilityManagerDelegate> _Nullable delegate;

/**
 * Starts a CoreBluetooth scan in search for all Estimote Beacons in range.
 * Related `utilityManager:didDiscoverBeacons:` is fired every 0.2 sec until
 * stopEstimoteBeaconDiscovery method invocation.
 *
 */
- (void)startEstimoteBeaconDiscovery;

/**
 * Starts a CoreBluetooth scan in search for all Estimote Beacons in range.
 * Related `utilityManager:didDiscoverBeacons:` is fired until
 * stopEstimoteBeaconDiscovery method invocation. Delegate method interval
 * is provided as a method param.
 *
 *  @param interval Interval, in seconds, for updates from delegate method.
 */
- (void)startEstimoteBeaconDiscoveryWithUpdateInterval:(NSTimeInterval)interval;

/**
 * Stops the CoreBluetooth based beacon discovery.
 */
- (void)stopEstimoteBeaconDiscovery;

/**
 * Starts a CoreBluetooth scan in search for all Estimote Nearables in range.
 * Related `utilityManager:didDiscoverNearables:` is fired every 0.2 sec until
 * stopEstimoteNearablesDiscovery method invocation.
 *
 */
- (void)startEstimoteNearableDiscovery;

/**
 * Starts a CoreBluetooth scan in search for all Estimote Nearables in range.
 * Related `utilityManager:didDiscoverNearables:` is fired until
 * stopEstimoteNearablesDiscovery method invocation. Delegate method interval
 * is provided as a method param.
 *
 *  @param interval Interval, in seconds, for updates from delegate method.
 */
- (void)startEstimoteNearableDiscoveryWithUpdateInterval:(NSTimeInterval)interval;

/**
 * Stops the CoreBluetooth based nearables discovery.
 */
- (void)stopEstimoteNearableDiscovery;

@end

NS_ASSUME_NONNULL_END
