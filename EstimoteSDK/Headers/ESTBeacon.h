//
//  ESTBeacon.h
//  EstimoteSDK
//
//  Version : 1.2.0
//  Created by Marcin Klimek on 9/19/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"

@class ESTBeacon;

////////////////////////////////////////////////////////////////////
// Estimote beacon delegate protocol


/**
 
 ESTBeaconDelegate defines beacon connection delegate mathods. Connection is asynchronous operation so you need to be prepared that eg. beaconDidDisconnectWith: method can be invoked without previous action.
 
 */

@protocol ESTBeaconDelegate <NSObject>

@optional

/**
 * Delegate method that indicates error in beacon connection.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconConnectionDidFail:(ESTBeacon*)beacon withError:(NSError*)error;

/**
 * Delegate method that indicates success in beacon connection.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconConnectionDidSucceeded:(ESTBeacon*)beacon;

/**
 * Delegate method that beacon did disconnect with device.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconDidDisconnect:(ESTBeacon*)beacon withError:(NSError*)error;

@end


////////////////////////////////////////////////////////////////////
// Interface definition

/**
 
 The ESTBeacon class represents a beacon that was encountered during region monitoring. You do not create instances of this class directly. The ESTBeaconManager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon was encountered.
 
 
ESTBeacon class contains basic Apple CLBeacon object reference as well as some additional functionality. It allows to  connect with Estimote beacon to read / write its characteristics.
 
 */

@interface ESTBeacon : NSObject

@property (nonatomic)           ESTBeaconFirmwareState  firmwareState;
@property (nonatomic)           id <ESTBeaconDelegate>  delegate;

/////////////////////////////////////////////////////
// bluetooth beacon available when used with
// startEstimoteBeaconsDiscoveryForRegion:


/// @name Publicly available properties

/**
 *  macAddress
 *
 *  Discussion:
 *    Hardware MAC address of the beacon.
 */
@property (nonatomic, strong)   NSString*               macAddress;

/**
 *  proximityUUID
 *
 *    Proximity identifier associated with the beacon.
 *
 */
@property (nonatomic, strong)   NSUUID*                 proximityUUID;

/**
 *  major
 *
 *    Most significant value associated with the region. If a major value wasn't specified, this will be nil.
 *
 */
@property (nonatomic, strong)   NSNumber*               major;

/**
 *  minor
 *
 *    Least significant value associated with the region. If a minor value wasn't specified, this will be nil.
 *
 */
@property (nonatomic, strong)   NSNumber*               minor;



/**
 *  rssi
 *
 *    Received signal strength in decibels of the specified beacon.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (nonatomic)           NSInteger               rssi;

/**
 *  distance
 *
 *    Distance between phone and beacon calculated based on rssi and measured power.
 *
 */
@property (nonatomic, strong)   NSNumber*               distance;

/**
 *  proximity
 *
 *    The value in this property gives a general sense of the relative distance to the beacon. Use it to quickly identify beacons that are nearer to the user rather than farther away.
 */
@property (nonatomic)           CLProximity             proximity;

/**
 *  measuredPower
 *
 *    rssi value measured from 1m. This value is used for device calibration.
 */
@property (nonatomic, strong)   NSNumber*               measuredPower;

/**
 *  hardwareVersion
 *
 *    Reference of the device peripheral object.
 */
@property (nonatomic, strong)   CBPeripheral*           peripheral;

/////////////////////////////////////////////////////
// properties filled when read characteristic

/// @name Properties available after connection


/**
 *  firmwareUpdateInfo
 *
 *    Flag indicating connection status.
 */
@property (nonatomic, readonly)   BOOL                  isConnected;

/**
 *  power
 *
 *    Power of signal in dBm. Value available after connection with the beacon. It takes one of the values represented by ESTBeaconPower .
 */
@property (nonatomic, strong)   NSNumber*               power;

/**
 *  advInterval
 *
 *    Advertising interval of the beacon. Value change from 50ms to 2000ms. Value available after connection with the beacon
 */
@property (nonatomic, strong)   NSNumber*               advInterval;

/**
 *  batteryLevel
 *
 *    Battery strength in %. Battery level change from 100% - 0%. Value available after connection with the beacon
 */
@property (nonatomic, strong)   NSNumber*               batteryLevel;


/**
 *  hardwareVersion
 *
 *    Version of device hardware. Value available after connection with the beacon
 */
@property (nonatomic, strong)   NSString*               hardwareVersion;

/**
 *  firmwareVersion
 *
 *    Version of device firmware. Value available after connection with the beacon
 */
@property (nonatomic, strong)   NSString*               firmwareVersion;


/**
 *  firmwareUpdateInfo
 *
 *    Firmware update availability status. Value available after connection with the beacon and firmware version check.
 */
@property (readonly, nonatomic) ESTBeaconFirmwareUpdate firmwareUpdateInfo;


/// @name Connection handling methods


/**
 * Connect to particular beacon using bluetooth.
 * Connection is required to change values like
 * Major, Minor, Power and Advertising interval.
 *
 * @return void
 */
-(void)connectToBeacon;

/**
 * Disconnect device with particular beacon
 *
 * @return void
 */
-(void)disconnectBeacon;


/// @name Methods for reading beacon configuration

/**
 * Read major of connected beacon (Previous connection
 * required)
 *
 * @param completion block with major value as param
 *
 * @return void
 */
- (void)readBeaconMajorWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Read minor of connected beacon (Previous connection
 * required)
 *
 * @param completion block with minor value as param
 *
 * @return void
 */
- (void)readBeaconMinorWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Read advertising interval of connected beacon (Previous connection
 * required)
 *
 * @param completion block with advertising interval value as param
 *
 * @return void
 */
- (void)readBeaconAdvIntervalWithCompletion:(ESTUnsignedShortCompletionBlock)completion;


/**
 * Read power of connected beacon (Previous connection
 * required)
 *
 * @param completion block with power value as param
 *
 * @return float value of beacon power
 */
- (void)readBeaconPowerWithCompletion:(ESTPowerCompletionBlock)completion;

/**
 * Read battery level of connected beacon (Previous connection
 * required)
 *
 * @param completion block with battery level value as param
 *
 * @return void
 */
- (void)readBeaconBatteryWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Read firmware version of connected beacon (Previous connection
 * required)
 *
 * @param completion block with firmware version value as param
 *
 * @return void
 */
- (void)readBeaconFirmwareVersionWithCompletion:(ESTStringCompletionBlock)completion;

/**
 * Read hardware version of connected beacon (Previous connection
 * required)
 *
 * @param completion block with hardware version value as param
 *
 * @return void
 */
- (void)readBeaconHardwareVersionWithCompletion:(ESTStringCompletionBlock)completion;


/// @name Methods for writing beacon configuration

/**
 * Writes major param to bluetooth connected beacon.
 *
 * @param major major beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMajor:(unsigned short)major withCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes minor param to bluetooth connected beacon.
 *
 * @param minor minor beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMinor:(unsigned short)minor withCompletion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Writes advertising interval (in milisec) of connected beacon.
 *
 * @param advertising interval of beacon (50 - 2000 ms)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconAdvInterval:(unsigned short)interval withCompletion:(ESTUnsignedShortCompletionBlock)completion;


/**
 * Writes power of bluetooth connected beacon.
 *
 * @param power advertising beacon power
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconPower:(ESTBeaconPower)power withCompletion:(ESTPowerCompletionBlock)completion;

/// @name Firmware update handling methods

/**
 * Verifies if new firmware version is available for download
 * without any additional action. Internet connection
 * is required to pass this process.
 *
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)checkFirmwareUpdateWithCompletion:(ESTFirmwareUpdateCompletionBlock)completion;

/**
 * Verifies if new firmware version is available for download
 * and updates firmware of connected beacon. Internet connection 
 * is required to pass this process.
 *
 * @param progress Block handling operation progress
 * @param completion Block handling operation completion
 *
 * @return void
 */
-(void)updateBeaconFirmwareWithProgress:(ESTStringCompletionBlock)progress
                          andCompletion:(ESTCompletionBlock)completion;

@end
