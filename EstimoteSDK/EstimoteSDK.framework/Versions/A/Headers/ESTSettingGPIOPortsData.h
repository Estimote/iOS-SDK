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
#import "ESTGPIOPortsData.h"

@class ESTSettingGPIOPortsData;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting PortsData operation for GPIO packet.
 *
 *  @param portsDataSetting PortsData setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingGPIOPortsDataCompletionBlock)(ESTSettingGPIOPortsData * _Nullable portsDataSetting, NSError * _Nullable error);


/**
 *  ESTSettingGPIOPortsData represents GPIO PortsData value.
 */
@interface ESTSettingGPIOPortsData : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingGPIOPortsData validationErrorForValue:]
 *
 *  @param portsData GPIO PortsData value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(ESTGPIOPortsData *)portsData;

/**
 *  Returns current value of GPIO PortsData setting.
 *
 *  Note that GPIO ports state (when used as input) is volatile
 *  and should be read each time its value is needed.
 *
 *  @return GPIO ConfigPort0 value.
 *  
 *  @see -[ESTSettingGPIOPortsData readValueWithCompletion:].
 */
- (ESTGPIOPortsData *)getValue;

/**
 *  Method allows to read value of initialized GPIO PortsData setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingGPIOPortsDataCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized GPIO PortsData setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param portsData PortsData value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 */
- (void)writeValue:(ESTGPIOPortsData *)portsData completion:(ESTSettingGPIOPortsDataCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param portsData PortsData value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(ESTGPIOPortsData *)portsData;

@end

NS_ASSUME_NONNULL_END
