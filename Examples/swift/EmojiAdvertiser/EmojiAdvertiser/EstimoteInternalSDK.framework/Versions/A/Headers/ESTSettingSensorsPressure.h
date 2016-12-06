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
#import "ESTSettingReadOnly.h"

@class ESTSettingSensorsPressure;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting Pressure operation for Sensors packet.
 *
 *  @param pressureSetting Pressure setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingSensorsPressureCompletionBlock)(ESTSettingSensorsPressure * _Nullable pressureSetting, NSError * _Nullable error);


/**
 *  ESTSettingSensorsPressure represents Sensors Pressure value.
 */
@interface ESTSettingSensorsPressure : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param pressure Sensors Pressure value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSUInteger)pressure;

/**
 *  Returns current value of Sensors Pressure setting.
 *
 *  @return Sensors Pressure value.
 */
- (NSUInteger)getValue;

/**
 *  Method allows to read value of initialized Sensors Pressure setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingSensorsPressureCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
