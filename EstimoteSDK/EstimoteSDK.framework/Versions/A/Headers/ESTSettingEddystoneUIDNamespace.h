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

#define ESTSettingEddystoneUIDNamespaceErrorDomain @"ESTSettingEddystoneUIDNamespaceErrorDomain"

/**
 *  Describes Eddystone UID Namespace validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneUIDNamespaceError) {
    /**
     *  Provided string is not a valid hex string.
     */
    ESTSettingEddystoneUIDNamespaceErrorInvalidFormat = 1,
    /**
     *  Privided string is too short.
     */
    ESTSettingEddystoneUIDNamespaceErrorTooShort,
    /**
     *  Provided string is too long.
     */
    ESTSettingEddystoneUIDNamespaceErrorTooLong
};

@class ESTSettingEddystoneUIDNamespace;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Namespace operation for Eddystone UID packet.
 *
 *  @param namespaceSetting Namespace setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneUIDNamespaceCompletionBlock)(ESTSettingEddystoneUIDNamespace * _Nullable namespaceSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneUIDNamespace represents Eddystone UID Namespace value.
 */
@interface ESTSettingEddystoneUIDNamespace : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *  
 *  @see +[ESTSettingEddystoneUIDNamespace validationErrorForValue:]
 *
 *  @param namespaceID Eddystone UID Namespace value in form of a hex string.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(NSString *)namespaceID;

/**
 *  Returns current value of Eddystone UID Namespace ID in form of a hex string.
 *
 *  @return Eddystone UID Namespace ID value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Eddystone UID Namespace setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneUIDNamespaceCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone UID Namespace setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param namespaceID Namespace hex string to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSString *)namespaceID completion:(ESTSettingEddystoneUIDNamespaceCompletionBlock)completion;


/**
 *  Helper method to convert a domain to Eddystone UID Namespace ID (hex string).
 *
 *  @param domain Eddystone domain, i.e. "com.estimote".
 *
 *  @return Converted Eddystone UID Namespace ID (hex string).
 */
+ (NSString *)namespaceHexStringForEddystoneDomain:(NSString *)domain;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param namespaceID Namespace hex string.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)namespaceID;

@end

NS_ASSUME_NONNULL_END
