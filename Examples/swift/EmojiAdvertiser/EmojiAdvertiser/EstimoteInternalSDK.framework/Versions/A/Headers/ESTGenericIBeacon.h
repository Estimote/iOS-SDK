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
 *  ESTGenericIBeacon represents iBeacon packet for Generic Advertiser.
 */
@interface ESTGenericIBeacon : NSObject

/**
 *  iBeacon Proximity UUID
 */
@property (nonatomic, strong, readonly) NSUUID *proximityUUID;

/**
 *  iBeacon Major
 */
@property (nonatomic, assign, readonly) CLBeaconMajorValue major;

/**
 *  iBeacon Minor
 */
@property (nonatomic, assign, readonly) CLBeaconMinorValue minor;

/**
 *  iBeacon Measured Power
 */
@property (nonatomic, assign, readonly) int8_t measuredPower;

/**
 *  MAC address of the device (6 bytes)
 */
@property (nonatomic, strong, readonly) NSData *macAddress;

/**
 *  Method allows initialize object.
 *
 *  @param proximityUUID    iBeacon Proximity UUID value.
 *  @param major            iBeacon Major value.
 *  @param minor            iBeacon Minor value.
 *  @param measuredPower    Measured power for iBeacon packet.
 *  @param macAddress       Mac address power for iBeacon packet.
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                        measuredPower:(int8_t)measuredPower
                           macAddress:(NSData *)macAddress;

/**
 *  Method allows to generate MAC address using Identifier and seed.
 *
 *  @param identifier   Identifier to be used for Mac generation. Device Identifier is recommented to be used here.
 *  @param seed         Seed for Mac address generation. Advertiser ID is recommended to be used here.
 */
+ (NSData *)randomStaticMacAddressForIdentifier:(NSString *)identifier
                                           seed:(int32_t)seed;


/**
 *  Method returns Generic Advertiser payload required to broadcast iBeacon packet.
 *
 *  @return Payload for Generic Advertiser.
 */
- (NSData *)getPayloadData;

@end

NS_ASSUME_NONNULL_END
