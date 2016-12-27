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
#import "ESTTimePeriod.h"

#define ESTSettingPowerScheduledAdvertisingPeriodErrorDomain @"ESTSettingPowerScheduledAdvertisingPeriodErrorDomain"

/**
 *  Describes Power ScheduledAdvertisingPeriod validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingPowerScheduledAdvertisingPeriodError)
{
     /**
     *  Provided time period object contains start time that exceeds 24 hours.
     */
    ESTSettingPowerScheduledAdvertisingPeriodErrorStartTimeTooBig = 1,
    /**
     *  Provided time period object contains end time that exceeds 24 hours.
     */
    ESTSettingPowerScheduledAdvertisingPeriodErrorEndTimeTooBig
    
};

@class ESTSettingPowerScheduledAdvertisingPeriod;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting ScheduledAdvertisingPeriod operation for Power packet.
 *
 *  @param periodSetting ScheduledAdvertisingPeriod setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingPowerScheduledAdvertisingPeriodCompletionBlock)(ESTSettingPowerScheduledAdvertisingPeriod * _Nullable periodSetting, NSError * _Nullable error);


/**
 *  ESTSettingPowerScheduledAdvertisingPeriod represents Power ScheduledAdvertisingPeriod value.
 */
@interface ESTSettingPowerScheduledAdvertisingPeriod : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingPowerScheduledAdvertisingPeriod validationErrorForValue:]
 *
 *  @param period Power ScheduledAdvertisingPeriod value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTTimePeriod *)period;

/**
 *  Returns current value of Power ScheduledAdvertisingPeriod setting.
 *
 *  @return Power ScheduledAdvertisingPeriod value.
 */
- (ESTTimePeriod *)getValue;

/**
 *  Method allows to read value of initialized Power ScheduledAdvertisingPeriod setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingPowerScheduledAdvertisingPeriodCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Power ScheduledAdvertisingPeriod setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param period ScheduledAdvertisingPeriod value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTTimePeriod *)period completion:(ESTSettingPowerScheduledAdvertisingPeriodCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param period ScheduledAdvertisingPeriod value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTTimePeriod *)period;

@end

NS_ASSUME_NONNULL_END
