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

@class ESTSettingEddystoneEIDEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enable operation for EddystoneEID packet.
 *
 *  @param enable Enable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneEIDEnableCompletionBlock)(ESTSettingEddystoneEIDEnable * _Nullable enableSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneEIDEnable represents EddystoneEID Enable value.
 */
@interface ESTSettingEddystoneEIDEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @param enable EddystoneEID Enable value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(BOOL)enable;

/**
 *  Returns current value of EddystoneEID Enable setting.
 *
 *  @return EddystoneEID Enable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized EddystoneEID Enable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneEIDEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized EddystoneEID Enable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enable Enable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(BOOL)enable completion:(ESTSettingEddystoneEIDEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
