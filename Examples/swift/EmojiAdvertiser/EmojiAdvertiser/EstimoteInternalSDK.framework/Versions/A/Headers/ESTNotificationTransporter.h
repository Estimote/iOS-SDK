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

/**
*  ESTNotificationTransporter is a class that allows you to easily exchange data between host app and extension.
*  After each successful save ESTNotification is sent so the extension or host app can read data.
*  Before implementing this class remember to setup App Groups in your project.
*  Please read https://developer.apple.com/library/ios/documentation/General/Conceptual/ExtensibilityPG/ExtensionScenarios.html
*  (Sharing Data with Your Containing App section) if you have any problems with that.
*/

#import <Foundation/Foundation.h>
#import "ESTNearable.h"

typedef NS_ENUM(NSInteger, ESTNotification)
{
    ESTNotificationDidSaveNearableZoneDescription,
    ESTNotificationDidSaveNearable,
    ESTNotificationDidBeaconEnterRegion,
    ESTNotificationDidBeaconExitRegion,
    ESTNotificationDidNearableEnterRegion,
    ESTNotificationDidNearableExitRegion,
    ESTNotificationDidRangeNearables
};

#define BEACON_REGION_KEY @"beaconRegionKey"


@interface ESTNotificationTransporter : NSObject

@property (nonatomic, readonly) NSString *currentAppGroupIdentifier;

/**
 * Returns Shared Transporter instance.
 * Remember: iPhone and Extension have different memory pool.
 * Which means, Transporter is not shared between those two.
 * Hence, you need to call - (void)setAppGroupIdentifier in
 * host app code and extension code.
 *
 * @return Shared instance of this class, used for communication between
 * host app and extension.
 */
+ (instancetype)sharedTransporter;

- (void)setAppGroupIdentifier:(NSString *)identifier;

/**
 *  Use this method to save Nearable Zone Description.
 *  It sends ESTNotificationDidSaveNearableZoneDescription after successful save.
 *  Data is stored in Shared Group Container, specified as currentAppGroupIdentifier.
 *  If item was already saved it will be overwritten.
 *
 *  @param zone Zone description
 *  @see - (NSString *)readNearableZoneDescription
 *
 *  @return YES if saving operation was successful, otherwise NO.
 */
- (BOOL)saveNearableZoneDescription:(NSString *)zone;

/**
*  Use this method to read previously saved Nearable Zone Description.
*  Data is read from Shared Group Container, specified as currentAppGroupIdentifier.
*
*  @see - (BOOL)saveNearableZoneDescription:
*
*  @return Nearable Zone Description.
*/
- (NSString *)readNearableZoneDescription;

/**
*  Use this method to save ESTNearable object.
*  It sends ESTNotificationDidSaveNearable after successful save.
*  Data is stored in Shared Group Container, specified as currentAppGroupIdentifier.
*  If item was already saved it will be overwritten.
*
*  @param nearable Nearable you want to save.
*  @see - (ESTNearable *)readNearable
*
*  @return YES if saving operation was successful, otherwise NO.
*/
- (BOOL)saveNearable:(ESTNearable *)nearable;

/**
*  Use this method to read previously saved ESTNearable object.
*  Data is read from Shared Group Container, specified as currentAppGroupIdentifier.
*
*  @see - (BOOL)saveNearable
*
*  @return ESTNearable object.
*/
- (ESTNearable *)readNearable;

/**
*  didRangeNearables provides mechanism for exchanging ranged Nearables data
*  between host app and extension.
*
*  @param nearables Ranged nearables array.
*
*  @return YES if saving operation was successful, otherwise NO.
*/
- (BOOL)didRangeNearables:(NSArray *)nearables;

/**
*  readRangedNearables allows you to read Nearables previously saved
*  by didRangeNearables method.
*
*  @return Array of Nearables ranged by host app
*/
- (NSArray *)readRangedNearables;

/**
 *  Notify Extension about didEnterRegion event for CLBeaconRegion object.
 *  Use this method for iBeacon and Nearables devices.
 *  In order to get CLBeaconRegion for Nearable use
 *  - (CLBeaconRegion *)beaconRegion method of ESTNearable class.
 * 
 *  You can get CLBeaconRegion object from NSNotification.userInfo object
 *  under BEACON_REGION_KEY key.
 *
 *  @param region Entered CLBeaconRegion.
 */
- (void)notifyDidEnterRegion:(CLBeaconRegion *)region;

/**
 *  Notify Extension about didExitRegion event for CLBeaconRegion object.
 *  Use this method for iBeacon and Nearables devices.
 *  In order to get CLBeaconRegion for Nearable use
 *  - (CLBeaconRegion *)beaconRegion method of ESTNearable class.
 *
 *  You can get CLBeaconRegion object from NSNotification.userInfo object
 *  under BEACON_REGION_KEY key.
 *
 *  @param region Exited CLBeaconRegion.
 */
- (void)notifyDidExitRegion:(CLBeaconRegion *)region;

/**
 *  Notify Extension about didEnterIdentifierRegion event for ESTNearable object.
 *  This method automatically saves identifier.
 *  After receiving ESTNotificationDidNearableEnterRegion, identifier can be fetched
 *  with readIdentifierForMonitoringEvents method.
 *
 *  @param identifier Entered ESTNearable region, defined as NSString.
 */
- (void)notifyDidEnterIdentifierRegion:(NSString *)identifier;

/**
 *  Notify Extension about didExitIdentifierRegion event for ESTNearable object.
 *  This method automatically saves identifier.
 *  After receiving ESTNotificationDidNearableExitRegion, identifier can be fetched
 *  with readIdentifierForMonitoringEvents method.
 *
 *  @param identifier Exited ESTNearable region, defined as NSString.
 */
- (void)notifyDidExitIdentifierRegion:(NSString *)identifier;

/**
 *  Read Identifier for monitoring events.
 *  Data is read from Shared Group Container, specified as currentAppGroupIdentifier.
 *
 *  @return Returns Identifier associated with ESTNearable object, monitored by ESTNearableManager.
 */
- (NSString *)readIdentifierForMonitoringEvents;

- (void)addObserver:(id)observer selector:(SEL)selector forNotification:(ESTNotification)notification;
- (void)removeObserver:(id)observer;

@end
