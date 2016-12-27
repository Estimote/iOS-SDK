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

#define ESTSettingIBeaconMajorErrorDomain @"ESTSettingIBeaconMajorErrorDomain"

/**
 *  Describes iBeacon Advertising Major validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingIBeaconMajorError) {
    /**
     *  Provided major value is equal to zero.
     */
    ESTSettingIBeaconMajorErrorEqualsZero = 1,
};

@class ESTSettingIBeaconMajor;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting major operation.
 *
 *  @param major Major setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconMajorCompletionBlock)(ESTSettingIBeaconMajor * _Nullable major, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconMajor represents iBeacon major value broadcasted by the device.
 */
@interface ESTSettingIBeaconMajor : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingIBeaconMajor validationErrorForValue:].
 *
 *  @param major iBeacon Major value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype _Nullable)initWithValue:(unsigned short)major;

/**
 *  Returns current value of iBeacon major setting.
 *
 *  @return iBeacon major value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized iBeacon Major setting object.
 *
 *  @param completion Block should be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconMajorCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon Major setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param completion Block should be invoked when operation is complete.
 */
- (void)writeValue:(unsigned short)value completion:(ESTSettingIBeaconMajorCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param major Major value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)major;

@end

NS_ASSUME_NONNULL_END
