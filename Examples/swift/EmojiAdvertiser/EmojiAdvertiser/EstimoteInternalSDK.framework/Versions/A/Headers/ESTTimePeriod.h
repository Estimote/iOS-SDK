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

#import <Foundation/Foundation.h>
#import "ESTTime.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTTimePeriod represents time interval using two time points.
 *  Can be used for time intervals of reoccuring events without a concrete absolute time.
 *
 *  Start time later than end time is allowed. In that situation, 
 *  the object represents interval spanning across adjacent days.
 */
@interface ESTTimePeriod : NSObject <NSCopying>

/**
 *  Time interval starting bound. Can be later than the end time.
 */
@property (nonatomic, strong, readonly) ESTTime *startTime;

/**
 *  Time interval ending bound. Can be before the start time.
 */
@property (nonatomic, strong, readonly) ESTTime *endTime;

/**
 *  Designated initializer.
 *
 *  @param startTime Time interval starting bound.
 *  @param endTime   Time interval ending bound.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithStartTime:(ESTTime *)startTime endTime:(ESTTime *)endTime;

/**
 *  Convenience initializer.
 *
 *  @param startTimeSeconds Time interval starting bound in seconds.
 *  @param endTimeSeconds   Time interval ending bound in seconds.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithStartTimeSeconds:(NSUInteger)startTimeSeconds endTimeSeconds:(NSUInteger)endTimeSeconds;

@end

NS_ASSUME_NONNULL_END
