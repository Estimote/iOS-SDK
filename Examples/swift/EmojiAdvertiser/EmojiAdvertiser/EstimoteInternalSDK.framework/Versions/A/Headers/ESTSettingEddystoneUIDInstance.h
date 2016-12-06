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

#define ESTSettingEddystoneUIDInstanceErrorDomain @"ESTSettingEddystoneUIDInstanceErrorDomain"

/**
 *  Describes Eddystone UID Instance validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneUIDInstanceError) {
    /**
     *  Provided string is not a valid hex string.
     */
    ESTSettingEddystoneUIDInstanceErrorInvalidFormat = 1,
    /**
     *  Privided string is too short.
     */
    ESTSettingEddystoneUIDInstanceErrorTooShort,
    /**
     *  Provided string is too long.
     */
    ESTSettingEddystoneUIDInstanceErrorTooLong
};

@class ESTSettingEddystoneUIDInstance;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Instance ID operation for Eddystone UID packet.
 *
 *  @param instanceID Instance ID setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneUIDInstanceCompletionBlock)(ESTSettingEddystoneUIDInstance * _Nullable instanceIDSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneUIDInstance represents Eddystone UID Instance ID value.
 */
@interface ESTSettingEddystoneUIDInstance : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneUIDInstance validationErrorForValue:]
 *
 *  @param instanceID Eddystone UID Instance ID (hex string).
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(NSString *)instanceID;

/**
 *  Returns current value of Eddystone UID Instance ID setting.
 *
 *  @return Eddystone UID Instance ID value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Eddystone UID Instance ID setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneUIDInstanceCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone UID Instance ID setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param instanceID Instance ID hex string to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(NSString *)instanceID completion:(ESTSettingEddystoneUIDInstanceCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param instanceID Instance hex string.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)instanceID;

@end

NS_ASSUME_NONNULL_END
