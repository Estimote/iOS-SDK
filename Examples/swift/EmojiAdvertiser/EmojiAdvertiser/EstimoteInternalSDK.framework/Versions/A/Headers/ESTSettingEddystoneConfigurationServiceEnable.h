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

#define ESTSettingEddystoneConfigurationServiceEnableErrorDomain @"ESTSettingEddystoneConfigurationServiceEnableErrorDomain"

@class ESTSettingEddystoneConfigurationServiceEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting `EddystoneConfigurationServiceEnable` operation for Eddystone Configuration packet.
 *
 *  @param eddystoneConfigurationServiceEnable EddystoneConfigurationServiceEnable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneConfigurationServiceEnableCompletionBlock)(ESTSettingEddystoneConfigurationServiceEnable * _Nullable eddystoneConfigurationServiceEnableSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneConfigurationServiceEnable represents EddystoneConfigurationServiceEnable setting value.
 */
@interface ESTSettingEddystoneConfigurationServiceEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingEddystoneConfigurationServiceEnable validationErrorForValue:]
 *
 *  @param eddystoneConfigurationServiceEnable EddystoneConfigurationServiceEnable setting value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)eddystoneConfigurationServiceEnable;

/**
 *  Returns current value of EddystoneConfigurationServiceEnable setting.
 *
 *  @return EddystoneConfigurationServiceEnable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized EddystoneConfigurationServiceEnable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneConfigurationServiceEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized EddystoneConfigurationServiceEnable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param eddystoneConfigurationServiceEnable EddystoneConfigurationServiceEnable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(BOOL)eddystoneConfigurationServiceEnable completion:(ESTSettingEddystoneConfigurationServiceEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
