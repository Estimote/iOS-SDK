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
#import "ESTSettingPowerFlipToSleepEnable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationPowerFlipToSleepEnable allows to create read/write operations for DeviceInfo FlipToSleepEnable setting of a device.
 */
@interface ESTBeaconOperationPowerFlipToSleepEnable : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for DeviceInfo FlipToSleepEnable setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingPowerFlipToSleepEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation for DeviceInfo FlipToSleepEnable setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingPowerFlipToSleepEnable *)setting completion:(ESTSettingPowerFlipToSleepEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
