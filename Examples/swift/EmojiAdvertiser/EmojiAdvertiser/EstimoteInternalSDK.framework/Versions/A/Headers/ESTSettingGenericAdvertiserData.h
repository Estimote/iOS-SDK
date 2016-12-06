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
#import "ESTGenericAdvertiser.h"

#define ESTSettingGenericAdvertiserDataErrorDomain @"ESTSettingGenericAdvertiserDataErrorDomain"

/**
 *  Describes GenericAdvertiser GenericAdvertiserData validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingGenericAdvertiserDataError)
{
     /**
     *  Provided value is incorrect.
     */
    ESTSettingGenericAdvertiserDataErrorCanNotBeNil = 1
};

@class ESTSettingGenericAdvertiserData;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting GenericAdvertiserData operation for GenericAdvertiser packet.
 *
 *  @param genericAdvertiserDataSetting GenericAdvertiserData setting carrying value.
 *  @param error Operation error.       No error means success.
 */
typedef void(^ESTSettingGenericAdvertiserDataCompletionBlock)(ESTSettingGenericAdvertiserData * _Nullable genericAdvertiserDataSetting, NSError * _Nullable error);


/**
 *  ESTSettingGenericAdvertiserData represents GenericAdvertiser GenericAdvertiserData value.
 */
@interface ESTSettingGenericAdvertiserData : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserData validationErrorForValue:]
 *
 *  @param genericAdvertiserData GenericAdvertiser GenericAdvertiserData value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSData *)genericAdvertiserData;

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserData validationErrorForValue:]
 *
 *  @param genericAdvertiserData GenericAdvertiser GenericAdvertiserData value.
 *  @param advertiserID GenericAdvertiser ID.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSData *)genericAdvertiserData
                 advertiserID:(ESTGenericAdvertiserID)advertiserID;

- (instancetype)initWithData:(NSData *)data
         genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID;

/**
 *  Returns current value of GenericAdvertiser GenericAdvertiserData setting.
 *
 *  @return GenericAdvertiser GenericAdvertiserData value.
 */
- (NSData *)getValue;

/**
 *  Method allows to read value of initialized GenericAdvertiser GenericAdvertiserData setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserDataCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GenericAdvertiser GenericAdvertiserData setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param genericAdvertiserData GenericAdvertiserData value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSData *)genericAdvertiserData completion:(ESTSettingGenericAdvertiserDataCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param genericAdvertiserData GenericAdvertiserData value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSData *)genericAdvertiserData;

@end

NS_ASSUME_NONNULL_END
