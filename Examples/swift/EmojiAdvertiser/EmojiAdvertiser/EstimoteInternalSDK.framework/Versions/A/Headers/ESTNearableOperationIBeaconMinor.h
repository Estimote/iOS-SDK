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
#import "ESTSettingIBeaconMinor.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTNearableOperationIBeaconMinor allows to create read/write operations for Settings IBeaconMinor setting of a device.
 */
@interface ESTNearableOperationIBeaconMinor : ESTSettingOperation <ESTNearableOperationProtocol>

/**
 *  Method allows to create read operation for Settings IBeaconMinor setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingIBeaconMinorCompletionBlock)completion;

/**
 *  Method allows to create write operation for Settings IBeaconMinor setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingIBeaconMinor *)setting completion:(ESTSettingIBeaconMinorCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
