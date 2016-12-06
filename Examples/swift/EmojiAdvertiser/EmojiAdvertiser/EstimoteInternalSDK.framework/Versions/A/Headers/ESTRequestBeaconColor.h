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
#import "ESTRequestGetJSON.h"
#import "ESTBeaconVO.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestBeaconColorErrorDomain @"ESTRequestBeaconColorErrorDomain"

/**
 *  Errors occurring for request.
 */
typedef NS_ENUM(NSInteger, ESTRequestBeaconColorError)
{
    /**
     *  Error returned when Estimote Cloud failed to find color for beacon with provided ID.
     */
    ESTRequestBeaconColorErrorColorNotAvailable
};

typedef void(^ESTRequestBeaconColorBlock)(ESTColor beaconColor, NSError * _Nullable error);

/**
 *  ESTRequestBeaconColor is used to fetch color of single beacon device.
 */

@interface ESTRequestBeaconColor : ESTRequestGetJSON

@property (nonatomic, strong, readonly) NSString * _Nullable macAddress;

@property (nonatomic, strong, readonly) NSUUID * _Nullable proximityUUID;
@property (nonatomic, strong, readonly) NSNumber * _Nullable major;
@property (nonatomic, strong, readonly) NSNumber * _Nullable minor;

/**
 *  Initialise request with MAC address.
 *
 *  @param macAddress MAC address of device provided as NSString
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress;

/**
 *  Initialise request with MAC address.
 *
 *  @param beacon Proximity UUID, Major and Minor provided as CLBeacon
 *
 *  @return instance of request
 */
- (instancetype)initWithBeacon:(CLBeacon *)beacon;

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
 *  @param completion Completion block with returned data (ESTBeaconVO object with color and macAddress property filled).
 */
- (void)sendRequestWithCompletion:(ESTRequestBeaconColorBlock)completion;

@end

NS_ASSUME_NONNULL_END
