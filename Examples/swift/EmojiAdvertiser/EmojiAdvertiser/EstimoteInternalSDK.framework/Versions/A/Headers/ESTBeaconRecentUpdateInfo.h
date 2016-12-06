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
#import "ESTBeaconRecentConfig.h"

/**
 * Class `ESTBeaconRecentUpdateInfo` represents all data that has been already applied in the beacon.
 */
@interface ESTBeaconRecentUpdateInfo : ESTBeaconBaseVO

/**
 *  Device mac address about which this info is for.
 */
@property (nonatomic, readonly) NSString *macAddress;

/**
 *  Beacon's settings, that were applied.
 */
@property (nonatomic, readonly) ESTBeaconRecentConfig *config;

/**
 *  Settings creation timestamp.
 */
@property (nonatomic, readonly) NSDate *createdAt;

/**
 *  Time when settings were applied to the device.
 */
@property (nonatomic, readonly) NSDate *syncedAt;

/**
 *  Method initializing recent change's info object.
 *
 *  @param data Cloud data parsed from request response
 *  @param config Recent change's config object
 *
 *  @return recent change's info object
 */
- (instancetype)initWithCloudData:(NSDictionary *)data andMacAddress:(NSString *)mac;

@end
