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

#define ESTSettingStorageBlockCommandErrorDomain @"ESTSettingStorageBlockCommandErrorDomain"

/**
 *  Describes ESTSettingStorageBlockCommand possible values.
 */
typedef NS_ENUM(NSUInteger, ESTStorageBlockCommand)
{
    /**
     *  Block command for clearing data in Estimote Storage.
     */
    ESTStorageBlockCommandReset = 1
};

/**
 *  Describes StorageBlockCommand setting validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingStorageBlockCommandError)
{
    /**
     *  Provided value is out of range.
     */
    ESTSettingStorageBlockCommandErrorOutOfRange = 1
};

@class ESTSettingStorageBlockCommand;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting StorageBlockCommand operation for Storage packet.
 *
 *  @param storageBlockCommandSetting StorageBlockCommand setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingStorageBlockCommandCompletionBlock)(ESTSettingStorageBlockCommand * _Nullable storageBlockCommandSetting, NSError * _Nullable error);


/**
 *  ESTSettingStorageBlockCommand represents Storage StorageBlockCommand value.
 */
@interface ESTSettingStorageBlockCommand : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingStorageBlockCommand validationErrorForValue:]
 *
 *  @param storageBlockCommand Storage StorageBlockCommand value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTStorageBlockCommand)storageBlockCommand;

/**
 *  Returns current value of Storage StorageBlockCommand setting.
 *
 *  @return Storage StorageBlockCommand value.
 */
- (ESTStorageBlockCommand)getValue;

/**
 *  Method allows to create write operation from already initialized Storage StorageBlockCommand setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param storageBlockCommand StorageBlockCommand value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTStorageBlockCommand)storageBlockCommand completion:(ESTSettingStorageBlockCommandCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param storageBlockCommand StorageBlockCommand value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTStorageBlockCommand)storageBlockCommand;

@end

NS_ASSUME_NONNULL_END
