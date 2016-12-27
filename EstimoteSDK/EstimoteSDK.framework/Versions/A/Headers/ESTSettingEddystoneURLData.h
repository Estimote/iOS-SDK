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

#define ESTSettingEddystoneURLDataErrorDomain @"ESTSettingEddystoneURLDataErrorDomain"

/**
 *  Describes Eddystone URL validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneURLNamespaceError) {
    /**
     *  Provided URL string is invalid.
     */
    ESTSettingEddystoneURLDataErrorInvalidURL = 1
};

@class ESTSettingEddystoneURLData;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting URL Data operation for Eddystone URL packet.
 *
 *  @param eddystoneURLSetting URL Data setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneURLDataCompletionBlock)(ESTSettingEddystoneURLData * _Nullable eddystoneURLSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneURLData represents Eddystone URL Data value.
 */
@interface ESTSettingEddystoneURLData : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:. 
 *
 *  @see +[ESTSettingEddystoneURLInterval validationErrorForValue:]
 *
 *  @param eddystoneURL Eddystone URL Data value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(NSString *)eddystoneURL;

/**
 *  Returns current value of Eddystone URL Data setting.
 *
 *  @return Eddystone URL URL Data value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Eddystone URL Data setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneURLDataCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone URL Data setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param eddystoneURL URL Data value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSString *)eddystoneURL completion:(ESTSettingEddystoneURLDataCompletionBlock)completion;

/**
 *  Method checks if provided value is a proper Eddystone URL string. Returns nil if validation passes.
 *
 *  @param eddystoneURL Eddystone URL string.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)eddystoneURL;

@end

NS_ASSUME_NONNULL_END
