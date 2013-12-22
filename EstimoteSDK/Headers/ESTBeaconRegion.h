//
//  ESTBeaconRegion.h
//  EstimoteSDK
//
//  Version : 1.2.0
//  Created by Marcin Klimek on 9/21/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*
 *  ESTBeaconMajorValue
 *
 *  Discussion:
 *    Type represents the most significant value in a beacon.
 *
 */
typedef uint16_t ESTBeaconMajorValue;

/*
 *  ESTBeaconMinorValue
 *
 *  Discussion:
 *    Type represents the least significant value in a beacon.
 *
 */
typedef uint16_t ESTBeaconMinorValue;


/**
 
 A ESTBeaconRegion object defines a type of region that is based on the device’s proximity to a Bluetooth beacon, as opposed to a geographic location. A beacon region looks for devices whose identifying information matches the information you provide. When that device comes in range, the region triggers the delivery of an appropriate notification.
 
 You can monitor beacon regions in two ways. To receive notifications when a device enters or exits the vicinity of a beacon, use the startMonitoringForRegion: method of your location manager object. While a beacon is in range, you can also call the startRangingBeaconsInRegion: method to begin receiving notifications when the relative distance to the beacon changes.
 
 ESTBeaconRegion extends basic CLBeaconRegion Core Location object, allowing to directly initialize region that is supported by Estimote Cloud platform.
 
 */
@interface ESTBeaconRegion : CLBeaconRegion

/**
 * Initialize a Estimote beacon region. Major and minor values will be wildcarded.
 *
 * @param identifier Region identifier
 * @return Initialized ESTBeaconRegion object
 **/
- (id)initRegionWithIdentifier:(NSString *)identifier;

/**
 * Initialize a Estimote beacon region with major value. Minor value will be wildcarded.
 *
 * @param major minor location value
 * @param identifier Region identifier
 * @return Initialized ESTBeaconRegion object
 **/
- (id)initRegionWithMajor:(ESTBeaconMajorValue)major identifier:(NSString *)identifier;

/**
 * Initialize a Estimote beacon region identified by a major and minor values.
 *
 * @param major minor location value
 * @param minor minor location value
 * @param identifier Region identifier
 * @return Initialized ESTBeaconRegion object
 **/
- (id)initRegionWithMajor:(ESTBeaconMajorValue)major minor:(ESTBeaconMinorValue)minor identifier:(NSString *)identifier;

@end
