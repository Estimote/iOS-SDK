//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTSettingReadWrite.h"

#define ESTSettingStorageCurrentPointerPositionErrorDomain @"ESTSettingStorageCurrentPointerPositionErrorDomain"


@class ESTSettingStorageCurrentPointerPosition;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting CurrentPointerPosition operation for Storage packet.
 *
 *  @param currentPointerPositionSetting CurrentPointerPosition setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingStorageCurrentPointerPositionCompletionBlock)(ESTSettingStorageCurrentPointerPosition * _Nullable currentPointerPositionSetting, NSError * _Nullable error);


/**
 *  ESTSettingStorageCurrentPointerPosition represents Storage CurrentPointerPosition value.
 */
@interface ESTSettingStorageCurrentPointerPosition : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingStorageCurrentPointerPosition validationErrorForValue:]
 *
 *  @param currentPointerPosition Storage CurrentPointerPosition value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint32_t)currentPointerPosition;

/**
 *  Returns current value of Storage CurrentPointerPosition setting.
 *
 *  @return Storage CurrentPointerPosition value.
 */
- (uint32_t)getValue;

/**
 *  Method allows to read value of initialized Storage CurrentPointerPosition setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingStorageCurrentPointerPositionCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Storage CurrentPointerPosition setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param currentPointerPosition CurrentPointerPosition value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint32_t)currentPointerPosition completion:(ESTSettingStorageCurrentPointerPositionCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
