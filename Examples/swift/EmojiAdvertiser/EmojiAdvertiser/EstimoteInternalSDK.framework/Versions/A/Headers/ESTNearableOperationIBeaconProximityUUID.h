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
#import "ESTNearableOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingIBeaconProximityUUID.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationIBeaconProximityUUID allows to create read/write operations for Settings IBeaconProximityUUID setting of a device.
 */
@interface ESTNearableOperationIBeaconProximityUUID : ESTSettingOperation <ESTNearableOperationProtocol>

/**
 *  Method allows to create read operation for Settings IBeaconProximityUUID setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconProximityUUIDCompletionBlock)completion;

/**
 *  Method allows to create write operation for Settings IBeaconProximityUUID setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconProximityUUID *)setting completion:(ESTSettingIBeaconProximityUUIDCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
