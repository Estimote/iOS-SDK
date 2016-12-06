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

NS_ASSUME_NONNULL_BEGIN

/**
 *  Proximity zone where device was located.
 */
typedef NS_ENUM(NSInteger, ESTEddystoneProximity) {
    /**
     *  Unknown proximity zone.
     */
    ESTEddystoneProximityUnknown,
    /**
     *  Immediate proximity zone.
     */
    ESTEddystoneProximityImmediate,
    /**
     *  Near proximity zone.
     */
    ESTEddystoneProximityNear,
    /**
     *  Far proximity zone.
     */
    ESTEddystoneProximityFar
};


/**
 *  Object of this class represents single Eddystone device, with all its available properties.
 *  `ESTEddystone` object should not be created manually. Instances are created by ESTEddystoneManager
 *  with discovery process and return in `eddystoneManager:didDiscoverEddystones:withFilter:` delegate method.
 */
@interface ESTEddystone : NSObject <NSCopying>

/**
 *  MAC address of device advertising Eddystone packets.
 *  This property is filled only for eddystone packets
 *  broadcasted by proximity beacons (1st generation).
 */
@property (nonatomic, strong) NSString *macAddress;

/**
 *  Bluetooth peripheral identifier.
 */
@property (nonatomic, strong) NSUUID *peripheralIdentifier;

/**
 *  Signal strength detected on the phone (-100 to 0))
 */
@property (nonatomic, strong) NSNumber *rssi;

/**
 *  One sigma horizontal accuracy in meters.
 */
@property (nonatomic, strong) NSNumber *accuracy;

/**
 * Proximity zone of the device.
 */
@property (nonatomic) ESTEddystoneProximity proximity;

/**
 *  Last time device was seen.
 */
@property (nonatomic, strong) NSDate *discoveryDate;

/**
 *  Telemetry information delivered in separate packet packet every 10 seconds.
 */
@property (nonatomic, strong) NSNumber *measuredPower;

/**
 *  Internaly used method allows to update ESTEddystone object with another ESTEddystone object.
 *
 *  @param eddystone provided ESTEddystone object.
 */
- (void)updateWithEddystone:(ESTEddystone *)eddystone;

/**
 *  Equality method
 *
 *  @param eddystone Eddystone you want to compare with.
 *
 *  @return Bool value indicating equality.
 */
- (BOOL)isEqualToEddystone:(ESTEddystone *)eddystone;
@end

NS_ASSUME_NONNULL_END
