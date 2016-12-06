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

NS_ASSUME_NONNULL_BEGIN

@class ESTBeaconManager;

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

#pragma mark Authorization Change Events (new in iOS 8)
///--------------------------------------------------------------------
/// @name Authorization Change Events (new in iOS 8)
///--------------------------------------------------------------------

/**
 * Tells the delegate that the authorization status for the application changed.
 *
 * This method is called whenever the application's ability to use location services changes. Changes can occur because the user allowed or denied the use of location services for your application or for the system as a whole.
 *
 * If the authorization status is already known when you call the `requestWhenInUseAuthorization` or `requestAlwaysAuthorization` method, the beacon manager does not report the current authorization status to this method. The beacon manager only reports changes to the authorization status. For example, it calls this method when the status changes from `kCLAuthorizationStatusNotDetermined` to `kCLAuthorizationStatusAuthorizedWhenInUse`.
 */
- (void)beaconManager:(id)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

#pragma mark Monitoring Events
///--------------------------------------------------------------------
/// @name Monitoring Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that a new region is being monitored.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that is being monitored.
 */

- (void)beaconManager:(id)manager
didStartMonitoringForRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate that a region monitoring error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region for which the error occurred.
 * @param error An error object describing why monitoring failed.
 */
- (void)beaconManager:(id)manager
monitoringDidFailForRegion:(CLBeaconRegion * _Nullable)region
            withError:(NSError *)error;

/**
 * Tells the delegate that the user entered the specified region.
 *
 * Because regions are a shared application resource, every active beacon and location manager object delivers this message to its associated delegate. It does not matter which beacon or location manager actually registered the specified region. And if multiple beacon and location managers share a delegate object, that delegate receives the message multiple times.
 *
 *The region object provided may not be the same one that was registered. As a result, you should never perform pointer-level comparisons to determine equality. Instead, use the region's identifier string to determine if your delegate should respond.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that was entered.
 */
- (void)beaconManager:(id)manager
       didEnterRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate that the user left the specified region.
 *
 * Because regions are a shared application resource, every active beacon and location manager object delivers this message to its associated delegate. It does not matter which beacon or location manager actually registered the specified region. And if multiple beacon and location managers share a delegate object, that delegate receives the message multiple times.
 *
 *The region object provided may not be the same one that was registered. As a result, you should never perform pointer-level comparisons to determine equality. Instead, use the region's identifier string to determine if your delegate should respond.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that was exited.
 */
- (void)beaconManager:(id)manager
        didExitRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate about the state of the specified region.
 *
 * The beacon manager calls this method whenever there is a boundary transition for a region. It calls this method in addition to calling the `<beaconManager:didEnterRegion:>` and `<beaconManager:didExitRegion:>` methods. The beacon manager also calls this method in response to a call to its `<[ESTBeaconManager requestStateForRegion:]>` method, which runs asynchronously.
 *
 * @param manager The beacon manager object reporting the event.
 * @param state The state of the specified region: `CLRegionStateUnknown`, `CLRegionStateInside` or `CLRegionStateOutside`.
 * @param region The region which state was determined.
 */
- (void)beaconManager:(id)manager
    didDetermineState:(CLRegionState)state
            forRegion:(CLBeaconRegion *)region;

#pragma mark Ranging Events
///--------------------------------------------------------------------
/// @name Ranging Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that one or more beacons are in range.
 *
 * @param manager The beacon manager object reporting the event.
 * @param beacons An array of `<CLBeacon>` objects representing the beacons currently in range. You can use the information in these objects to determine the range of each beacon and its identifying information.
 * @param region The region that was used to range the beacons.
 */
- (void)beaconManager:(id)manager
      didRangeBeacons:(NSArray<CLBeacon *> *)beacons
             inRegion:(CLBeaconRegion *)region;


/**
 * Tells the delegate that a region ranging error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region for which the error occurred.
 * @param error An error object describing why ranging failed.
 */
- (void)beaconManager:(id)manager
rangingBeaconsDidFailForRegion:(CLBeaconRegion * _Nullable)region
            withError:(NSError *)error;

#pragma mark Advertising Events
///--------------------------------------------------------------------
/// @name Advertising Events
///--------------------------------------------------------------------

/**
 * Tells the delegate the the device started advertising as an iBeacon.
 *
 * @param manager The beacon manager object reporting the event.
 * @param error If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)beaconManagerDidStartAdvertising:(id)manager
                                   error:(NSError * _Nullable)error;

#pragma mark General Events
///--------------------------------------------------------------------
/// @name General Events
///--------------------------------------------------------------------

/**
 * The beacon manager calls this method when it encounters an error trying to get the beacons data. If the user denies your application’s use of the location service, this method reports a kCLErrorDenied error. Upon receiving such an error, you should stop the location service. This method is forwarding locationManager:didFailWithError: method of CLLocationManager.
 *
 * @param manager The beacon manager object reporting the event.
 * @param error If an error occurred, this error object describes the error.
 */
- (void)beaconManager:(id)manager didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
