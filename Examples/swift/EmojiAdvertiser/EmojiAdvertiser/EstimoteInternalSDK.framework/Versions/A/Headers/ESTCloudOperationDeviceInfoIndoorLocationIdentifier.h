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
#import "ESTSettingOperation.h"
#import "ESTCloudOperationProtocol.h"
#import "ESTSettingDeviceInfoIndoorLocationIdentifier.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationDeviceInfoIndoorLocationIdentifier allows to create read operations for DeviceInfo IndoorLocationIdentifier setting of a device.
 */
@interface ESTCloudOperationDeviceInfoIndoorLocationIdentifier : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo IndoorLocationIdentifier setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoIndoorLocationIdentifierCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
