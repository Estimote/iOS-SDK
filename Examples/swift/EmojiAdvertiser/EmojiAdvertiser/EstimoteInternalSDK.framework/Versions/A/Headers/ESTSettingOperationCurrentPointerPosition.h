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
#import "ESTSettingStorageCurrentPointerPosition.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperationCurrentPointerPosition allows to create read/write operations for Storage CurrentPointerPosition setting of a device.
 */
@interface ESTSettingOperationCurrentPointerPosition : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Storage CurrentPointerPosition setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingStorageCurrentPointerPositionCompletionBlock)completion;

/**
 *  Method allows to create write operation for Storage CurrentPointerPosition setting.
 *
 *  @param setting    Setting to be written to a device.
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationWithSetting:(ESTSettingStorageCurrentPointerPosition *)setting completion:(ESTSettingStorageCurrentPointerPositionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END