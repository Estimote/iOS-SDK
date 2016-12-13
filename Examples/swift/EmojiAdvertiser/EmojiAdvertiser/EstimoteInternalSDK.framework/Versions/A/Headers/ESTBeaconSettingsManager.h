//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTPeripheralTypeUtility.h"
#import "ESTDeviceSettingsCollection.h"
#import "ESTSettingsIBeacon.h"
#import "ESTSettingsEstimoteLocation.h"
#import "ESTSettingsEstimoteTLM.h"
#import "ESTSettingsEddystoneUID.h"
#import "ESTSettingsEddystoneURL.h"
#import "ESTSettingsEddystoneTLM.h"
#import "ESTSettingsEddystoneEID.h"
#import "ESTSettingsDeviceInfo.h"
#import "ESTSettingsPower.h"
#import "ESTSettingsGPIO.h"
#import "ESTSettingConnectivityInterval.h"
#import "ESTSettingsConnectivity.h"
#import "ESTSettingsSensors.h"
#import "ESTSettingsEddystoneConfigurationService.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Error domain for ESTDeviceSettingsManager class.
 */
#define ESTDeviceSettingsManagerErrorDomain @"ESTDeviceSettingsManagerErrorDomain"

typedef void(^ESTDeviceSettingsManagerSyncCompletionBlock)(NSError * _Nullable error);

/**
 *  Block used as a result of all operation success or failure of one of them.
 *
 *  @see performOperationsFromArray:completion:
 *
 *  @param error Error of operation. No error means success.
 */
typedef void(^ESTDeviceSettingsManagerOperationsCompletionBlock)(NSError * _Nullable error);

/**
 *  Settings related errors.
 */
typedef NS_ENUM(NSInteger, ESTDeviceSettingsManagerError)
{
    /**
     *  Settings synchronization is already in progress for the device.
     */
    ESTDeviceSettingsManagerErrorSynchronizationInProgress,
    /**
     *  Settings is not support by the device.
     */
    ESTDeviceSettingsManagerErrorSettingNotSupported,
    /**
     *  Settings is not provided for write operation.
     */
    ESTDeviceSettingsManagerErrorSettingNotProvidedForWrite,
    /**
     *  Validation failed for another setting provided in the group.
     */
    ESTDeviceSettingsManagerErrorSettingValidationFailed,
    
    /**
     *  Reading setting value from Estimote Cloud failed.
     */
    ESTDeviceSettingsManagerErrorSettingCloudReadFailed,
    
    /**
     *  Saving new value of settings in Estimote Cloud failed.
     */
    ESTDeviceSettingsManagerErrorSettingCloudSaveFailed
};


/**
 *  ESTDeviceSettingsManager allows to manager device settings interaction
 *  like writing to peripheral and saving to the Estimote Cloud.
 */
@interface ESTBeaconSettingsManager : NSObject

/**
 *  Available collection of device settings.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettingsCollection *settingsCollection;

#pragma mark - Convenience Settings API
///--------------------------------------------------------------------
/// @name Convenience Settings API
///--------------------------------------------------------------------

/**
 *  Group of settings related to Device info configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsDeviceInfo *deviceInfo;

/**
 *  Group of settings related to Power management.
 */
@property (nonatomic, strong, readonly) ESTSettingsPower *power;

/**
 *  Group of settings related to Connectivity packet.
 */
@property (nonatomic, strong, readonly) ESTSettingsConnectivity *connectivity;

/**
 *  Group of settings related to Apple iBeacon packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsIBeacon *iBeacon;

/**
 *  Group of settings related to Estimote Location packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsEstimoteLocation *estimoteLocation;

/**
 *  Group of settings related to Estimote Telemetry packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsEstimoteTLM *estimoteTLM;

/**
 *  Group of settings related to Eddystone UID packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsEddystoneUID *eddystoneUID;

/**
 *  Group of settings related to Eddystone URL packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsEddystoneURL *eddystoneURL;

/**
 *  Group of settings related to Eddystone TLM packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsEddystoneTLM *eddystoneTLM;

/**
 * Group of settings related to Eddystone EID packet configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsEddystoneEID *eddystoneEID;

/**
 *  Group of settings related to device GPIO configuration.
 */
@property (nonatomic, strong, readonly) ESTSettingsGPIO *GPIO;

/**
 *  Group of settings related to device sensors.
 */
@property (nonatomic, strong, readonly) ESTSettingsSensors *sensors;

/**
 *  Group of settings related to Generic Attribute Profile.
 */
@property (nonatomic, strong, readonly) ESTSettingsEddystoneConfigurationService *eddystoneConfigurationService;


#pragma mark - Advanced Settings API
///--------------------------------------------------------------------
/// @name Advanced Settings API
///--------------------------------------------------------------------

/**
 *  Method allows to perform single setting read/write operation
 *
 *  @param operation Setting operation.
 */
- (void)performOperation:(id <ESTBeaconOperationProtocol>)operation;

/**
 *  Method allows to perform few setting read/write operations.
 *
 *  @param firstOperation First setting operation.
 */
- (void)performOperations:(id<ESTBeaconOperationProtocol>)firstOperation, ...;

/**
 *  Method allows to perform group of setting read/write operations provided in an array.
 *
 *  @param operationsArray Array of setting operations.
 */
- (void)performOperationsFromArray:(NSArray<id<ESTBeaconOperationProtocol>> *)operationsArray;

/**
 *  Method allows to perform group of setting read/write operations provided in an array.
 *
 *  @param operationsArray Array of setting operations.
 *  @param completion Completion block that should be executed after all operations succeed or any of the operation fails.
 */
- (void)performOperationsFromArray:(NSArray<id<ESTBeaconOperationProtocol>> *)operationsArray completion:(ESTDeviceSettingsManagerOperationsCompletionBlock _Nullable)completion;

#pragma mark Notifications
///--------------------------------------------------------------------
/// @name Notifications
///--------------------------------------------------------------------

/*
 *  Registers notification object for watching. Its callback would be fired each time the device sents notification data.
 *
 *  Note that the device has to be in connected state in order for notifications to work.
 */
- (void)registerNotification:(id <ESTDeviceNotificationProtocol>)notification;

/**
 *  Stop calling handle blocks for previously registered notifications by clearing the notification registry.
 */
- (void)unregisterAllNotifications;

@end


@class ESTDeviceLocationBeacon;

@interface ESTBeaconSettingsManager (Internal)

/**
 *  Method allows to initialize object with device and peripheral.
 *
 *  @param device     Device to be managed (not retained).
 *  @param peripheral Peripheral implementing `ESTPeripheralConfigurable` protocol.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDevice:(ESTDeviceLocationBeacon *)device peripheral:(ESTPeripheralTypeUtility *)peripheral;

/*
 *  Method allows to localy initialise settings.
 *
 *  As a result of this operation `settingsCollection` property if updated
 *  with firmware application version.
 *
 *  @param completion Block invoked when operation is complete.
 */
- (void)initializedOfflineSettingsWithCompletion:(ESTDeviceSettingsManagerSyncCompletionBlock)completion;

/*
 *  Method allows to synchronise all device settings with Estimote Cloud.
 *
 *  Synchronisation takes all the settings (including pending settings)
 *  from Estimote Cloud and writes them to the device. Each write operation
 *  confirms its result in the Estimote Cloud.
 *
 *  As a result of this operation `settingsCollection` property if updated
 *  with most recent settings.
 *
 *  @param completion Block invoked when operation is complete.
 */
- (void)synchronizeSettingsWithCompletion:(ESTDeviceSettingsManagerSyncCompletionBlock)completion;

/**
 *  Method allows to update peripheral kept by this class as weak reference.
 *
 *  @param peripheral Updated peripheral.
 */
- (void)updatePeripheral:(ESTPeripheralTypeUtility *)peripheral;

/**
 *  Method allows to update particular setting.
 *
 *  @param setting Setting to update.
 */
- (void)updateSetting:(ESTSettingBase *)setting;

@end

NS_ASSUME_NONNULL_END
