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
#import "ESTDeviceGeoLocation.h"
#import "ESTDeviceIndoorLocation.h"


/**
 *  This Value Object represents status report related to the device.
 */
@interface ESTDeviceStatusReport : ESTBaseVO

/**
 *  Expected battery percentage stored as integer number of percents.
 */
@property (nonatomic, strong, readonly) NSNumber *batteryPercentage;

/**
 *  Expected battery lifetime in days.
 */
@property (nonatomic, strong, readonly) NSNumber *batteryLifetime;

/**
 *  Battery voltage in millivolts.
 */
@property (nonatomic, strong, readonly) NSNumber *batteryVoltageInVolts;

/**
 *  Clock offset in seconds.
 */
@property (nonatomic, strong, readonly) NSNumber *clockOffsetInSeconds;

/**
 *  Currently installed firmware version.
 */
@property (nonatomic, strong, readonly) NSString *firmwareVersion;

/**
 *  Information when the device was synchronized last time.
 */
@property (nonatomic, strong, readonly) NSDate *lastSync;

/**
 *  Designated initializer.
 *
 *  @param dictionary Dictionary provided by the Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

@end
