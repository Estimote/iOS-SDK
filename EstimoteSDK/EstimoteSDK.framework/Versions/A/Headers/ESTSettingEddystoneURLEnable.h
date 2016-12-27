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

@class ESTSettingEddystoneURLEnable;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting Enable operation for Eddystone URL packet.
 *
 *  @param enabledSetting Enable setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingEddystoneURLEnableCompletionBlock)(ESTSettingEddystoneURLEnable * _Nullable enabledSetting, NSError * _Nullable error);


/**
 *  ESTSettingEddystoneURLEnable represents Eddystone URL Enable value.
 */
@interface ESTSettingEddystoneURLEnable : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param enabled Eddystone URL Enable value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(BOOL)enabled;

/**
 *  Returns current value of Eddystone URL Enable setting.
 *
 *  @return Eddystone URL Enable value.
 */
- (BOOL)getValue;

/**
 *  Method allows to read value of initialized Eddystone URL Enable setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingEddystoneURLEnableCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Eddystone URL Enable setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param enabled Enable value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(BOOL)enabled completion:(ESTSettingEddystoneURLEnableCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
