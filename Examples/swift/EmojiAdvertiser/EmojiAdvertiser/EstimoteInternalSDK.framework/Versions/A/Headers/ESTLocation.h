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
 *  ESTLocation defined by one or more Estimote Device broadcasting
 *  Estimote Location packet.
 */
@interface ESTLocation : NSObject

/**
 *  Identifier of the location.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Signal strength detected on the phone/tablet (-100 to 0))
 */
@property (nonatomic, strong, readonly) NSNumber *rssi;

/**
 *  One sigma horizontal accuracy in meters.
 */
@property (nonatomic, strong, readonly) NSNumber *accuracy;

/**
 *  Strength of the signal for 1m distance.
 */
@property (nonatomic, strong, readonly) NSNumber *measuredPower;

/**
 *  Last time device was seen.
 */
@property (nonatomic, strong, readonly) NSDate *discoveryDate;

/**
 *  Initialize object with identifier of the location.
 *
 *  @param identifier Identifier of the location.
 *  @param rssi Signal strength.
 *  @param measuredPower Signal strength for 1m distance.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier
                              rssi:(NSNumber *)rssi
                     measuredPower:(NSInteger)measuredPower
                     discoveryDate:(NSDate *)discoveryDate;

/**
 *  Internally used method allows to update ESTEddystone object with another ESTEddystone object.
 *
 *  @param eddystone provided ESTEddystone object.
 */
- (void)updateWithLocation:(ESTLocation *)location;

@end

NS_ASSUME_NONNULL_END
