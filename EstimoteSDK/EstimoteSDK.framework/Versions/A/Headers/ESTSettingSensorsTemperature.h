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

@class ESTSettingSensorsTemperature;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting Temperature operation for Sensors packet.
 *
 *  @param temperatureSetting Temperature setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingSensorsTemperatureCompletionBlock)(ESTSettingSensorsTemperature * _Nullable temperatureSetting, NSError * _Nullable error);


/**
 *  ESTSettingSensorsTemperature represents Sensors Temperature value.
 */
@interface ESTSettingSensorsTemperature : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param temperature Sensors Temperature value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(float)temperature;

/**
 *  Returns current value of Sensors Temperature setting in Celsius degree.
 *
 *  @return Sensors Temperature value.
 */
- (float)getValue;

/**
 *  Returns current value of Sensors Temperature setting in Fahrenheit degree.
 *
 *  @return Sensors Temperature value.
 */
- (float)getValueInFahrenheit;

/**
 *  Method allows to read value of initialized Sensors Temperature setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingSensorsTemperatureCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
