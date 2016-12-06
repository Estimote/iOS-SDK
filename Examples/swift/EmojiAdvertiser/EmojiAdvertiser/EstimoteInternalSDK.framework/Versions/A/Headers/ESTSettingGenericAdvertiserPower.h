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

#define ESTSettingGenericAdvertiserPowerErrorDomain @"ESTSettingGenericAdvertiserPowerErrorDomain"

typedef NS_ENUM(int8_t, ESTGenericAdvertiserPowerLevel)
{
    ESTGenericAdvertiserPowerLevel1 = -30,
    ESTGenericAdvertiserPowerLevel1A = -40, // use this instead of -30 for nRF52-based beacons (e.g., G1.8 and later, F3.3 and later)
    ESTGenericAdvertiserPowerLevel2 = -20,
    ESTGenericAdvertiserPowerLevel3 = -16,
    ESTGenericAdvertiserPowerLevel4 = -12,
    ESTGenericAdvertiserPowerLevel5 = -8,
    ESTGenericAdvertiserPowerLevel6 = -4,
    ESTGenericAdvertiserPowerLevel7 = 0,
    ESTGenericAdvertiserPowerLevel8 = 4,
    ESTGenericAdvertiserPowerLevel9 = 10 // for Location Beacons with long-range support (e.g., F3.3 and later)
};

/**
 *  Describes GenericAdvertiser GenericAdvertiserPower validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingGenericAdvertiserPowerError)
{
     /**
     *  Provided value not allowed.
     */
    ESTSettingGenericAdvertiserPowerErrorValueNotAllowed = 1
};

@class ESTSettingGenericAdvertiserPower;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting GenericAdvertiserPower operation for GenericAdvertiser packet.
 *
 *  @param genericAdvertiserPowerSetting GenericAdvertiserPower setting carrying value.
 *  @param error Operation error.        No error means success.
 */
typedef void(^ESTSettingGenericAdvertiserPowerCompletionBlock)(ESTSettingGenericAdvertiserPower * _Nullable genericAdvertiserPowerSetting, NSError * _Nullable error);


/**
 *  ESTSettingGenericAdvertiserPower represents GenericAdvertiser GenericAdvertiserPower value.
 */
@interface ESTSettingGenericAdvertiserPower : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserPower validationErrorForValue:]
 *
 *  @param genericAdvertiserPower GenericAdvertiser GenericAdvertiserPower value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower;

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserPower validationErrorForValue:]
 *
 *  @param genericAdvertiserPower GenericAdvertiser GenericAdvertiserPower value.
 *  @param advertiserID GenericAdvertiser ID.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower
                 advertiserID:(ESTGenericAdvertiserID)advertiserID;

- (instancetype)initWithData:(NSData *)data
         genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID;

/**
 *  Returns current value of GenericAdvertiser GenericAdvertiserPower setting.
 *
 *  @return GenericAdvertiser GenericAdvertiserPower value.
 */
- (unsigned short)getValue;

/**
 *  Method allows to read value of initialized GenericAdvertiser GenericAdvertiserPower setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserPowerCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GenericAdvertiser GenericAdvertiserPower setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param genericAdvertiserPower GenericAdvertiserPower value to be written to the device.
 *  @param completion             Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower completion:(ESTSettingGenericAdvertiserPowerCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param genericAdvertiserPower GenericAdvertiserPower value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower;

@end

NS_ASSUME_NONNULL_END
