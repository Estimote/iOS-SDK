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

#define ESTSettingEddystoneUIDIntervalErrorDomain @"ESTSettingEddystoneUIDIntervalErrorDomain"

/**
 *  Describes Eddystone UID Advertising Interval validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingEddystoneUIDIntervalError) {
    /**
     *  Provided value is too small.
     */
    ESTSettingEddystoneUIDIntervalErrorValueTooSmall = 1,
    /**
     *  Provided value is too big.
     */
    ESTSettingEddystoneUIDIntervalErrorValueTooBig
};

@class ESTSettingEddystoneUIDInterval;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting AdvertisingInterval operation for Eddystone UID packet.
 *
 *  @param advertisingInterval AdvertisingInterval setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneUIDIntervalCompletionBlock)(ESTSettingEddystoneUIDInterval * _Nullable advertisingIntervalSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneUIDInterval represents Eddystone UID AdvertisingInterval value.
 */
@interface ESTSettingEddystoneUIDInterval : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *  
 *  @see +[ESTSettingEddystoneUIDInterval validationErrorForValue:]
 *
 *  @param advertisingInterval Eddystone UID AdvertisingInterval value in ms. It should be between 100 and 2000.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(unsigned short)advertisingInterval;

/**
 *  Returns current value of Eddystone UID AdvertisingInterval setting in ms.
 *
 *  @return Eddystone UID AdvertisingInterval value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized Eddystone UID AdvertisingInterval setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneUIDIntervalCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone UID AdvertisingInterval setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param advertisingInterval AdvertisingInterval value in ms to be written to the device. It should be between 100 and 2000.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(unsigned short)advertisingInterval completion:(ESTSettingEddystoneUIDIntervalCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param advertisingInterval AdvertisingInterval value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)advertisingInterval;

@end

NS_ASSUME_NONNULL_END
