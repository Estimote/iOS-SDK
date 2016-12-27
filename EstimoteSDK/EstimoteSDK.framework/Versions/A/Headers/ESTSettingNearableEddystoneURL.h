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

#define ESTSettingNearableEddystoneURLErrorDomain @"ESTSettingNearableEddystoneURLErrorDomain"

/**
 *  Describes Settings EddystoneURL validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingNearableEddystoneURLError)
{
     /**
     *  Provided value is not a valid Eddystone URL.
     */
    ESTSettingNearableEddystoneURLErrorInvalidURL = 1,
    
    /**
     *  Convenience API is not supported.
     */
    ESTSettingNearableEddystoneURLErrorConvenienceAPIUnsupported
};

@class ESTSettingNearableEddystoneURL;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting EddystoneURL operation for Settings packet.
 *
 *  @param eddystoneURLSetting EddystoneURL setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingNearableEddystoneURLCompletionBlock)(ESTSettingNearableEddystoneURL * _Nullable eddystoneURLSetting, NSError * _Nullable error);


/**
 *  ESTSettingNearableEddystoneURL represents Settings EddystoneURL value.
 */
@interface ESTSettingNearableEddystoneURL : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingNearableEddystoneURL validationErrorForValue:]
 *
 *  @param eddystoneURL Settings EddystoneURL value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSString *)eddystoneURL;

/**
 *  Returns current value of Settings EddystoneURL setting.
 *
 *  @return Settings EddystoneURL value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Settings EddystoneURL setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingNearableEddystoneURLCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Settings EddystoneURL setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param eddystoneURL EddystoneURL value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(NSString *)eddystoneURL completion:(ESTSettingNearableEddystoneURLCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param eddystoneURL EddystoneURL value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)eddystoneURL;

@end

NS_ASSUME_NONNULL_END
