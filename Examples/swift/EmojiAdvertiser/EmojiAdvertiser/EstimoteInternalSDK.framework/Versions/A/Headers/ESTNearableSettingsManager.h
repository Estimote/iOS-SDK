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
#import "ESTNearableOperationProtocol.h"
#import "ESTPeripheralNearable.h"

@class ESTPeripheralNearable;
@class ESTDeviceSettingsCollection;
@class ESTDeviceNearable;
@class ESTNearableVO;

#define ESTNearableSettingsManagerErrorDomain @"ESTNearableSettingsManagerErrorDomain" 

typedef NS_ENUM(NSUInteger, ESTNearableSettingsManagerError)
{
    /**
     *  Settings synchronization is already in progress for the device.
     */
    ESTNearableSettingsManagerErrorSynchronizationInProgress,
    /**
     *  Settings is not support by the device.
     */
    ESTNearableSettingsManagerErrorSettingNotSupported,
    /**
     *  Settings is not provided for write operation.
     */
    ESTNearableSettingsManagerErrorSettingNotProvidedForWrite,
    /**
     *  Validation failed for another setting provided in the group.
     */
    ESTNearableSettingsManagerErrorSettingValidationFailed,
    
    /**
     *  Reading setting value from Estimote Cloud failed.
     */
    ESTNearableSettingsManagerErrorSettingCloudReadFailed,
    
    /**
     *  Could not save nearable settings in Cloud.
     */
    ESTNearableSettingsManagerErrorCloudSaveFailed
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableSettingsManager allows to manage device settings interaction
 *  like writing to peripheral and saving to the Estimote Cloud.
 */
@interface ESTNearableSettingsManager : NSObject <ESTPeripheralNearableDelegate>

/**
 *  Flat key-value settings container.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettingsCollection *settingsCollection;

/**
 *  Method executes provided Nearable Operation.
 *
 *  @param operation Nearable Operation to be performed.
 */
- (void)performOperation:(id<ESTNearableOperationProtocol>)operation;

/**
 *  Method executes provided Nearable Operation.
 *
 *  @param operations Nearable Operations to be performed.
 */
- (void)performOperationsFromArray:(NSArray<id<ESTNearableOperationProtocol>> *)operations;

@end


@interface ESTNearableSettingsManager (Internal)

/**
 *  Designated initializer.
 *
 *  @param device     Nearable object required by the convenience API to work.
 *  @param peripheral Peripheral used for Bluetooth communication.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDevice:(ESTDeviceNearable *)device peripheral:(ESTPeripheralNearable *)peripheral;

/**
 *  Performs settings synchronization during the connection process. Writes to the device settings fetched from cloud.
 *
 *  @param nearableVO      Value Object representing setting values fetched from Cloud.
 *  @param firmwareVersion Device firmware version used to ignore unsupported setting operations.
 *  @param completion      Synchronization completion block.
 */
- (void)synchronizeUsingNearableVO:(ESTNearableVO *)nearableVO forFirmwareVersion:(NSString *)firmwareVersion completion:(void(^)())completion;

@end

NS_ASSUME_NONNULL_END
