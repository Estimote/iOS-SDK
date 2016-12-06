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

#define ESTSettingIBeaconMinorErrorDomain @"ESTSettingIBeaconMinorErrorDomain"

/**
 *  Describes iBeacon Advertising Minor validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingIBeaconMinorError) {
    /**
     *  Provided Minor value is equal to zero.
     */
    ESTSettingIBeaconMinorErrorEqualsZero = 1,
};

@class ESTSettingIBeaconMinor;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Minor operation for iBeacon packet.
 *
 *  @param minor Minor setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconMinorCompletionBlock)(ESTSettingIBeaconMinor * _Nullable minor, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconMinor represents iBeacon Minor value.
 */
@interface ESTSettingIBeaconMinor : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param minor iBeacon Minor value.
 *
 *  @return Initialized object.
 */
- (instancetype _Nullable)initWithValue:(unsigned short)minor;

/**
 *  Returns current value of iBeacon Minor setting.
 *
 *  @return iBeacon Minor value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized iBeacon Minor setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconMinorCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized iBeacon Minor setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param minor Minor value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(unsigned short)minor completion:(ESTSettingIBeaconMinorCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param minor Minor value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(unsigned short)minor;

@end

NS_ASSUME_NONNULL_END
