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
#import "ESTBeaconBaseVO.h"

/**
 *  Object of this class contains all settings that were applied to the Estimote beacon device.
 */

@interface ESTBeaconRecentConfig : ESTBeaconBaseVO

/**
 *  To what proximity UUID was changed.
 */
@property (nonatomic, readonly) NSString *proximityUUID;

/**
 *  To what value major was changed.
 */
@property (nonatomic, readonly) NSNumber *major;

/**
 *  To what value minor was changed.
 */
@property (nonatomic, readonly) NSNumber *minor;

/**
 *  Flag for switching state of Estimote Secure UUID.
 */
@property (nonatomic, readonly) NSNumber *security;

/**
 *  To what value advertising interval was changed.
 */
@property (nonatomic, readonly) NSNumber *advInterval;

/**
 *  To what value (`ESTBroadcastingPower`) broadcasting power was changed.
 */
@property (nonatomic, readonly) NSNumber *power;

/**
 *  To what value flag for switching state of basic power mode was changed.
 */
@property (nonatomic, readonly) NSNumber *basicPowerMode;

/**
 *  TO what value flag for switching state of smart power mode was changed.
 */
@property (nonatomic, readonly) NSNumber *smartPowerMode;

/**
 *  To what firmware version beacon was updated.
 */
@property (nonatomic, readonly) NSString *firmware;

/**
 *  To what type (`ESTBroadcastingScheme`) primary packet type was changed.
 */
@property (nonatomic, readonly) NSNumber *broadcastingScheme;

/**
 *  To what location beacons was assigned.
 */
@property (nonatomic, readonly) NSString *formattedAddress;

/**
 *  Set to YES if user has unassigned the device's Geo Location.
 */
@property (nonatomic, readonly) BOOL geoLocationDeleted;

/**
 * To what value `ESTBeaconConditionalBroadcasting` was changed.
 */
@property (nonatomic, readonly) NSNumber *conditionalBroadcasting;

/**
 * To what zone beacon was assigned.
 */
@property (nonatomic, readonly) NSString *zone;

/**
 *  Flag switching state of device motion detection (accelerometer).
 */
@property (nonatomic, readonly) NSNumber *motionDetection;

/**
 *  Method initializing recent change's config object.
 *
 *  @param data NSDictionary of data parsed from Cloud response
 *
 *  @return recent change config
 */
- (instancetype)initWithCloudData:(NSDictionary *)data;

@end
