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
#import "ESTSettingDeviceInfoName.h"
#import "ESTCloudOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationDeviceInfoName allows to create read/write operations for Device Info Name setting of a device.
 */
@interface ESTCloudOperationDeviceInfoName : ESTSettingOperation <ESTBeaconOperationProtocol, ESTCloudOperationProtocol>

/**
 *  Method allows to create read operation for Device Info Name setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingDeviceInfoNameCompletionBlock)completion;

/**
 *  Method allows to create write operation for Device Info Name setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingDeviceInfoName *)setting completion:(ESTSettingDeviceInfoNameCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
