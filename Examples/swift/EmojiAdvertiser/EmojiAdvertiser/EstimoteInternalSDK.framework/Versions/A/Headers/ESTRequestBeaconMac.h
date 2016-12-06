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

#import "ESTRequestGetJSON.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestBeaconMacErrorDomain @"ESTRequestBeaconMacErrorDomain"

/**
 *  Errors occurring for request.
 */
typedef NS_ENUM(NSInteger, ESTRequestBeaconMacError)
{
    /**
     *  Unknown error occurred.
     */
    ESTRequestBeaconMacErrorUnknown
};

typedef void(^ESTRequestBeaconMacBlock)(NSString * _Nullable macAddress, NSError * _Nullable error);

/**
 *  ESTRequestBeaconMac allows to get MAC address for beacon based on CLBeacon
 *  (ProximityUUID, Major, Minor) identification. Method is publicly available
 *  for all beacons.
 */

@interface ESTRequestBeaconMac : ESTRequestGetJSON

@property (nonatomic, strong, readonly) NSUUID *beaconProximityUUID;
@property (nonatomic, strong, readonly) NSNumber *beaconMajor;
@property (nonatomic, strong, readonly) NSNumber *beaconMinor;

/**
 *  Initialise request with beacon.
 *
 *  @param beacon beacon should be used to get MAC address.
 *
 *  @return instance of request
 */
- (instancetype)initWithBeacon:(CLBeacon *)beacon;

/**
 *  Initialise request with beacon params.
 *
 *  @param proximityUUID Corresponding beacon Proximity UUID.
 *  @param major Corresponding beacon Major.
 *  @param minor Corresponding beacon Minor.
 *
 *  @return instance of request
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(short)major
                                minor:(short)minor;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (CLLocation object).
 */
- (void)sendRequestWithCompletion:(ESTRequestBeaconMacBlock)completion;

@end

NS_ASSUME_NONNULL_END
