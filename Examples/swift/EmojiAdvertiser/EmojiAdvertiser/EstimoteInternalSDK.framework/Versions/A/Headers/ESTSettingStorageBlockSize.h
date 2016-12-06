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
#import "ESTSettingReadOnly.h"

@class ESTSettingStorageBlockSize;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting BlockSize operation for Storage packet.
 *
 *  @param blockSizeSetting BlockSize setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingStorageBlockSizeCompletionBlock)(ESTSettingStorageBlockSize * _Nullable blockSizeSetting, NSError * _Nullable error);


/**
 *  ESTSettingStorageBlockSize represents Storage BlockSize value.
 */
@interface ESTSettingStorageBlockSize : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param blockSize Storage BlockSize value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(uint32_t)blockSize;

/**
 *  Returns current value of Storage BlockSize setting.
 *
 *  @return Storage BlockSize value.
 */
- (uint32_t)getValue;

/**
 *  Method allows to read value of initialized Storage BlockSize setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingStorageBlockSizeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
