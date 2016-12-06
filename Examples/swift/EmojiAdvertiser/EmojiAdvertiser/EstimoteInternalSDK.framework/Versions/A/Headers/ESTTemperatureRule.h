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

#import "ESTNearableRule.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTTemperatureRule` class defines single rule related to ambient temperature of the Estimote nearable device.
 */

@interface ESTTemperatureRule : ESTNearableRule

@property (nonatomic, strong) NSNumber * _Nullable maxValue;
@property (nonatomic, strong) NSNumber * _Nullable minValue;

+ (instancetype)temperatureGraterThan:(double)value forNearableIdentifier:(NSString *)identifier;
+ (instancetype)temperatureLowerThan:(double)value forNearableIdentifier:(NSString *)identifier;
+ (instancetype)temperatureBetween:(double)minValue and:(double)maxValue forNearableIdentifier:(NSString *)identifier;

+ (instancetype)temperatureGraterThan:(double)value forNearableType:(ESTNearableType)type;
+ (instancetype)temperatureLowerThan:(double)value forNearableType:(ESTNearableType)type;
+ (instancetype)temperatureBetween:(double)minValue and:(double)maxValue forNearableType:(ESTNearableType)type;

@end

NS_ASSUME_NONNULL_END
