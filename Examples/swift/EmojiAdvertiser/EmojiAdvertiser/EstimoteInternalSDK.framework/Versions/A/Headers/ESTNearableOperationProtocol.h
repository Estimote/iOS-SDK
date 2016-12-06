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
#import "ESTSettingOperation.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationProtocol has to be implemented by all nearable setting
 *  operation classes to be compatible with Estimote device API.
 */
@protocol ESTNearableOperationProtocol <NSObject>

/**
 *  Defines if the operation is read or write.
 *
 *  @return Operation type.
 */
- (ESTSettingOperationType)type;

/**
 *  Defines if operation comes only from Cloud, device or both.
 */
- (ESTSettingStorageType)storageType;

/**
 *  Device register identifier specified in the Nearable Bluetooth
 *  communication protocol.
 *
 *  @return Register identifier.
 */
- (uint16_t)registerID;

/**
 *  Serialized setting value data to be written to the device. 
 *  Specified in the Nearable Bluetooth communication protocol.
 *
 *  @return Value data.
 */
- (NSData *)valueData;

/**
 *  Serialized setting data size specified in the Nearable Bluetooth 
 *  communication protocol. It's not the same as NSData length.
 *
 *  @return Setting data size.
 */
- (NSInteger)valueDataSize;

/**
 *  Oldest firmware version that supports this operation's setting.
 *
 *  @return Semver string.
 */
- (NSString *)supportedFirmwareVersion;

/**
 *  Setting to be written or read by executing this operation.
 *
 *  @return Setting subclass.
 */
- (ESTSettingBase *)getSetting;

/**
 *  Method allows to update setting.
 *
 *  @param data Data that should be used to update setting.
 */
- (void)updateSetting:(ESTSettingBase *)setting;

/**
 *  Defines this operation's associated setting class.
 *  Must be a subclass of ESTSettingBase.
 *
 *  @return Setting class.
 */
- (Class)settingClass;

/**
 *  Method indicates if particular operation should be synchronized
 *  with Estimote Cloud while performing.
 *
 *  @return Flag indicating synchronization.
 */
- (BOOL)shouldSynchronize;

/**
 *  Block to be invoked after the operation is executed successfully.
 */
- (void)fireSuccessBlock;

/**
 *  Block to be invoked after the operation fails.
 *
 *  @param error Error Describing failure reason.
 */
- (void)fireFailureBlockWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
