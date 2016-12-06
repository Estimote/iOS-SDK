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

@class ESTDeviceConnectable;

/**
 * Possible statuses of `ESTSettingOperationStatus`
 */
typedef NS_ENUM(NSInteger, ESTSettingOperationStatus)
{
    /**
     *  The operation is in progress.
     */
    ESTSettingOperationStatusInProgress,
    
    /**
     *  The operation is complete.
     */
    ESTSettingOperationStatusComplete,
   
    /**
     *  The operation failed.
     */
    ESTSettingOperationStatusFailed
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperation represents base class for setting operations
 *  mainly responsible for handling operation type.
 */
@interface ESTSettingOperation : NSObject

/**
 *  Property describing the current operation status. 
 *  Note that it will only be updated if operation is executed 
 *  as a part of `ESTBeaconOperationsCollection`.
 */
@property (nonatomic, assign) ESTSettingOperationStatus status;

/**
 *  Designated initializer.
 *
 *  @param type Type of operation (read or write).
 *
 *  @return Instance of operation object.
 */
- (instancetype)initWithType:(ESTSettingOperationType)type;

/**
 *  Method returns type of setting operation.
 *
 *  @return Type of operation.
 */
- (ESTSettingOperationType)type;

/**
 *  Method used to determine where the setting is stored (Cloud database, device memory, or both).
 *  If not customized in subclass, defaults to ESTSettingStorageTypeDeviceCloud.
 *
 *  @return Setting storage type.
 */
- (ESTSettingStorageType)storageType;

@end


@interface ESTSettingOperation (Internal)

/**
 *  The device that operation should be performed on.
 *  Required for -readValueWithCompletion: and -writeValue:completion: methods to work.
 */
@property (nonatomic, weak) ESTDeviceConnectable *device;

@end

NS_ASSUME_NONNULL_END
