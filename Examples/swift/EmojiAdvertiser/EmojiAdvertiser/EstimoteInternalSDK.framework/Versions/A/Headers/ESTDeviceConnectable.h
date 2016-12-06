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
#import "ESTDevice.h"
#import "ESTDefinitions.h"
#import "ESTDeviceSettingProtocol.h"
#import "ESTCloudSettingProtocol.h"
#import "ESTDeviceNotificationProtocol.h"
#import "ESTBeaconOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ESTDeviceFirmwareUpdateProgressBlock)(NSInteger value);

@class ESTDeviceConnectable;


/**
 *  ESTDeviceConnectableDelegate defines protocol for ESTDeviceConnectable delegate object.
 */
@protocol ESTDeviceConnectableDelegate <NSObject>

@optional

/**
 *  Method invoked when connection to device was successful.
 *
 *  @param device Device connection was established with.
 */
- (void)estDeviceConnectionDidSucceed:(ESTDeviceConnectable *)device;

/**
 *  Method invoked when device disconnect event occurred.
 *
 *  @param device Disconnected device.
 *  @param error  Error representing reason of disconnect.
 */
- (void)estDevice:(ESTDeviceConnectable *)device didDisconnectWithError:(NSError * _Nullable)error;

/**
 *  Method invoked when connection to device failed.
 *
 *  @param device Device connection failed for.
 *  @param error  Error representing reason of failure.
 */
- (void)estDevice:(ESTDeviceConnectable *)device didFailConnectionWithError:(NSError *)error;

@end


/**
 *  ESTDeviceConnectable is a superclass for connectable Estimote devices.
 */
@interface ESTDeviceConnectable : ESTDevice

/**
 *  Delegate object that will get method calls related to connection.
 */
@property (nonatomic, weak) id <ESTDeviceConnectableDelegate> _Nullable delegate;

/**
 *  Status of device connection.
 */
@property (nonatomic, assign, readonly) ESTConnectionStatus connectionStatus;

#pragma mark Connectivity
///--------------------------------------------------------------------
/// @name Connectivity
///--------------------------------------------------------------------

/**
 *  Perform connection to the device.
 */
- (void)connect;

/**
 *  Perform connection to the device with automatic firmware update.
 */
- (void)connectAndUpdate;

/**
 * Cancel connection to the device.
 */
- (void)disconnect;

#pragma mark Firmware update
///--------------------------------------------------------------------
/// @name Firmware update
///--------------------------------------------------------------------

/**
 *  Allows to validate firmware update availability.
 *
 *  @param completion Blocked invoked when validation is complete.
 */
- (void)checkFirmwareUpdateWithCompletion:(ESTObjectCompletionBlock)completion;

/**
 *  Allows to perform firmware update of the device Over The Air. 
 *  Keep in mind that established bluetooth connection
 *  is required to perform firmware update.
 *
 *  @param progress   Block invoked on firmware update progress.
 *  @param completion Block invoked on firmware update complete.
 */
- (void)updateFirmwareWithProgress:(ESTDeviceFirmwareUpdateProgressBlock)progress
                        completion:(ESTCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
