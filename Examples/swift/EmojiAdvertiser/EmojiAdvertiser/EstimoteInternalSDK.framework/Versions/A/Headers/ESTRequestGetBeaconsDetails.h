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

typedef NS_OPTIONS(NSUInteger, ESTBeaconDetailsFields)
{
    ESTBeaconDetailsAllFields                        = 1 << 0,
    ESTBeaconDetailsFieldMac                         = 1 << 1,
    ESTBeaconDetailsFieldColor                       = 1 << 2,
    ESTBeaconDetailsFieldName                        = 1 << 3,
    ESTBeaconDetailsFieldGPSLocation                 = 1 << 4,
    ESTBeaconDetailsFieldIndoorLocation              = 1 << 5,
    ESTBeaconDetailsFieldPublicIdentifier            = 1 << 6,
    ESTBeaconDetailsFieldRemainingBatteryLifetime    = 1 << 7,
    
    ESTBeaconDetailsAllSettings                      = 1 << 8,
    ESTBeaconDetailsFieldBattery                     = 1 << 9,
    ESTBeaconDetailsFieldPower                       = 1 << 10,
    ESTBeaconDetailsFieldInterval                    = 1 << 11,
    ESTBeaconDetailsFieldHardware                    = 1 << 12,
    ESTBeaconDetailsFieldFirmware                    = 1 << 13,
    ESTBeaconDetailsFieldBasicPowerMode              = 1 << 14,
    ESTBeaconDetailsFieldSmartPowerMode              = 1 << 15,
    ESTBeaconDetailsFieldTimeZone                    = 1 << 16,
    ESTBeaconDetailsFieldSecurity                    = 1 << 17,
    ESTBeaconDetailsFieldMotionDetection             = 1 << 18,
    ESTBeaconDetailsFieldConditionalBroadcasting     = 1 << 19,
    ESTBeaconDetailsFieldBroadcastingScheme          = 1 << 20,
    ESTBeaconDetailsFieldUUIDMajorMinor              = 1 << 21,
    ESTBeaconDetailsFieldEddystoneNamespaceID        = 1 << 22,
    ESTBeaconDetailsFieldEddystoneInstanceID         = 1 << 23
};

typedef void(^ESTRequestGetBeaconsDetailsBlock)(NSArray * _Nullable beaconVOArray, NSError * _Nullable error);


/**
 *  Request allows to fetch information about group of beacons
 *  with identifiers provided during initialization.
 */
@interface ESTRequestGetBeaconsDetails : ESTRequestGetJSON

/** 
 *  Array of identifiers of beacons which details should be fetched.
 *  Can be MAC addresses or Eddystone Identifiers or proximityUUID:major:minor strings
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *beaconIdentifiers;

/**
 *  Possible beacon parameters that can be fetched from the Estimote Cloud.
 *  Provided as NS_OPTIONS ESTBeaconDetailsFields.
 */
@property (nonatomic, assign, readonly) ESTBeaconDetailsFields fields;

/**
 *  Initialise request with Beacons array.
 *
 *  @param beacons Array of CLBeacon objects
 *
 *  @param fields A mask of fields indicating which beacon parameters you want to fetch
 *
 *  @return instance of request
 */
- (instancetype)initWithBeacons:(NSArray<CLBeacon *> *)beacons andFields:(ESTBeaconDetailsFields)fields;

/**
 *  Initialise request with MAC addresses.
 *
 *  @param macAddresses Array of MAC addresses as NSStrings
 *
 *  @param fields A mask of fields indicating which beacon parameters you want to fetch
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddresses:(NSArray<NSString *> *)macAddresses andFields:(ESTBeaconDetailsFields)fields;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (Array of beaconVO objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetBeaconsDetailsBlock)completion;

@end

NS_ASSUME_NONNULL_END
