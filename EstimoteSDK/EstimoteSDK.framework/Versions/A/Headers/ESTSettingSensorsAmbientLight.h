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

@class ESTSettingSensorsAmbientLight;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting AmbientLight operation for Sensors packet.
 *
 *  @param ambientLightSetting AmbientLight setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingSensorsAmbientLightCompletionBlock)(ESTSettingSensorsAmbientLight * _Nullable ambientLightSetting, NSError * _Nullable error);


/**
 *  ESTSettingSensorsAmbientLight represents Sensors AmbientLight value.
 */
@interface ESTSettingSensorsAmbientLight : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param ambientLight Sensors AmbientLight value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSUInteger)ambientLight;

/**
 *  Returns current value of Sensors AmbientLight setting.
 *
 *  @return Sensors AmbientLight value.
 */
- (NSUInteger)getValue;

/**
 *  Method allows to read value of initialized Sensors AmbientLight setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingSensorsAmbientLightCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
