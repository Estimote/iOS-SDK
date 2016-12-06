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

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSecureBeacon represents single Estimote Beacon broadcasting iBeacon packet with Secure UUID feature enabled.
 *  Provided Proximity UUID, Major and Minor values represent actual beacon values, not randomised ones. `ESTSecureBeacon`
 *  should not be created manually. Objects of this class are returning from `ESTSecureBeaconManager` class during ranging.
 */
@interface ESTBeacon : NSObject <NSCopying, NSSecureCoding>

/**
 *  proximityUUID
 *
 *  Discussion:
 *    Proximity identifier associated with the beacon.
 *
 */
@property (readonly, nonatomic, strong) NSUUID *proximityUUID;

/**
 *  major
 *
 *  Discussion:
 *    Most significant value associated with the beacon.
 *
 */
@property (readonly, nonatomic, strong) NSNumber *major;

/**
 *  minor
 *
 *  Discussion:
 *    Least significant value associated with the beacon.
 *
 */
@property (readonly, nonatomic, strong) NSNumber *minor;

/**
 *  proximity
 *
 *  Discussion:
 *    Proximity of the beacon from the device.
 *
 */
@property (readonly, nonatomic) CLProximity proximity;

/**
 *  accuracy
 *
 *  Discussion:
 *    Represents an one sigma horizontal accuracy in meters where the measuring device's location is
 *    referenced at the beaconing device. This value is heavily subject to variations in an RF environment.
 *    A negative accuracy value indicates the proximity is unknown.
 *
 */
@property (readonly, nonatomic) CLLocationAccuracy accuracy;

/**
 *  rssi
 *
 *  Discussion:
 *    Received signal strength in decibels of the specified beacon.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (readonly, nonatomic) NSInteger rssi;

/**
 *  Returns Initialized object of ESTSecureBeacon class.
 *
 *  @param proximityUUID corresponding Proximity UUID
 *  @param major corresponding Major
 *  @param minor corresponding Minor
 *  @param proximity corresponding proximity
 *  @param accuracy corresponding accuracy
 *  @param rssi corresponding rssi;
 *
 *  @return Initialized ESTSecureBeacon object.
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                            proximity:(CLProximity)proximity
                             accuracy:(CLLocationAccuracy)accuracy
                                 rssi:(NSInteger)rssi;

@end

NS_ASSUME_NONNULL_END
