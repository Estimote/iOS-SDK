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

#import <CoreLocation/CoreLocation.h>
#import "ESTSecureBeaconManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTSecureBeaconManager : NSObject

/**
 * The delegate object to receive update events.
 *
 * @see ESTBeaconManagerDelegate
 */
@property (nonatomic, weak) id <ESTSecureBeaconManagerDelegate> _Nullable delegate;

#pragma mark CoreLocation Authorization (new in iOS 8)
///--------------------------------------------------------------------
/// @name CoreLocation Authorization (new in iOS 8)
///--------------------------------------------------------------------

/**
 * Returns the app's authorization status for using location services.
 *
 * For more details about the new location services authorization model please refer to the CoreLocation documentation.
 *
 * @see +[CLLocationManager authorizationStatus]
 *
 * @return A value indicating whether the app is authorized to use location services.
 */
+ (CLAuthorizationStatus)authorizationStatus;

/**
 * Requests permission to use location services while the app is in the foreground.
 *
 * "When in use" authorization is sufficient to use beacon ranging (`<startRangingBeaconsInRegion:>`) and monitoring (`<startMonitoringForRegion:>`) in the foreground, but is not enough to use monitoring in the background and will not relaunch a terminated app upon a monitoring event.
 *
 * For more details about the new location services authorization model please refer to the CoreLocation documentation.
 *
 * @see -[CLLocationManager requestWhenInUseAuthorization]
 */
- (void)requestWhenInUseAuthorization;

/**
 * Requests permission to use location services whenever the app is running.
 *
 * "Always" authorization is required to use beacon monitoring (`<startMonitoringForRegion:>`) in the background and to relaunch a terminated app upon a monitoring event.
 *
 * For more details about the new location services authorization model please refer to the CoreLocation documentation.
 *
 * @see -[CLLocationManager requestWhenInUseAuthorization]
 */
- (void)requestAlwaysAuthorization;


#pragma mark CoreLocation
///--------------------------------------------------------------------
/// @name CoreLocation Based Scanning
///--------------------------------------------------------------------

/**
 * Starts monitoring the specified region.
 *
 * If an existing region with the same identifier is already being monitored by the application, the old region is replaced by the new one. The regions you add using this method are shared by all beacon and location manager objects in your application.
 *
 * Region events are delivered to the `<[ESTBeaconManagerDelegate beaconManager:didEnterRegion:]>` and `<[ESTBeaconManagerDelegate beaconManager:didExitRegion:]>` methods of your `<delegate>`. If there is an error, the beacon manager calls the `<[ESTBeaconManagerDelegate beaconManager:monitoringDidFailForRegion:withError:]>` method of your `delegate` instead.
 *
 * @param region The region object that defines the boundary to monitor. This parameter must not be `nil.`
 *
 * @see stopMonitoringForRegion:
 */
- (void)startMonitoringForRegion:(CLBeaconRegion *)region;

/**
 * Stops monitoring the specified secured region.
 *
 * If the specified region object is not currently being monitored, this method has no effect.
 *
 * @param region The region object currently being monitored. This parameter must not be `nil`. The object you specify need not be the exact same object that you registered but its beacon region attributes should be the same.
 *
 * @see startMonitoringForRegion:
 */
- (void)stopMonitoringForRegion:(CLBeaconRegion *)region;

/**
 * Starts the delivery of notifications for beacons in the specified secured region.
 *
 * Once registered, the beacon manager reports any encountered beacons to its delegate by calling the `<[ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:]>` method. If there is an error registering the specified beacon region, the beacon manager calls its delegate's `<[ESTBeaconManagerDelegate beaconManager:rangingBeaconsDidFailForRegion:withError:]>` method and provides the appropriate error information.
 *
 * @param region The region object that defines the identifying information for the targeted beacons. The number of beacons represented by this region object depends on which identifier values you use to initialize it. Beacons must match all of the identifiers you specify. This method copies the region information it needs from the object you provide. If `nil`, defaults to targeting all beacons with `proximityUUID` equal to `ESTIMOTE_PROXIMITY_UUID`.
 *
 * @see stopRangingBeaconsInRegion:
 */
- (void)startRangingBeaconsInRegion:(CLBeaconRegion *)region;

/**
 * Stops the delivery of notifications for the specified secured beacon region.
 *
 * @param region The region that identifies the beacons. The object you specify need not be the exact same object that you registered but its beacon region attributes should be the same. If `nil`, defaults to targeting all beacons with `proximityUUID` equal to `ESTIMOTE_PROXIMITY_UUID`.
 *
 * @see startRangingBeaconsInRegion:
 */
- (void)stopRangingBeaconsInRegion:(CLBeaconRegion *)region;

/**
 * Retrieves the state of a region.
 *
 * This method performs the request asynchronously and delivers the results to the beacon manager's `<delegate>`. You must implement the `<[ESTBeaconManagerDelegate beaconManager:didDetermineState:forRegion:]>` method in the `delegate` to receive the results.
 *
 * @param region The region whose state you want to know.
 */
- (void)requestStateForRegion:(CLBeaconRegion *)region;

/**
 * The set of shared beacon regions monitored by this beacon manager object. (read-only)
 */
@property (readonly, nonatomic, copy) NSSet *monitoredRegions;

/**
 * The set of beacon regions currently being tracked using ranging. (read-only)
 */
@property (readonly, nonatomic, copy) NSSet *rangedRegions;

@end

NS_ASSUME_NONNULL_END
