//
//  ESTBeaconManager.h
//  EstimoteSDK
//
//  Version : 1.2.0
//  Created by Marcin Klimek on 9/18/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconRegion.h"
#import "ESTBeacon.h"

@class ESTBeaconManager;

/**
 
 The ESTBeaconManagerDelegate protocol defines the delegate methods to respond for related events.
 */

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

/**
 * Delegate method invoked during ranging.
 * Allows to retrieve NSArray of all discoverd beacons
 * represented with ESTBeacon objects.
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as ESTBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region;

/**
 * Delegate method invoked wehen ranging fails
 * for particular region. Related NSError object passed.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
rangingBeaconsDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;


/**
 * Delegate method invoked wehen monitoring fails
 * for particular region. Related NSError object passed.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
monitoringDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;
/**
 * Method triggered when iOS device enters estimote 
 * beacon region during monitoring.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
      didEnterRegion:(ESTBeaconRegion *)region;


/**
 * Method triggered when iOS device leaves estimote
 * beacon region during monitoring.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
       didExitRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when estimote beacon region state
 * was determined using requestStateForRegion:
 *
 * @param manager estimote beacon manager
 * @param state estimote beacon region state
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
     didDetermineState:(CLRegionState)state
             forRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when device starts advertising
 * as iBeacon.
 *
 * @param manager estimote beacon manager
 * @param error info about any error
 *
 * @return void
 */
-(void)beaconManagerDidStartAdvertising:(ESTBeaconManager *)manager
                                  error:(NSError *)error;

/**
 * Delegate method invoked to handle discovered
 * ESTBeacon objects using CoreBluetooth framework
 * in particular region.
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as ESTBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
          didDiscoverBeacons:(NSArray *)beacons
                    inRegion:(ESTBeaconRegion *)region;

/**
 * Delegate method invoked when CoreBluetooth based
 * discovery process fails.
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
    didFailDiscoveryInRegion:(ESTBeaconRegion *)region;

@end



/**
 
 The ESTBeaconManager class defines the interface for handling and configuring the estimote beacons and get related events to your application. You use an instance of this class to establish the parameters that describes each beacon behavior. You can also use a beacon manager object to retrieve all beacons in range.
 
 A beacon manager object provides support for the following location-related activities:
 
 * Monitoring distinct regions of interest and generating location events when the user enters or leaves those regions (works in background mode).
 * Reporting the range to nearby beacons and ther distance for the device.
 
 */

@interface ESTBeaconManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <ESTBeaconManagerDelegate> delegate;

/**
 Allows to avoid beacons with unknown state (proximity == 0), when ranging. Default value is NO.
 */
@property (nonatomic) BOOL avoidUnknownStateBeacons;

@property (nonatomic, strong) ESTBeaconRegion*         virtualBeaconRegion;


/// @name CoreLocation based iBeacon monitoring and ranging methods

/**
 * Range all Estimote beacons that are visible in range.
 * Delegate method beaconManager:didRangeBeacons:inRegion: 
 * is used to retrieve found beacons. Returned NSArray contains 
 * ESTBeacon objects.
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)startRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Start monitoring for particular region.
 * Functionality works in the background mode as well.
 * Every time you enter or leave region appropriet
 * delegate method inovked: beaconManager:didEnterRegtion:
 * and beaconManager:didExitRegion:
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)startMonitoringForRegion:(ESTBeaconRegion*)region;

/**
 * Stops ranging Estimote beacons.
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)stopRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * Unsubscribe application from iOS monitoring of
 * Estimote beacon region.
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)stopMonitoringForRegion:(ESTBeaconRegion *)region;

/**
 * Allows to validate current state for particular region
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)requestStateForRegion:(ESTBeaconRegion *)region;

/// @name Turning device into iBeacon

/**
 * Allows to turn device into virtual estimote beacon.
 *
 * @param major minor beacon value
 * @param minor major beacon value
 * @param identifier unique identifier for you region
 *
 * @return void
 */
-(void)startAdvertisingWithMajor:(ESTBeaconMajorValue)major
                       withMinor:(ESTBeaconMinorValue)minor
                  withIdentifier:(NSString*)identifier;


/**
 * Stop beacon advertising
 *
 * @return void
 */
-(void)stopAdvertising;


/// @name CoreBluetooth based utility methods


/**
 * Start beacon discovery process based on CoreBluetooth 
 * framework. Method is useful for older beacons discovery 
 * that are not advertising as iBeacons.
 *
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)startEstimoteBeaconsDiscoveryForRegion:(ESTBeaconRegion*)region;


/**
 * Stops CoreBluetooth based beacon discovery process.
 *
 * @return void
 */
-(void)stopEstimoteBeaconDiscovery;

@end

