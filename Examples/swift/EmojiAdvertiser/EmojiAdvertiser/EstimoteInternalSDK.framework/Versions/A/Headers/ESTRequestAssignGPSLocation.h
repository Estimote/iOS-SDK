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
#import "ESTRequestPutJSON.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestAssignGPSLocationErrorDomain @"ESTRequestAssignGPSLocationErrorDomain"

/**
 *  Errors occurring for request.
 */
typedef NS_ENUM(NSInteger, ESTRequestAssignGPSLocationError)
{
    /**
     *  Error returned when request failed to obtain current GPS Location.
     *  It can occurs only when location was not provided during initialisation.
     */
    ESTRequestAssignGPSLocationErrorGPSLocationNotAvailable
};

typedef void(^ESTRequestAssignGPSLocationBlock)(CLLocation * _Nullable result, NSError * _Nullable error);

/**
 *  ESTRequestBeaconColor is used to assign GPS location to single beacon device. 
 *  GPS Location can be provided during initialisation or taken automatically when nil provided.
 */

@interface ESTRequestAssignGPSLocation : ESTRequestPutJSON

/**
 *  Initialise request with beacon object
 *
 *  @param beacon beacon object for whom location should be assigned
 *  @param location Optional location of the device. When nil provided, GPS position will be taken automatically.
 *
 *  @return initialised request
 */
- (instancetype)initWithBeacon:(CLBeacon *)beacon location:(CLLocation *)location;

/**
 *  Initialise request with MAC address
 *
 *  @param macAddress MAC address of beacon for whom location should be assigned
 *  @param location Optional location of the device. When nil provided, GPS position will be taken automatically.
 *
 *  @return initialised request
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress location:(CLLocation *)location;

/**
 *  Initialise request with Beacon parameters.
 *
 *  @param proximityUUID Beacon's proximity UUID
 *  @param major         Beacon's major
 *  @param minor         Beacon's minor
 *
 *  @return instance of request
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (CLLocation object).
 */
- (void)sendRequestWithCompletion:(ESTRequestAssignGPSLocationBlock)completion;

@end

NS_ASSUME_NONNULL_END
