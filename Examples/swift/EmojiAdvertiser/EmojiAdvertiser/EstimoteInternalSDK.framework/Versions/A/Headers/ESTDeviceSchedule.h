//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import "ESTBaseVO.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents schedule for conditional advertising.
 */
@interface ESTDeviceSchedule : ESTBaseVO

/**
 *  Indicates if scheduled advertising is enabled as BOOL value.
 */
@property (nonatomic, strong, readonly) NSNumber *enabled;

/**
 *  Indicates advertising start time in seconds since midnight
 *  if scheduled advertising is enabled.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *startTime;

/**
 *  Indicates advertising start time in seconds since midnight
 *  if scheduled advertising is enabled.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *stopTime;

/**
 *  Designated initializer.
 *
 *  @param data Dictionary provided by the Estimote cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

/**
 *  Method for returning dictionary represantation of advertising time schedule settings.
 */
- (NSDictionary *)cloudDictionary;

@end

NS_ASSUME_NONNULL_END
