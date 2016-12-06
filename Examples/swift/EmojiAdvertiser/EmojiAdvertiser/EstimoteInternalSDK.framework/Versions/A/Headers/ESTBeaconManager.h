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
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconManagerDelegate.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

#define ESTIMOTE_PROXIMITY_UUID             [[NSUUID alloc] initWithUUIDString:@"B9407F30-F5F8-466E-AFF9-25556B57FE6D"]
#define ESTIMOTE_MACBEACON_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"08D4A950-80F0-4D42-A14B-D53E063516E6"]
#define ESTIMOTE_IOSBEACON_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"8492E75F-4FD6-469D-B132-043FE94921D8"]

#define ESTBeaconManagerErrorDomain @"ESTBeaconManagerErrorDomain"

typedef NS_ENUM(NSInteger, ESTBeaconManagerError)
{
    ESTBeaconManagerErrorInvalidRegion = 1,
    ESTBeaconManagerErrorLocationServicesUnauthorized
};

@interface ESTBeaconManager : NSObject

/**
 * The delegate object to receive update events.
 *
 * @see ESTBeaconManagerDelegate
 */
@property (nonatomic, weak) id <ESTBeaconManagerDelegate> _Nullable delegate;

#pragma mark iBeacon utilities
///--------------------------------------------------------------------
/// @name iBeacon utilities
///--------------------------------------------------------------------

/**
 * When `proximity` of a ranged beacon is `CLProximityUnknown`, iOS reports certain properties such as `rssi` or `distance` as unknown too. This property enables you to retain last known attributes of the beacon for a certain amount of time after its proximity changes to `CLProximityUnknown`.
 *
 * The value of this property reflects the number of ranging events which reported the beacon in the `CLProximityUnknown` state required to reset its attributes. By default this is 1, which means a single ranging event is enough to reset the beacon's attributes - resulting in immediate refreshes of all the `CLProximityUnknown` beacons. If you set it to e.g. 3, then 3 consecutive ranging events reporting the beacon as `CLProximityUnknown` are required to drop its last known attributes.
 *
 * You can use this property to improve ranging stability when your beacons are often reported as `CLProximityUnknown`, e.g. due to high advertising intervals.
 */
@property (nonatomic) NSInteger preventUnknownUpdateCount;


/**
 * When set to YES, ranging will skip all the beacons with `proximity` equal to `CLProximityUnknown`.
 */
@property (nonatomic) BOOL avoidUnknownStateBeacons;

/**
 * When ranging multiple regions, setting this to YES will result in a single `<[ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:]>` invocation reporting all the beacons ranged in all the regions for which ranging was started. In such case, the `inRegion` parameter will be `nil`, as ranging result does not represent a single region, but all the ranged regions instead.
 */
@property (nonatomic) BOOL returnAllRangedBeaconsAtOnce;

/**
 * Sets the limit (500 by default) of beacons to be delivered to the `<[ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:]>` delegate method.
 *
 * @param limit number of beacons that should be returned
 */
- (void)updateRangeLimit:(NSInteger)limit;


#pragma mark Advertising as iBeacon
///--------------------------------------------------------------------
/// @name Advertising as iBeacon
///--------------------------------------------------------------------

/**
 * Start advertising the iOS device as a iBeacon.
 *
 * @param proximityUUID The `proximityUUID` to advertise.
 * @param major The `major` to advertise.
 * @param minor The `minor` to advertise.
 * @param identifier The identifier of the region used to advertise.
 */
- (void)startAdvertisingWithProximityUUID:(NSUUID *)proximityUUID
                                    major:(CLBeaconMajorValue)major
                                    minor:(CLBeaconMinorValue)minor
                               identifier:(NSString *)identifier;

- (void)stopAdvertising;

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

/**
 * Checks if the current Location Services authorization is enough to do ranging (i.e., either 'when in use' or 'always').
 */
- (BOOL)isAuthorizedForRanging;

/**
 * Checks if the current Location Services authorization is enough to do monitoring (i.e., 'always').
 */
- (BOOL)isAuthorizedForMonitoring;


#pragma mark CoreLocation Based Scanning
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
 * @see stopMonitoringForAllRegions
 */
- (void)startMonitoringForRegion:(CLBeaconRegion *)region;

/**
 * Stops monitoring the specified region.
 *
 * If the specified region object is not currently being monitored, this method has no effect.
 *
 * @param region The region object currently being monitored. This parameter must not be `nil`. The object you specify need not be the exact same object that you registered but its beacon region attributes should be the same.
 *
 * @see startMonitoringForRegion:
 * @see stopMonitoringForAllRegions
 */
- (void)stopMonitoringForRegion:(CLBeaconRegion *)region;

/**
 * Stops monitoring all monitored regions.
 *
 * @see startMonitoringForRegion:
 * @see stopMonitoringForRegion:
 */
- (void)stopMonitoringForAllRegions;

/**
 * Starts the delivery of notifications for beacons in the specified region.
 *
 * Once registered, the beacon manager reports any encountered beacons to its delegate by calling the `<[ESTBeaconManagerDelegate beaconManager:didRangeBeacons:inRegion:]>` method. If there is an error registering the specified beacon region, the beacon manager calls its delegate's `<[ESTBeaconManagerDelegate beaconManager:rangingBeaconsDidFailForRegion:withError:]>` method and provides the appropriate error information.
 *
 * @param region The region object that defines the identifying information for the targeted beacons. The number of beacons represented by this region object depends on which identifier values you use to initialize it. Beacons must match all of the identifiers you specify. This method copies the region information it needs from the object you provide. If `nil`, defaults to targeting all beacons with `proximityUUID` equal to `ESTIMOTE_PROXIMITY_UUID`.
 *
 * @see stopRangingBeaconsInRegion:
 * @see stopRangingBeaconsInAllRegions
 */
- (void)startRangingBeaconsInRegion:(CLBeaconRegion *)region;

/**
 * Stops the delivery of notifications for the specified beacon region.
 *
 * @param region The region that identifies the beacons. The object you specify need not be the exact same object that you registered but its beacon region attributes should be the same. If `nil`, defaults to targeting all beacons with `proximityUUID` equal to `ESTIMOTE_PROXIMITY_UUID`.
 *
 * @see startRangingBeaconsInRegion:
 * @see stopRangingBeaconsInAllRegions
 */
- (void)stopRangingBeaconsInRegion:(CLBeaconRegion *)region;

/**
 * Stops the delivery of notifications for all ranged beacon regions.
 *
 * @see startRangingBeaconsInRegion:
 * @see stopRangingBeaconsInRegion:
 */
- (void)stopRangingBeaconsInAllRegions;

/**
 * Retrieves the state of a region.
 *
 * This method performs the request asynchronously and delivers the results to the beacon manager's `<delegate>`. You must implement the `<[ESTBeaconManagerDelegate beaconManager:didDetermineState:forRegion:]>` method in the `delegate` to receive the results.
 *
 * @param region The region whose state you want to know.
 */
- (void)requestStateForRegion:(CLBeaconRegion *)region;

/**
 * The set of shared beacon regions monitored by all beacon and location manager objects. (read-only)
 */
@property (readonly, nonatomic, copy) NSSet *monitoredRegions;

/**
 * The set of beacon regions currently being tracked using ranging. (read-only)
 */
@property (readonly, nonatomic, copy) NSSet *rangedRegions;

#pragma mark Estimote Motion UUID support
///--------------------------------------------------------------------
/// @name Estimote Motion UUID support
///--------------------------------------------------------------------

/**
 *  Returns Motion Proximity UUID identifier related to Proximity UUID returned by param.
 *  Motion Proximity UUID is created by reversing first bit of corresponding Proximity UUID.
 *
 *  @param proximityUUID corresponding Proximity UUID
 *
 *  @return calculated Motion Proximity UUID
 */
+ (NSUUID *)motionProximityUUIDForProximityUUID:(NSUUID *)proximityUUID;

@end

NS_ASSUME_NONNULL_END
