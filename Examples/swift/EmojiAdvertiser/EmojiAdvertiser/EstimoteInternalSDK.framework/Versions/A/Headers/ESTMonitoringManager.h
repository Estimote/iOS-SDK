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
#import "ESTMonitoringZone.h"

@class ESTMonitoringManager;

NS_ASSUME_NONNULL_BEGIN

#define ESTMonitoringManagerErrorDomain @"ESTMonitoringManagerErrorDomain"

/**
 * Possible errors generated while using Monitoring Manager related to Bluetooth or Estimote Cloud.
 */
typedef NS_ENUM(NSInteger, ESTMonitoringManagerError)
{
    /**
     * The platform does not support Bluetooth low energy. 
     */
    ESTMonitoringManagerErrorBluetoothNotSupported = 1,
    /**
     * The app is not authorized to use Bluetooth low energy. 
     */
    ESTMonitoringManagerErrorUnauthorizedToUseBluetooth = 2,
    /**
     * Bluetooth is currently powered off.
     */
    ESTMonitoringManagerErrorBluetoothOff = 3,
    /**
     * Error was encountered during Estimote Cloud connection attempt.
     */
    ESTMonitoringManagerErrorConnectionFail = -1,
    /**
     * No data was returned as a response or it couldn't be parsed as JSON.
     */
    ESTMonitoringManagerErrorNoData = -2,
    /**
     * Estimote Cloud cannot or will not process the request due to an apparent client error.
     */
    ESTMonitoringManagerErrorBadRequest = 400,
    /**
     * Estimote Cloud is refusing to respond to the request, authorization is required for the resource.
     */
    ESTMonitoringManagerErrorUnauthorized = 401,
    /**
     * Estimote Cloud is refusing to respond to the request, the user does not have the necessary permissions for the resource.
     */
    ESTMonitoringManagerErrorForbidden = 403,
    /**
     * The requested resource could not be found.
     */
    ESTMonitoringManagerErrorNotFound = 404,
    /**
     * Estimote Cloud failed to properly handle the request.
     */
    ESTMonitoringManagerErrorInternalServerError = 500,
};


/**
 *  Describes messages sent from Monitoring Manager to its delegate object.
 */
@protocol ESTMonitoringManagerDelegate <NSObject>

/**
 *  Tells the delegate that the user entered proximity of monitored device.
 *
 *  @param manager    The monitoring manager reporting the event
 *  @param identifier Device identifier broadcasted in the Estimote Location packet that triggered the enter event.
 */
@optional
- (void)monitoringManager:(ESTMonitoringManager *)manager didEnterRangeOfIdentifier:(NSString *)identifier;

/**
 *  Tells the delegate that the user entered proximity of monitored device.
 *
 *  @param manager    The monitoring manager reporting the event
 *  @param identifier Device identifier broadcasted in the Estimote Location packet that triggered the exit event.
 */
@optional
- (void)monitoringManager:(ESTMonitoringManager *)manager didExitRangeOfIdentifier:(NSString *)identifier;

/**
 *  Tells the delegate that the manager started Bluetooth monitoring.
 *
 *  @param manager The monitoring manager reporting the event
 */
@optional
- (void)monitoringManagerDidStart:(ESTMonitoringManager *)manager;

/**
 *  Tells the delegate that the manager failed monitoring because of Estimote Cloud or Bluetooth related error.
 *  The error object's <code>code</code> is a case of <code>ESTMonitoringManagerError</code> enum.
 *  The error object's <code>domain</code> is <code>ESTMonitoringManagerErrorDomain</code>.
 *
 *  @param manager The monitoring manager reporting the event
 *  @param error   Error describing what went wrong.
 */
@optional
- (void)monitoringManager:(ESTMonitoringManager *)manager didFailWithError:(NSError *)error;

@end


/**
 *  ESTMonitoringManager handles monitoring Location Beacons on top of Estimote Location packet.
 *
 *  In order to monitor multiple devices a separate instance of Monitoring Manager should be created
 *  for each monitored device.
 *
 *  Estimote Monitoring uses Core Bluetooth and Core Location frameworks underneath. 
 *  To make it work when the app is in background, make sure following entries 
 *  are present in <code>Info.plist</code> file:
 
 *  - <code>bluetooth-central</code>
 
 *  - <code>NSBluetoothPeripheralUsageDescription</code>
 
 *  - <code>NSLocationAlwaysUsageDescription</code>
 *
 */
@interface ESTMonitoringManager : NSObject

/**
 *  Delegate object that monitoring callbacks will be sent to.
 */
@property (nonatomic, weak) id<ESTMonitoringManagerDelegate> delegate;

/**
 *  Starts reporting monitoring events for device broadcasting Estimote Location packet with given identifier.
 *  Fetches monitoring parameters from Estimote Cloud, uses them to provide best monitoring experience,
 *  calls <code>monitoringManagerdidStart</code> and starts reporting monitoring events.
 *
 *  If the fetch failed, starts reporting monitoring events using default parameters.
 *  
 *  Requests Core Location's Always Usage authorization.
 *
 *  Forgets previously monitored identifier if called multiple times on the same Monitoring Manager object.
 *
 *  @param identifier Estimote Location public id. Equal to device identifier in Estimote Cloud.
 *  @param proximity  Crossing monitoring proximity boundary causes monitoring events to happen. This is the proximity to be monitored.
 */
- (void)startMonitoringForIdentifier:(NSString *)identifier inProximity:(ESTMonitoringProximity)proximity;

/**
 *  Start reporting monitoring events for device broadcasting Estimote Location packet with given identifier.
 *  Uses default monitoring parameters.
 *
 *  Forgets previously monitored identifier if called multiple times on the same Monitoring Manager object.
 *
 *  @param identifier Estimote Location public id. Equal to device identifier in Estimote Cloud.
 */
- (void)startDefaultMonitoringForIdentifier:(NSString *)identifier;

/**
 *  Stop reporting monitoring events.
 */
- (void)stopMonitoring;

/**
 *  Increase monitoring responsiveness in background (experimental). Can cause increase in battery usage.
 */
- (void)startTurboMode;

/**
 *  Stop increasing responsiveness in background. Battery performance returns to normal.  
 */
- (void)stopTurboMode;

@end

NS_ASSUME_NONNULL_END
