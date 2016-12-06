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

#define ESTSettingLinkNetworkEnabledErrorDomain @"ESTSettingLinkNetworkEnabledErrorDomain"

@class ESTSettingLinkNetworkEnabled;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enabled operation for Link Network packet.
 *
 *  @param enabled Enabled setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingLinkNetworkEnabledCompletionBlock)(ESTSettingLinkNetworkEnabled * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingLinkNetworkEnabled represents Link Network Enabled value.
 */
@interface ESTSettingLinkNetworkEnabled : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingLinkNetworkEnabled validationErrorForValue:]
 *
 *  @param enabled Link Network Enabled value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of Link Network Enabled setting.
 *
 *  @return Link Network Enabled value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Link Network Enabled setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingLinkNetworkEnabledCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Link Network Enabled setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled Enabled value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingLinkNetworkEnabledCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param enabled Enabled value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
