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

#define ESTSettingGenericAdvertiserEnableErrorDomain @"ESTSettingGenericAdvertiserEnableErrorDomain"


@class ESTSettingGenericAdvertiserEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting GenericAdvertiserEnabled operation for GenericAdvertiser packet.
 *
 *  @param genericAdvertiserEnabledSetting GenericAdvertiserEnabled setting carrying value.
 *  @param error Operation error.          No error means success.
 */
typedef void(^ESTSettingGenericAdvertiserEnableCompletionBlock)(ESTSettingGenericAdvertiserEnable * _Nullable genericAdvertiserEnabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingGenericAdvertiserEnable represents GenericAdvertiser GenericAdvertiserEnabled value.
 */
@interface ESTSettingGenericAdvertiserEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserEnable validationErrorForValue:]
 *
 *  @param genericAdvertiserEnabled GenericAdvertiser GenericAdvertiserEnabled value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)genericAdvertiserEnabled;

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGenericAdvertiserEnable validationErrorForValue:]
 *
 *  @param genericAdvertiserEnabled GenericAdvertiser GenericAdvertiserEnabled value.
 *  @param genericAdvertiserID      GenericAdvertiser ID represented by ESTGenericAdvertiserID enum.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)genericAdvertiserEnabled
          genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID;



- (instancetype)initWithData:(NSData *)data
         genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID;

/**
 *  Returns current value of GenericAdvertiser GenericAdvertiserEnabled setting.
 *
 *  @return GenericAdvertiser GenericAdvertiserEnabled value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized GenericAdvertiser GenericAdvertiserEnabled setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GenericAdvertiser GenericAdvertiserEnabled setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param genericAdvertiserEnabled GenericAdvertiserEnabled value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)genericAdvertiserEnabled completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
