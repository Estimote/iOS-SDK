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
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"
#import "ESTFirmwareInfoVO.h"
#import "ESTBeaconVO.h"

NS_ASSUME_NONNULL_BEGIN

#define CONNECTION_ERROR_UID_MISSING    400
#define CONNECTION_ERROR_AUTHORIZATION  401
#define CONNECTION_ERROR_TIMEOUT        402
#define CONNECTION_ERROR_NOT_LOGGED_IN  403

#define CHARACTERISTIC_ERROR            410
#define SAME_VALUE_ERROR                411


#define AUTHORIZATION_ERROR_DIFFERENT_USER      601
#define AUTHORIZATION_ERROR_NO_CLOUD_ACCOUNT    602
#define AUTHORIZATION_ERROR_NOT_ASSIGNED        603
#define AUTHORIZATION_ERROR_NOT_REGISTERED      604
#define AUTHORIZATION_ERROR_SERVER              605

@class ESTBeaconConnection;

enum
{
    ESTConnectionInternetConnectionError,
    ESTConnectionIdentifierMissingError,
    ESTConnectionNotAuthorizedError,
    ESTConnectionNotConnectedToReadWrite
};

/**
 * The `ESTBeaconConnectionDelegate` protocol defines the delegate methods used to receive updates about `<ESTBeaconConnection>` connection status, as well as sensor related updates once a connection to the beacon has been established.
 */

@protocol ESTBeaconConnectionDelegate <NSObject>

@optional

/**
 * Tells the delegate that Estimote Cloud verified device for authorized user.
 *
 * @param connection The beacon connection object reporting the event.
 * @param data Information about the device stored in the Estimote Cloud.
 * @param error An error object containing the error code that indicates why connection failed.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection didVerifyWithData:(ESTBeaconVO * _Nullable)data error:(NSError * _Nullable)error;

/**
 * Tells the delegate that an attempt to connect to a beacon succeeded and the connection has been established.
 *
 * @param connection The beacon connection object reporting the event.
 */
- (void)beaconConnectionDidSucceed:(ESTBeaconConnection *)connection;

/**
 * Tells the delegate that an attempt to connect to a beacon has failed.
 *
 * @param connection The beacon connection object reporting the event.
 * @param error An error object containing the error code that indicates why connection failed.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection didFailWithError:(NSError *)error;

/**
 * Tells the delegate that a previously connected beacon has disconnected.
 *
 * @param connection The beacon connection object reporting the event.
 * @param error An error object containing the error code that indicates why the beacon disconnected.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection didDisconnectWithError:(NSError * _Nullable)error;

/**
 * Tells the delegate that a beacon's `<[ESTBeaconConnection motionState]>` value has changed.
 *
 * @param connection The beacon connection object reporting the event.
 * @param state The new `motionState` value.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection motionStateChanged:(ESTBeaconMotionState)state;

/**
 * Tells the delegate that a beacon's RSSI value was updated.
 *
 * @param connection The beacon connection object reporting the event.
 * @param rssi The new rssi value.
 */
- (void)beaconConnection:(ESTBeaconConnection *)connection didUpdateRSSI:(NSNumber *)rssi;

@end

/**
 * The `ESTBeaconConnection` class defines the interface for interacting with a single Estimote beacon. It enables you to connect to the device, retrieve properties and change its configuration settings.
 *
 * The ESTBeaconConnection instance can be initialized using CLBeacon object or mac address being unique identifier of particular device. Fetch required beacon details you can use:
 *
 * - `startRangingBeaconsInRegion:` - which is a CoreLocation based scan and delivers `CLBeacon` objects.
 *
 * - `startEstimoteBeaconsDiscovery` - which is a CoreBluetooth based scan and delivers `ESTBluetoothBeacon` object containing mac address.
 *
 * Properties become editable once connected to the beacon. See connect for more details about connecting to the beacon. You will also need to assign a delegate to be notified about connection and disconnection events. The delegate needs to conform to the `<ESTBeaconConnectionDelegate>` protocol.
 */

@interface ESTBeaconConnection : NSObject

/**
 *  Delegate object receiving callbacks.
 */
@property (nonatomic, weak) id<ESTBeaconConnectionDelegate> _Nullable delegate;

/**
 * Identifier of the device that you aim to connect.
 * Based on the method you used to initialize it may contain:
 * - Device Mac address
 * - Device iBeacon properties formatted as follows: ProximityUUUID:Major:Minor
 *
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 * The connection status between the user device and the beacon.
 *
 */
@property (readonly, nonatomic) ESTConnectionStatus connectionStatus;

/**
 *  Static method initializing connection object with Estimote beacon
 *
 *  @param proximityUUID discovered beacons Proximity UUID
 *  @param major discovered beacons Major
 *  @param minor discovered beacons Minor
 *  @param delegate delegate reference
 *
 *  @return beacon connection object
 */
+ (instancetype)connectionWithProximityUUID:(NSUUID *)proximityUUID
                                      major:(CLBeaconMajorValue)major
                                      minor:(CLBeaconMinorValue)minor
                                   delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate;

/**
 *  Static method initializing connection object with Estimote beacon
 *
 *  @param beacon discovered beacon
 *  @param delegate delegate reference
 *
 *  @return beacon connection object
 */
+ (instancetype)connectionWithBeacon:(CLBeacon *)beacon
                            delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate;

/**
 *  Static method initializing connection object with Estimote beacon
 *
 *  @param macAddress discovered beacon object MAC address
 *  @param delegate delegate reference
 *
 *  @return beacon connection object
 */
+ (instancetype)connectionWithMacAddress:(NSString *)macAddress
                                delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate __attribute__((deprecated("Starting from SDK 4.0.0-beta1 macAddress is deprecated. Use initWithIdentifier constructor")));

/**
 *  Static method initializing connection object with Estimote beacon
 *
 *  @param identifier discovered beacon object identifier
 *  @param delegate delegate reference
 *
 *  @return beacon connection object
 */
+ (instancetype)connectionWithIdentifier:(NSString *)identifier
                                delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate;

/**
 *  Method initializing connection object with Estimote beacon with
 *  delegate object support
 *
 *  @param proximityUUID discovered beacons Proximity UUID
 *  @param major discovered beacons Major
 *  @param minor discovered beacons Minor
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                             delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate
                     startImmediately:(BOOL)startImmediately;

/**
 *  Method initializing connection object with Estimote beacon with
 *  delegate object support
 *
 *  @param beacon discovered beacon
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithBeacon:(CLBeacon *)beacon
                      delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate
              startImmediately:(BOOL)startImmediately;

/**
 *  Method initializing connection object with beacon with
 *  delegate object support
 *
 *  @param macAddress discovered beacon object MAC address
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress
                          delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate
                  startImmediately:(BOOL)startImmediately __attribute__((deprecated("Starting from SDK 3.7.0 macAddress is deprecated. Use initWithIdentifier constructor")));

/**
 * Method initializing connection object with beacon with
 * delegate object support
 *
 *  @param identifier discovered beacon object identifier
 *  @param delegate delegate to handle callbacks
 *  @param startImmediately indicates if created object should start connection immediately
 *
 *  @return beacon connection object
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                          delegate:(id<ESTBeaconConnectionDelegate> _Nullable)delegate
                  startImmediately:(BOOL)startImmediately;

#pragma mark Connection handling
///--------------------------------------------------------------------
/// @name Connection handling
///--------------------------------------------------------------------

/**
 *  Initiates connection procedure
 */
- (void)startConnection;


/**
 *  Initiates connection procedure with additional params
 *
 *  @param attempts number of connection attempts
 *  @param timeout  timeout of single connection
 */
- (void)startConnectionWithAttempts:(NSInteger)attempts
                  connectionTimeout:(NSInteger)timeout;

/**
 *  Cancels connection procedure
 */
- (void)cancelConnection;

/**
 *  Performs disconnect procedure for connected device.
 */
- (void)disconnect;


#pragma mark - Device identification
///--------------------------------------------------------------------
/// @name Device identification
///--------------------------------------------------------------------

/**
 * The MAC address of the beacon.
 */
@property (readonly, nonatomic) NSString * _Nullable macAddress;

/**
 * The name of the beacon.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSString * _Nullable name;

/**
 * The dictionary containing geocoding data for beacon's GPS location.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSDictionary * _Nullable location;

/**
 * The latitude of beacon's GPS location.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSNumber * _Nullable latitude;

/**
 * The longitude of beacon's GPS location.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSNumber * _Nullable longitude;

/**
 * The identifier of indoor location beacon belongs to.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSString * _Nullable indoorLocationIdentifier;

/**
 * The name of indoor location beacon belongs to.
 *
 * This value is stored and retrieved from the Estimote Cloud.
 */
@property (readonly, nonatomic) NSString * _Nullable indoorLocationName;

/**
 * The color of the beacon.
 *
 * This value is stored and retrieved from the Estimote Cloud, which means it might be unavailable under certain circumstances - e.g. no Internet connectivity.
 *
 */
@property (readonly, nonatomic) ESTColor color;

/**
 *  The underlying Bluetooth peripheral device.
 */
@property (readonly, nonatomic) CBPeripheral * _Nullable peripheral __attribute__((deprecated("CBPeripheral peripheral property is deprecated since 3.7.0 version")));

/**
 *  Broadcasting scheme of device.
 */
@property (readonly, nonatomic) ESTBroadcastingScheme broadcastingScheme;

#pragma mark - iBeacon settings
///--------------------------------------------------------------------
/// @name iBeacon settings
///--------------------------------------------------------------------

/**
 * The proximity ID of the beacon.
 *
 * @see writeProximityUUID:completion:
 */
@property (readonly, nonatomic) NSUUID * _Nullable proximityUUID;

/**
 * The proximity ID of the beacon when it's in motion.
 *
 * This default to the same value as the `<proximityUUID>`. Setting it to a different value enables you to detect whether a beacon is in motion or not without a need to connect to the beacon. This can be achieved in two ways:
 *
 * 1. When ranging beacons - if the beacon is in motion, the `proximityUUID` property will be equal to the `motionProximityUUID`. Note that the `motionProximityUUID` property is not available unless connected to the beacon, so you need to know its value in advance.
 *
 * 2. When monitoring regions - you can have two separate regions, one with the regular `proximityUUID` and one with the `motionProximityUUID`. Enter and exit notifications will then correspond to the beacon starting and stopping to move.
 *
 * @warning This feature is disabled by default. The option to enable it will be made available in an upcoming update to the SDK.
 *
 * @since Estimote OS 2.0
 *
 */
@property (readonly, nonatomic) NSUUID * _Nullable motionProximityUUID;

/**
 * The most significant value in the beacon.
 *
 * @see writeMajor:completion:
 */
@property (readonly, nonatomic) NSNumber * _Nullable major;

/**
 * The least significant value in the beacon.
 *
 * @see writeMinor:completion:
 */
@property (readonly, nonatomic) NSNumber * _Nullable minor;

/**
 * The power of the beacon's radio signal in dBm.
 *
 * This is a `char` value, so the proper way to retrieve it is `[beacon.power charValue]`.
 *
 * @see writePower:completion:
 */
@property (readonly, nonatomic) NSNumber * _Nullable power;

/**
 * The advertising interval of the beacon in ms.
 *
 * @see writeAdvInterval:completion:
 */
@property (readonly, nonatomic) NSNumber * _Nullable advInterval;

#pragma mark - Google Eddystone

/**
 * Namespace ID of Google Eddystone - part of device identification.
 */
@property (readonly, nonatomic) NSString * _Nullable eddystoneNamespace;

/**
 * Instance ID of Google Eddystone - part of device identification.
 */
@property (readonly, nonatomic) NSString * _Nullable eddystoneInstance;

/**
 * URL advertised by Google Eddystone device in URL mode.
 */
@property (readonly, nonatomic) NSString * _Nullable eddystoneURL;

#pragma mark - Hardware and software information

/**
 * The hardware version of the beacon.
 */
@property (readonly, nonatomic) NSString * _Nullable hardwareVersion;

/**
 * The firmware version of the beacon.
 *
 * @see checkFirmwareUpdateWithCompletion:
 * @see updateFirmwareWithProgress:completion:
 */
@property (readonly, nonatomic) NSString * _Nullable firmwareVersion;

/**
 * The received signal strength of the beacon, measured in decibels.
 */
@property (readonly, nonatomic) NSNumber * _Nullable rssi;

#pragma mark - Power management
///--------------------------------------------------------------------
/// @name Power management
///--------------------------------------------------------------------

/**
 * The battery charge level for the beacon.
 *
 * Battery level ranges from 0 (fully discharged) to 100 (fully charged).
 */
@property (readonly, nonatomic) NSNumber * _Nullable batteryLevel;

/**
 * The battery model.
 *
 * @see ESTBeaconBatteryType
 */
@property (readonly, nonatomic) ESTBeaconBatteryType batteryType;

/**
 *    Remaining lifetime in days, based on current battery level, advertising interval and broadcasting power values
 */
@property (readonly, nonatomic) NSNumber * _Nullable remainingLifetime;

/**
 * A flag indicating availability and status of the Basic Power Mode.
 *
 * @since Estimote OS A2.1
 *
 * @see ESTBeaconPowerSavingMode
 */
@property (readonly, nonatomic) ESTBeaconPowerSavingMode basicPowerMode;

/**
 * A flag indicating availability and status of the Smart Power Mode.
 *
 * @since Estimote OS A2.1
 *
 * @see ESTBeaconPowerSavingMode
 */
@property (readonly, nonatomic) ESTBeaconPowerSavingMode smartPowerMode;

/**
 *  A flag indicating status of Estimote Secure UUID.
 *
 *  @since Estimote OS 2.2
 *  @see ESTBeaconEstimoteSecureUUID
 */
@property (readonly, nonatomic) ESTBeaconEstimoteSecureUUID estimoteSecureUUIDState;

/**
 * A flag indicating if motion UUID is enabled.
 *
 * @since Estimote OS A2.1
 *
 * @see writeMotionUUIDEnabled:completion:
 */
@property (readonly, nonatomic) ESTBeaconMotionUUID motionUUIDState;

#pragma mark - Sensors handling
///--------------------------------------------------------------------
/// @name Sensors handling
///--------------------------------------------------------------------

/**
 * A flag indicating if the beacon is in motion or not.
 *
 * This value changes:
 *
 * - from NO to YES immediately after a still beacon starts moving,
 *
 * - from YES to NO after a beacon stops moving and remains still for 2 seconds.
 *
 */
@property (readonly, nonatomic) ESTBeaconMotionState motionState;

/**
 *  State of temperature sensor.
 */
@property (readonly, nonatomic) ESTBeaconTemperatureState temperatureState;

/**
 * A flag indicating which type of broadcasting is enabled
 *
 * @since Estimote OS A3.0.0
 *
 * @see writeConditionalBroadcastingType:completion:
 */
@property (readonly, nonatomic) ESTBeaconConditionalBroadcasting conditionalBroadcastingState;

/**
 * A flag indicating if accelerometer is enabled.
 *
 * @since Estimote OS A2.1
 *
 * @see writeMotionDetectionEnabled:completion:
 */
@property (readonly, nonatomic) ESTBeaconMotionDetection motionDetectionState;

#pragma mark - Reading methods for sensors
///--------------------------------------------------------------------
/// @name Reading methods for sensors
///--------------------------------------------------------------------

/**
 * Retrieves the temperature of surrounding environment reported by the beacon.
 *
 * @param completion A block that is called when the temperature has been retrieved from the beacon.
 *
 * The completion block receives the following parameters:
 *
 * - `NSNumber *value` - The temperature in Celsius degrees.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @see writeCalibratedTemperature:completion:
 */
- (void)readTemperatureWithCompletion:(ESTNumberCompletionBlock)completion;

/**
 * Retrieves the number of times the beacon has been in motion since the last `<resetAccelerometerCountWithCompletion:>`.
 *
 * @param completion A block that is called when the counter has been retrieved.
 *
 * The completion block receives the following parameters:
 *
 * - `NSNumber *value` - The value of the counter.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)readAccelerometerCountWithCompletion:(ESTNumberCompletionBlock)completion;

/**
 * Resets the counter - number of times the beacon has been in motion since the last reset.
 *
 * @param completion A block that is called when the counter has been reset.
 *
 * The completion block receives the following parameters:
 *
 * - `NSNumber *value` - The new value of the counter.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)resetAccelerometerCountWithCompletion:(ESTUnsignedShortCompletionBlock)completion;

#pragma mark - Writing methods for broadcasting settings
///--------------------------------------------------------------------
/// @name Writing methods for broadcasting settings
///--------------------------------------------------------------------

/**
 *  Changes broadcasting scheme for device. Broadcasting scheme describes set settings
 *  defining what kind of data and how often is broadcasting.
 *
 *  Possible options are:
 *  - ESTBroadcastingSchemeEstimote - broadcasts iBeacon packets with customizable Advertising interval.
 *    Default advertising interval (950ms) value is set after method invocation.
 *  - ESTBroadcastingSchemeIBeacon - broadcasts iBeacon packets with iBeacon Advertising interval.
 *  - ESTBroadcastingSchemeEddystoneURL - broadcasts Eddystone-URL packets with customizable interval.
 *    Default advertising interval (500ms) value is set after method invocation.
 *  - ESTBroadcastingSchemeEddystoneUID - broadcasts Eddystone-UID packets with customizable interval.
 *    Default advertising interval (500ms) value is set after method invocation.
 */
- (void)writeBroadcastingScheme:(ESTBroadcastingScheme)broadcastingScheme completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 *  Changes the conditional broadcasting type. Note that the accelerometer must be enabled for this feature to work
 *  i.e. you must set Motion Detection Flag in order to use this feature.
 *  Possible options are:
 *  - ESTBeaconConditionalBroadcastingOff - the default mode, beacon is broadcasting all the time
 *  - ESTBeaconConditionalBroadcastingMotionOnly – beacon only advertises when it's in motion.
 *    Note that UUID used in advertising packet depends on Motion UUID Flag state.
 *  - ESTBeaconConditionalBroadcastingFlipToStop – beacon does not advertise when it's stationary and facing gecko pad up.
 *    If the beacon is moving or oriented differently it acts normally.
 *
 *  @since Estimote OS A3.0.0
 *
 *  @param conditionalBroadcasting Conditional broadcasting mode to be set in the beacon.
 *  @param completion A block that is called when the belly mode has been enabled or disabled.
 *
 */
- (void)writeConditionalBroadcastingType:(ESTBeaconConditionalBroadcasting)conditionalBroadcasting
                              completion:(ESTBoolCompletionBlock)completion;

#pragma mark - Writing methods for iBeacon settings
///--------------------------------------------------------------------
/// @name Writing methods for iBeacon settings
///--------------------------------------------------------------------

/**
 * Sets the `<name>` of the beacon.
 *
 * @param name The new name of the beacon.
 * @param completion A block that is called when the new name has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `NSString *value` - The new name of the beacon.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeName:(NSString *)name completion:(ESTStringCompletionBlock)completion;

/**
 * Sets the `<proximityUUID>`.
 *
 * @param pUUID The new `proximityUUID`.
 * @param completion A block that is called when the new `proximityUUID` has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `NSString *value` - The new `proximityUUID`.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @warning If you change the `proximityUUID`, you might want to consider changing the `<motionProximityUUID>` as well. If you don't, the beacon will broadcast two different `proximityUUIDs` depending on whether its in motion or not!@
 */
- (void)writeProximityUUID:(NSString *)pUUID completion:(ESTStringCompletionBlock)completion;

/**
 * Sets the `<major>` value.
 *
 * @param major The new `major` value.
 * @param completion A block that is called when the new `major` value has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `unsigned short value` - The new `major` value.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeMajor:(unsigned short)major completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the `<minor>` value.
 *
 * @param minor The new `minor` value.
 * @param completion A block that is called when the new `minor` value has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `unsigned short value` - The new `minor` value.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeMinor:(unsigned short)minor completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the advertising interval, i.e. `<advInterval>`.
 *
 * @param interval The new `advInterval` in milliseconds. The value must be in range from 100 to 2000.
 * @param completion A block that is called when the new `advInterval` has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `unsigned short value` - The new `advInterval`.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeAdvInterval:(unsigned short)interval completion:(ESTUnsignedShortCompletionBlock)completion;

/**
 * Sets the broadcasting `<power>`.
 *
 * @param power The new broadcasting `power`. Must be one of the <ESTBeaconPower> values.
 * @param completion A block that is called when the new broadcasting power has been set.
 *
 * The completion block receives the following parameters:
 *
 * - `ESTBeaconPower value` - The new broadcasting `power`.
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writePower:(ESTBeaconPower)power completion:(ESTPowerCompletionBlock)completion;

#pragma mark - Writing methods for Google beacons
///--------------------------------------------------------------------
/// @name Writing methods for Google beacons
///--------------------------------------------------------------------

/**
 *  Sets Google beacon Namespace ID. Value should be provided as a domain formatted string (FQDN)
 *  according to Google beacon best practices. Method automatically produce SHA-1 hash.
 *  First 10 bytes of produced hash are used as Namespace ID.
 *
 *  @param eddystoneNamespace Google beacon Namespace ID
 *  @param completion A block that is called when the Namespace has been changed or error occurred.
 */
- (void)writeEddystoneDomainNamespace:(NSString *)eddystoneNamespace completion:(ESTStringCompletionBlock)completion;

/**
 *  Sets Google beacon Instance ID. Value should be provided as a Hexadecimal string
 *  representing 6 bytes (12 character string - 2 chars for 1 byte).
 *
 *  @param eddystoneNamespace Google beacon Instance ID
 *  @param completion A block that is called when the Instance ID has been changed or error occurred.
 */
- (void)writeEddystoneHexNamespace:(NSString *)eddystoneNamespace completion:(ESTStringCompletionBlock)completion;

/**
 *  Sets Google beacon Instance ID. Value should be provided as a Hexadecimal string
 *  representing 6 bytes (12 character string - 2 chars for 1 byte).
 *
 *  @param eddystoneInstance Google beacon Instance ID
 *  @param completion A block that is called when the Instance ID has been changed or error occurred.
 */
- (void)writeEddystoneInstance:(NSString *)eddystoneInstance completion:(ESTStringCompletionBlock)completion;

/**
 *  Sets Eddystone URL. Defined URL is provided in advertising packet
 *  when ESTBeaconPacketTypeEddystoneURL is selected as a packet type.
 *
 *  @param eddystoneURL Eddystone URL
 *  @param completion A block that is called when the URL has been changed or error occurred.
 */
- (void)writeEddystoneURL:(NSString *)eddystoneURL completion:(ESTStringCompletionBlock)completion;

#pragma mark - Writing methods for power management
///--------------------------------------------------------------------
/// @name Writing methods for power management
///--------------------------------------------------------------------

/**
 * Enables or disables the `<basicPowerMode>`.
 *
 * @param enable YES to enable, NO to disable the Basic Power Mode.
 * @param completion A block that is called when the Basic Power Mode has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - `BOOL value` - YES if the Basic Power Mode has been enabled, NO if the Basic Power Mode has been disabled.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeBasicPowerModeEnabled:(BOOL)enable
                        completion:(ESTBoolCompletionBlock)completion;

/**
 * Enables or disables the `<smartPowerMode>`.
 *
 * @param enable YES to enable, NO to disable the Smart Power Mode.
 * @param completion A block that is called when the Smart Power Mode has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - `BOOL value` - YES if the Smart Power Mode has been enabled, NO if the Smart Power Mode has been disabled.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeSmartPowerModeEnabled:(BOOL)enable
                        completion:(ESTBoolCompletionBlock)completion;


#pragma mark - Writing methods for security features
///--------------------------------------------------------------------
/// @name Writing methods for security features
///--------------------------------------------------------------------

/**
 *  Enables Estimote Secure UUID.
 *
 *  @param enable     Yes to enable, No to disable Estimote Secure UUID.
 *  @param completion Block with operation result.
 */
- (void)writeEstimoteSecureUUIDEnabled:(BOOL)enable
                            completion:(ESTBoolCompletionBlock)completion;

#pragma mark - Writing methods for sensors
///--------------------------------------------------------------------
/// @name Writing methods for sensors
///--------------------------------------------------------------------

/**
 * Enables or disables the accelerometer allowing to detect if beacon is in motion.
 *
 * @param enable YES to enable, NO to disable the accelerometer.
 * @param completion A block that is called when the accelerometer has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - `BOOL value` - YES if the accelerometer has been enabled, NO if the accelerometer has been disabled.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @since Estimote OS A2.1
 *
 */
- (void)writeMotionDetectionEnabled:(BOOL)enable
                         completion:(ESTBoolCompletionBlock)completion;

/**
 * Enables or disables the motion UUID.
 *
 * @param enable YES to enable, NO to disable the motion UUID.
 * @param completion A block that is called when the motion UUID has been enabled or disabled.
 *
 * The completion block receives the following parameters:
 *
 * - `BOOL value` - YES if the motion UUID has been enabled, NO if the motion UUID has been disabled.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @since Estimote OS A2.1
 *
 */
- (void)writeMotionUUIDEnabled:(BOOL)enable
                    completion:(ESTBoolCompletionBlock)completion;

/**
 * Calibrates the beacon's thermometer sensor.
 *
 * Beacons are basically calibrated out of the box, but additional manual calibration is recommended in order to minimize measurement error. When the sensor is not calibrated, measurement error is ±4 ℃. After calibration it's ±2 ℃.
 *
 * To perform calibration you need to keep the beacon at room temperature for a couple of minutes. Use a separate thermometer to read the actual value (in Celsius degrees) and pass it to this method.
 *
 * @param temperature The reference temperature in Celsius degrees.
 * @param completion A block that is called when the calibration has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - `NSNumber *value` - The current temperature in Celsius degrees, after the calibration.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)writeCalibratedTemperature:(NSNumber *)temperature
                        completion:(ESTNumberCompletionBlock)completion;

#pragma mark - Writing methods for GPS location
///--------------------------------------------------------------------
/// @name Writing methods for GPS location
///--------------------------------------------------------------------

/**
  * Saves GPS latitude and longitude in Estimote Cloud.
  * After successful save lat and log is set in beacon connection object.
  *
  *  @param latitude   GPS latitude
  *  @param longitude  GPS longitude
  *  @param completion completion block fired on operation completion
  */
- (void)writeLatitude:(NSNumber *)latitude
            longitude:(NSNumber *)longitude
           completion:(ESTCompletionBlock)completion;

#pragma mark - Writing methods for Cloud Tags setting of a device
///--------------------------------------------------------------------
/// @name Writing methods for Cloud Tags setting of a device
///--------------------------------------------------------------------

/**
  * Saves Cloud Tags setting for the device in Estimote Cloud.
  *
  *  @param tags       Cloud Tags
  *  @param completion completion block fired on operation completion
  */
-  (void)writeTags:(NSSet <NSString *> *)tags
        completion:(ESTCompletionBlock)completion;

#pragma mark - Reset to factory settings
///--------------------------------------------------------------------
/// @name Reset to factory settings
///--------------------------------------------------------------------

/**
 * Resets the beacon's `<major>`, `<minor>`, `<proximityUUID>`, broadcasting `<power>` and `<advInterval>` to factory settings.
 *
 * @param completion A block that is called when the settings have been reset.
 *
 * The completion block receives the following parameters:
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @warning This method does not reset the `<motionProximityUUID>`. You can reset it yourself to the default value of `ESTIMOTE_PROXIMITY_UUID` using the `<writeMotionProximityUUID:completion:>` method.
 */
- (void)resetToFactorySettingsWithCompletion:(ESTCompletionBlock)completion;

#pragma mark - MAC & Peripheral

/**
 *  Allows to get MAC address.
 *
 *  @param completion completion block returning reference to ESTBeaconConnection object performing operation.
 */
- (void)getMacAddressWithCompletion:(ESTStringCompletionBlock)completion;

/**
 *  Allows to find CBPeripheral device using CBCentralManager scan.
 *
 *  @param timeout    timeout of scan operation
 *  @param completion completion block returning reference to ESTBeaconConnection object performing operation.
 */
- (void)findPeripheralForBeaconWithTimeout:(NSUInteger)timeout completion:(ESTObjectCompletionBlock)completion;

#pragma mark - Firmware update
///--------------------------------------------------------------------
/// @name Firmware update
///--------------------------------------------------------------------

/**
 * Checks if an updated firmware is available.
 *
 * The result of the check is available as a `ESTFirmwareInfoVO` class in the completion block and has the following properties:
 *
 * - `BOOL isUpdateAvailable` - YES if an update is available, NO if there's no update available. In the latter case, all the other properties of this structure will be `nil`.
 *
 * - `NSString *hardwareVersion` - The version of hardware this firmware update is dedicated for.
 *
 * - `NSString *firmwareVersion` - The version of the firmware available for update.
 *
 * - `NSString *changelog` - Changes introduced in the new version.
 *
 * @param completion A block that is called when the check has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - `ESTFirmwareInfoVO value` - Indicates whether an update is available. If so, it also holds additional information about the update.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)checkFirmwareUpdateWithCompletion:(ESTObjectCompletionBlock)completion;

/**
 * Updates the beacon's firmware.
 *
 * @param progress A block that is called throughout the update process to report on the progress.
 *
 * The progress block receives the following parameters:
 *
 * - `NSInteger value` - A percentage value (0-100) indicating the update progress.
 *
 * - `NSString *description` - A description of the current stage of the update.
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 *
 * @param completion A block that is called when the update has been completed.
 *
 * The completion block receives the following parameters:
 *
 * - `NSError *error` - If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)updateFirmwareWithProgress:(ESTProgressBlock)progress
                        completion:(ESTCompletionBlock)completion;

/**
 * Returns value object for current `ESTBeaconConnection` object.
 */
- (ESTBeaconVO *)valueObject;

@end

NS_ASSUME_NONNULL_END
