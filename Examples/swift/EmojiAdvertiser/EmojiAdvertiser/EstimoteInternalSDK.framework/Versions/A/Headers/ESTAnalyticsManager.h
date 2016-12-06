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
#import "ESTRequestAnalyticsTrack.h"
#import "ESTAnalyticsEventVO.h"

/**
 *  ESTAnalyticsManager class is responsible for registering analytics requests and events, triggered by ranging and monitoring `CLBeaconRegion`.
 *  Manager sends to Estimote Cloud up to 100 registered analytics events every 20 seconds.
 *  @warning *Important:* works only with iBeacon devices returned by `ESTBeaconManager` and `ESTSecureBeaconManager.
 */

@interface ESTAnalyticsManager : NSObject

+ (instancetype)sharedInstance;

/**
 *  Method allows to track analytics event for given region. Analytics events will be cached and sent to Estimote Cloud.
 *  @warning If `ESTGPSPositionManager` is enabled then `ESTAnalyticsManager` will create analytic event with GPS location assigned.
 *
 *  @param region `CLBeaconRegion` object, for which analytics events will be tracked
 *  @param eventType `ESTAnalyticsEventType` enum of tracked analytics events
 */
- (void)registerAnalyticsEventWithRegion:(CLBeaconRegion *)region
                                    type:(ESTAnalyticsEventType)eventType;

/**
 *  Method allows sending stored analytics events to Estimote Cloud.
 */
- (void)sendRegisteredEvents;

/**
 *  Method returns `ESTAnalyticsEventType` enum for given `CLProximity`.
 */
+ (ESTAnalyticsEventType)getEventTypeForProximity:(CLProximity)proximity;

#pragma mark - Analytics settings

/**
 *  Enables analytics requests on Enter/Exit monitoring events. Analytics data
 *  is collected in the Estimote Cloud.
 *
 *  @param enable flag indicating if analytics for monitoring should be enabled
 */
+ (void)enableMonitoringAnalytics:(BOOL)enable;

/**
 *  Enables analytics requests for ranging events.
 *  Information about beacons and their Proximity is collected
 *  in the Estimote Cloud.
 *
 *  @param enable flag indicating if analytics for ranging should be enabled
 */
+ (void)enableRangingAnalytics:(BOOL)enable;

/**
 *  When GPS Positioning is turned on analytics events
 *  contains information about GPS Location.
 *
 *  @param enable flag indicating if GPS Positioning should be enabled
 */
+ (void)enableGPSPositioningForAnalytics:(BOOL)enable;

/**
 *  Indicates current state of monitoring analytics.
 *
 *  @return flag that indicates if analytics is enabled
 */
+ (BOOL)isMonitoringAnalyticsEnabled;

/**
 *  Indicates current state of ranging analytics.
 *
 *  @return flag that indicates if analytics is enabled
 */
+ (BOOL)isRangingAnalyticsEnabled;

@end
