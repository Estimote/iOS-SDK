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

#define ESTSettingLinkNetworkDomainErrorDomain @"ESTSettingLinkNetworkDomainErrorDomain"

/**
 *  Describes Link Network Domain validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingLinkNetworkDomainError)
{
     /**
     *  Provided value is not a valid URL.
     */
    ESTSettingLinkNetworkDomainErrorNotValid = 1,
    
    /**
     *  Provided URL is too long.
     */
    ESTSettingLinkNetworkDomainErrorTooLong = 2
};

@class ESTSettingLinkNetworkDomain;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Domain operation for Link Network packet.
 *
 *  @param domain Domain setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingLinkNetworkDomainCompletionBlock)(ESTSettingLinkNetworkDomain * _Nullable domainSetting, NSError * _Nullable error);


/**
 *  ESTSettingLinkNetworkDomain represents Link Network Domain value.
 */
@interface ESTSettingLinkNetworkDomain : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingLinkNetworkDomain validationErrorForValue:]
 *
 *  @param domain Link Network Domain value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(NSString *)domain;

/**
 *  Returns current value of Link Network Domain setting.
 *
 *  @return Link Network Domain value.
 */
- (NSString *)getValue;

/**
 *  Method allows to read value of initialized Link Network Domain setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingLinkNetworkDomainCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Link Network Domain setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param domain Domain value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(NSString *)domain completion:(ESTSettingLinkNetworkDomainCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param domain Domain value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(NSString *)domain;

@end

NS_ASSUME_NONNULL_END
