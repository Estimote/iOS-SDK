//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTBaseVO.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents physical location of the device.
 */
@interface ESTDeviceGeoLocation : ESTBaseVO

/**
 *  Location GPS latitude.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *latitude;

/**
 *  Location GPS longitude.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *longitude;


// ------------------- Resolved address properties -------------------

/**
 *  Location address country.
 */
@property (nonatomic, strong, readonly, nullable) NSString *country;

/**
 *  Location address zip code.
 */
@property (nonatomic, strong, readonly, nullable) NSString *zipCode;

/**
 *  Location address state.
 */
@property (nonatomic, strong, readonly, nullable) NSString *state;

/**
 *  Location address state code.
 */
@property (nonatomic, strong, readonly, nullable) NSString *stateCode;

/**
 *  Location address city.
 */
@property (nonatomic, strong, readonly, nullable) NSString *city;

/**
 *  Locations address street name.
 */
@property (nonatomic, strong, readonly, nullable) NSString *streetName;

/**
 *  Location address street number. Can contain letters.
 */
@property (nonatomic, strong, readonly, nullable) NSString *streetNumber;

/**
 *  Human readable full address string.
 */
@property (nonatomic, strong, readonly, nullable) NSString *formattedAddress;

/**
 *  Location accuracy.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *accuracy;

/**
 *  Location timezone.
 */
@property (nonatomic, strong, readonly, nullable) NSString *timezone;

/**
 *  Designated initializer. Use it to create new Geo Location in Cloud.
 *
 *  @param latitude  Latitude degrees number.
 *  @param longitude Longitude degrees number.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithLatitude:(NSNumber *)latitude
                       longitude:(NSNumber *)longitude;

@end


@interface ESTDeviceGeoLocation (Internal)

/**
 *  Cloud parsing initalizer.
 *
 *  @param dictionary Dictionary returned from Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
