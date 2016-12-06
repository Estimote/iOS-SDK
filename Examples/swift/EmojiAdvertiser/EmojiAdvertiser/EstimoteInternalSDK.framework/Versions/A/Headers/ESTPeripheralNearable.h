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
#import "ESTPeripheral.h"
#import "ESTDefinitions.h"
#import "ESTNearableOperationProtocol.h"

#define ESTPeripheralNearableErrorDomain @"ESTPeripheralNearableErrorDomain" 

typedef NS_ENUM(NSInteger, ESTPeripheralNearableError)
{
    ESTPeripheralNearableErrorUnknown,
    ESTPeripheralNearableErrorInvalidOperation,
    ESTPeripheralNearableErrorTimeoutReached,
    ESTPeripheralNearableErrorPacketError
};

/**
 *  ESTPeripheralNearable delegate protocol.
 */
@protocol ESTPeripheralNearableDelegate <NSObject>

/**
 *  Method invoked after single operation was performed with the device successfully.
 *
 *  @param peripheral Peripheral object that performed operation.
 *  @param operation  Operation that was performed.
 *  @param data       Data received from the device to be deserialized.
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didPerformOperation:(id<ESTNearableOperationProtocol>)operation andReceivedData:(NSData *)data;

/**
 *  Method invoked after single operation failed while communicating with the device.
 *
 *  @param peripheral Peripheral object that tried to perform operation.
 *  @param operation  Operation that was to be performed.
 *  @param error      Error explaining the failure reason.
 */
- (void)peripheral:(id<ESTPeripheral>)peripheral didFailOperation:(id<ESTNearableOperationProtocol>)operation withError:(NSError *)error;

@end


@interface ESTPeripheralNearable : NSObject <ESTPeripheral>

@property (nonatomic, readonly) CBPeripheral *peripheral;
@property (nonatomic, weak) id<ESTPeripheralNearableDelegate> delegate;

#pragma mark - Authorization

- (void)readAuthorizationSeedWithCompletion:(ESTObjectCompletionBlock)completion;

- (void)writeAuthorizationSeed:(NSData *)seed
                    completion:(ESTObjectCompletionBlock)completion;

- (void)writeAuthorizationSource:(NSData *)seed
                      completion:(ESTObjectCompletionBlock)completion;

//- (void)readCharacteristicForSetting:(id<ESTDeviceSettingProtocol>)setting;

#pragma mark - Nearable Operations

- (void)performNearableOperation:(id<ESTNearableOperationProtocol>)nearableOperation;

#pragma mark - OTA Update

- (void)otaEraseWithCompletion:(ESTCompletionBlock)completion;
- (void)otaVerifyWithCompletion:(ESTCompletionBlock)completion;
- (void)otaWriteFirmwareChunk:(NSData *)chunk completion:(ESTObjectCompletionBlock)completion;
- (void)otaCommandReboot;

@end
