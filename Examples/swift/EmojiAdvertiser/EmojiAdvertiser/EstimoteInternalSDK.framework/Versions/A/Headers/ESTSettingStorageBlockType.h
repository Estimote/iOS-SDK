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

#define ESTSettingStorageBlockTypeErrorDomain @"ESTSettingStorageBlockTypeErrorDomain"

@class ESTSettingStorageBlockType;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting BlockType operation for Storage packet.
 *
 *  @param blockTypeSetting BlockType setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingStorageBlockTypeCompletionBlock)(ESTSettingStorageBlockType * _Nullable blockTypeSetting, NSError * _Nullable error);


/**
 *  ESTSettingStorageBlockType represents Storage BlockType value.
 */
@interface ESTSettingStorageBlockType : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingStorageBlockType validationErrorForValue:]
 *
 *  @param blockType Storage BlockType value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint8_t)blockType;

/**
 *  Returns current value of Storage BlockType setting.
 *
 *  @return Storage BlockType value.
 */
- (uint8_t)getValue;

/**
 *  Method allows to read value of initialized Storage BlockType setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingStorageBlockTypeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Storage BlockType setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param blockType BlockType value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(uint8_t)blockType completion:(ESTSettingStorageBlockTypeCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
