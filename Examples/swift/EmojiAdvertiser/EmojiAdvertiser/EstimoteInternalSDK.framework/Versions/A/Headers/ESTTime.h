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

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTTime is an object wrapper around seconds since midnight.
 *  Represents given time of day, measuring seconds since midnight.
 *  Useful for representing time relative to midnight.
 */
@interface ESTTime : NSObject <NSCopying>

/**
 *  Seconds since midnight.
 */
@property (nonatomic, assign, readonly) NSUInteger secondsSinceMidnight;

/**
 *  Designated initializer.
 *
 *  @param seconds Seconds since midnight.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSecondsSinceMidnight:(NSUInteger)seconds;

/**
 *  Convenience initializer. Creates object using clock time values.
 *
 *  @param hours   Integer hours since midnight for a given point in time.
 *  @param minutes Integer minutes since midnight for a given point in time.
 *  @param seconds Integer seconds since midnight for a given point in time.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithHours:(NSUInteger)hours minutes:(NSUInteger)minutes seconds:(NSUInteger)seconds;

/**
 *  Convenience initializer. Creates object using clock time values. 
 *  Assumes seconds are equal to 0.
 *
 *  @param hours   Integer hours since midnight for a given point in time.
 *  @param minutes Integer minutes since midnight for a given point in time.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithHours:(NSUInteger)hours minutes:(NSUInteger)minutes;

@end

NS_ASSUME_NONNULL_END
