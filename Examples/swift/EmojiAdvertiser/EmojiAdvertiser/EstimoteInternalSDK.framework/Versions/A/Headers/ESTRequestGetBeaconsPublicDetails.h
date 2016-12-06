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
#import "ESTDefinitions.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ESTBeaconPublicDetailsFields)
{
    ESTBeaconPublicDetailsAllFields                        = 1 << 0,
    ESTBeaconPublicDetailsFieldMac                         = 1 << 1,
    ESTBeaconPublicDetailsFieldColor                       = 1 << 2,
    ESTBeaconPublicDetailsFieldPublicIdentifier            = 1 << 3,
    
    ESTBeaconPublicDetailsAllSettings                      = 1 << 4,
    ESTBeaconPublicDetailsFieldPower                       = 1 << 5,
    ESTBeaconPublicDetailsFieldSecurity                    = 1 << 6,
    ESTBeaconPublicDetailsFieldBroadcastingScheme          = 1 << 7,
    ESTBeaconPublicDetailsFieldUUIDMajorMinor              = 1 << 8,
    ESTBeaconPublicDetailsFieldEddystoneNamespaceID        = 1 << 9,
    ESTBeaconPublicDetailsFieldEddystoneInstanceID         = 1 << 10
};

typedef void(^ESTRequestGetBeaconsPublicDetailsBlock)(NSArray * _Nullable beaconVOArray, NSError * _Nullable error);

@interface ESTRequestGetBeaconsPublicDetails : ESTRequestGetJSON

/** Array of identifiers of beacons which details should be fetched.
 *  Can be MAC addresses or Eddystone Identifiers or proximityUUID:major:minor strings
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *beaconIdentifiers;
@property (nonatomic, assign, readonly) ESTBeaconPublicDetailsFields fields;

/**
 *  Initialise request with Beacons array.
 *
 *  @param beacons Array of CLBeacon objects
 *
 *  @param fields A mask of fields indicating which beacon parameters you want to fetch
 *
 *  @return instance of request
 */
- (instancetype)initWithBeacons:(NSArray<CLBeacon *> *)beacons andFields:(ESTBeaconPublicDetailsFields)fields;

/**
 *  Initialise request with MAC addresses.
 *
 *  @param macAddresses Array of MAC addresses as NSStrings
 *
 *  @param fields A mask of fields indicating which beacon parameters you want to fetch
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddresses:(NSArray<NSString *> *)macAddresses andFields:(ESTBeaconPublicDetailsFields)fields;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (Array of beaconVO objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetBeaconsPublicDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END

