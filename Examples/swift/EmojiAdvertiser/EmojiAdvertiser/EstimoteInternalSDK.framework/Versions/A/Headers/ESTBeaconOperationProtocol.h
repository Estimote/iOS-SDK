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

@class ESTSettingBase;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Possible types of setting operation.
 */
typedef NS_ENUM(NSInteger, ESTSettingOperationType)
{
    /**
     *  Read operation.
     */
    ESTSettingOperationTypeRead,
    /**
     *  Write operation.
     */
    ESTSettingOperationTypeWrite
};

/**
 *  Parameter describing source of operation.
 */
typedef NS_ENUM(NSUInteger, ESTSettingStorageType)
{
    ESTSettingStorageTypeDeviceCloud,
    ESTSettingStorageTypeCloudOnly,
    ESTSettingStorageTypeDeviceOnly
};


/**
 *  ESTSettingOperationProtocol has to be implemented by all setting
 *  operation classes to be compatible with Estimote device API.
 */
@protocol ESTBeaconOperationProtocol <NSObject>

@required

/**
 *  Type of operation (read or write).
 *
 *  @return Type described by enum.
 */
- (ESTSettingOperationType)type;

/**
 *  Defines if operation comes only from Cloud, device or both.
 */
- (ESTSettingStorageType)storageType;

/**
 *  Device register ID for setting.
 *
 *  @return ID of register.
 */
- (uint16_t)registerID;

/**
 *  Data represented as NSData should be stored in the device.
 *
 *  @return Data value.
 */
- (NSData *)valueData;

/**
 *  Method returns value of setting.
 *
 *  @return Value of setting. Type of value depends on the setting.
 */
- (id)valueCloud;

/**
 *  Lowest firmware version supporting setting.
 *
 *  @return Version of firmware.
 */
- (NSString *)supportedFirmwareVersion;

/**
 *  Method indicates if particular operation should be synchronized
 *  with Estimote Cloud while performing.
 *
 *  @return Flag indicating synchronization.
 */
- (BOOL)shouldSynchronize;

/**
 *  Method returns copy of the setting associated with this operation.
 *
 *  @return Setting object, i.e. of class ESTSettingIBeaconMajor.
 */
- (ESTSettingBase *)getSetting;

/**
 *  Method allows to update setting.
 *
 *  @param data Data that should be used to update setting.
 */
- (void)updateSettingWithData:(NSData *)data;

/**
 *  Method invoked when read/write operation finished with success.
 *
 *  @param result Result of read/write operation.
 */
- (void)fireSuccessBlockWithData:(NSData *)result;

/**
 *  Method invoked when read/write operation failed.
 *
 *  @param error NSError containing failure information.
 */
- (void)fireFailureBlockWithError:(NSError *)error;

@optional

/**
 *  All the operations that should be performed together with main one.
 *
 *  @return Array of associated operations.
 */
- (NSArray<id<ESTBeaconOperationProtocol>> *)associatedOperations;

@end

NS_ASSUME_NONNULL_END
