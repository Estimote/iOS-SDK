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
#import "ESTBeaconOperationProtocol.h"
#import "ESTPeripheral.h"
#import "ESTDefinitions.h"
#import "ESTDeviceNotificationProtocol.h"

#define ESTPeripheralTypeUtilityErrorDomain @"ESTPeripheralTypeUtilityErrorDomain"

typedef NS_ENUM(NSInteger, ESTPeripheralTypeUtilityError)
{
    ESTPeripheralTypeUtilityErrorReadWriteOperationFailed,
    ESTPeripheralTypeUtilityErrorPacketGenerationFailed,
    ESTPeripheralTypeUtilityErrorPacketError
};

/**
 *  State of device firmware.
 */
typedef NS_ENUM(NSInteger, ESTPeripheralFirmwareState) {
    /**
     *  Unknown state.
     */
    ESTPeripheralFirmwareStateUnknown,
    /**
     *  Bootloader state. Ready to be updated Over The Air.
     */
    ESTPeripheralFirmwareStateBoot,
    /**
     *  Application state. Ready to interact with settings.
     */
    ESTPeripheralFirmwareStateApp
};


/**
 *  ESTPeripheralTypeUtility delegate protocol.
 */
@protocol ESTPeripheralTypeUtilityDelegate <NSObject>

/**
 *  Method invoked after single operation was performed with the device successfully.
 *
 *  @param peripheral Peripheral object that performed operation.
 *  @param operation  Operation that was performed.
 *  @param data       Data received from the device to be deserialized.
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didPerformOperation:(id<ESTBeaconOperationProtocol>)operation andReceivedData:(NSData *)data;

/**
 *  Method invoked after single operation failed while communicating with the device.
 *
 *  @param peripheral Peripheral object that tried to perform operation.
 *  @param operation  Operation that was to be performed.
 *  @param error      Error explaining the failure reason.
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didFailOperation:(id<ESTBeaconOperationProtocol>)operation withError:(NSError *)error;

@end


/**
 *  ESTPeripheralTypeUtility is a wrapper around CBPeripheral object of beacon device.
 *  It allows to perform bluetooth only read/write operation on the device and reboot device;.
 */
@interface ESTPeripheralTypeUtility : NSObject <ESTPeripheral>

/**
 *  Flag indicates what is current firmware state (Unknown, App, Boot).
 */
@property (nonatomic, readonly) ESTPeripheralFirmwareState firmwareState;

/**
 *  Delegate object for `ESTPeripheralTypeUtility` class object.
 */
@property (nonatomic, strong) id<ESTPeripheralTypeUtilityDelegate> delegate;

/**
 *  Delegate object to be informed about device notification event.
 */
@property (nonatomic, weak) id<ESTPeripheralNotificationDelegate> notificationDelegate;

/**
 *  Restart device and put it into boot mode, what allows to perform
 *  Over The Air update.
 *
 *  @param completion Blocked invoked when reset is complete.
 */
- (void)resetPeripheralToBootWithCompletion:(ESTCompletionBlock)completion;

/**
 *  Perform read/write operation for setting.
 *
 *  @param operation Operation that should be performed.
 */
- (void)performSettingOperation:(id<ESTBeaconOperationProtocol>)operation;

/**
 *  Register for notifications from device provided during connection.
 *
 *  @param notification Notification we should register for.
 */
- (void)registerNotification:(id<ESTDeviceNotificationProtocol>)notification;

- (void)unregisterAllNotifications;

@end
