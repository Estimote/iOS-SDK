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
#import "ESTSettingStorageMaximumSize.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingOperationStorageMaximumSize allows to create read/write operations for Storage MaximumSize setting of a device.
 */
@interface ESTSettingOperationStorageMaximumSize : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Storage MaximumSize setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingStorageMaximumSizeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END