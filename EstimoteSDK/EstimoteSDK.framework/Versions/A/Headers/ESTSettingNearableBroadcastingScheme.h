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
#import "ESTNearableDefinitions.h"

#define ESTSettingNearableBroadcastingSchemeErrorDomain @"ESTSettingNearableBroadcastingSchemeErrorDomain"

/**
 *  Describes Settings BroadcastingScheme validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingNearableBroadcastingSchemeError)
{
     /**
      *  Provided value is not allowed.
      */
    ESTSettingNearableBroadcastingSchemeErrorNotAllowed = 1,
    
    /**
     *  Convenience API is not supported.
     */
    ESTSettingNearableBroadcastingSchemeErrorConvenienceAPIUnsupported
};

@class ESTSettingNearableBroadcastingScheme;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting BroadcastingScheme operation for Settings packet.
 *
 *  @param broadcastingSchemeSetting BroadcastingScheme setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingNearableBroadcastingSchemeCompletionBlock)(ESTSettingNearableBroadcastingScheme * _Nullable broadcastingSchemeSetting, NSError * _Nullable error);


/**
 *  ESTSettingNearableBroadcastingScheme represents Settings BroadcastingScheme value.
 */
@interface ESTSettingNearableBroadcastingScheme : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingNearableBroadcastingScheme validationErrorForValue:]
 *
 *  @param broadcastingScheme Settings BroadcastingScheme value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTNearableBroadcastingScheme)broadcastingScheme;

/**
 *  Returns current value of Settings BroadcastingScheme setting.
 *
 *  @return Settings BroadcastingScheme value.
 */
- (ESTNearableBroadcastingScheme)getValue;

/**
 *  Method allows to read value of initialized Nearable Broadcasting Scheme setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingNearableBroadcastingSchemeCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Nearable Broadcasting Scheme setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param broadcastingScheme Broadcasting scheme value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTNearableBroadcastingScheme)broadcastingScheme completion:(ESTSettingNearableBroadcastingSchemeCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param broadcastingScheme BroadcastingScheme value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTNearableBroadcastingScheme)broadcastingScheme;

@end

NS_ASSUME_NONNULL_END
