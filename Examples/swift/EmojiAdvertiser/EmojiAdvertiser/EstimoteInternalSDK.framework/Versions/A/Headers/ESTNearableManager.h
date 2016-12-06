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
#import "ESTNearable.h"

NS_ASSUME_NONNULL_BEGIN

@class ESTNearableManager;

/**
 * The `ESTNearableManagerDelegate` protocol defines the delegate methods used to receive nearable ranging and monitoring events from an `<ESTNearableManager>` object.
 */
@protocol ESTNearableManagerDelegate <NSObject>

@optional

#pragma mark Ranging delegate methods
///--------------------------------------------------------------------
/// @name Ranging delegate methods
///--------------------------------------------------------------------

/**
 * Tells the delegate that one or more nearables are in range.
 *
 * @param manager The nearable manager object reporting the event.
 * @param nearables An array of `<ESTNearable>` objects representing the nearables currently in range. You can use the information in these objects to determine the range of each nearables and its identifying information.
 * @param type The nearable type that was used to range the nearables.
 */
- (void)nearableManager:(ESTNearableManager *)manager didRangeNearables:(NSArray<ESTNearable *> *)nearables withType:(ESTNearableType)type;

/**
 * Tells the delegate that nearable with particular identifier is in range.
 *
 * @param manager The nearable manager object reporting the event.
 * @param nearables An `<ESTNearable>` object representing the nearables currently in range. You can use the information in these objects to determine the range of nearable and its identifying information.
 */
- (void)nearableManager:(ESTNearableManager *)manager didRangeNearable:(ESTNearable *)nearable;

/**
 * Tells the delegate that nearable ranging error occurred.
 *
 * @param manager The nearable manager object reporting the event.
 * @param error An error object describing why monitoring failed.
 */
- (void)nearableManager:(ESTNearableManager *)manager rangingFailedWithError:(NSError *)error;


#pragma mark Monitoring delegate methods
///--------------------------------------------------------------------
/// @name Monitoring delegate methods
///--------------------------------------------------------------------


/**
 * Tells the delegate that the user entered region of specified nearable type.
 *
 * @param manager The nearable manager object reporting the event.
 * @param type The nearable type region that was entered.
 */
- (void)nearableManager:(ESTNearableManager *)manager didEnterTypeRegion:(ESTNearableType)type;

/**
 * Tells the delegate that the user left the region of specified nearable type.
 *
 * @param manager The nearable manager object reporting the event.
 * @param type The nearable type region that was exited.
 */
- (void)nearableManager:(ESTNearableManager *)manager didExitTypeRegion:(ESTNearableType)type;

/**
 * Tells the delegate that the user entered region of specified nearable identifier.
 *
 * @param manager The nearable manager object reporting the event.
 * @param identifier The nearable identifier region that was entered.
 */
- (void)nearableManager:(ESTNearableManager *)manager didEnterIdentifierRegion:(NSString *)identifier;

/**
 * Tells the delegate that the user left the region of specified nearable identifier.
 *
 * @param manager The nearable manager object reporting the event.
 * @param identifier The nearable identifier region that was exited.
 */
- (void)nearableManager:(ESTNearableManager *)manager didExitIdentifierRegion:(NSString *)identifier;

/**
 * Tells the delegate that nearable monitoring error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param error An error object describing why monitoring failed.
 */
- (void)nearableManager:(ESTNearableManager *)manager monitoringFailedWithError:(NSError *)error;

@end

/**
 * The `ESTNearableManager` class defines the interface for ranging and monitoring nearables.
 */

@interface ESTNearableManager : NSObject

@property (nonatomic, weak) id <ESTNearableManagerDelegate> _Nullable delegate;

#pragma mark - Nearable monitoring related methods
///--------------------------------------------------------------------
/// @name Nearable monitoring related methods
///--------------------------------------------------------------------

/**
 * Starts monitoring for nearable with specified identifier.
 *
 * Events are delivered to the `<[ESTNearableManagerDelegate nearableManager:didEnterIdentifierRegion:]>` and `<[ESTNearableManagerDelegate nearableManager:didExitIdentifierRegion:]>` methods of your `<delegate>`. If there is an error, the nearable manager calls the `<[ESTNearableManagerDelegate nearableManager:monitoringFailedWithError:]>` method of your `delegate` instead.
 *
 * @param identifier Nearable unique identifier that you want to monitor for. This parameter must not be `nil.`
 *
 * @see nearableManager:stopMonitoringForIdentifier:
 */
- (void)startMonitoringForIdentifier:(NSString *)identifier;

/**
 * Stops monitoring for nearable with specified identifier.
 *
 * If object with specified identifier is not currently being monitored, this method has no effect.
 *
 * @param identifier The object's identifier currently being monitored. This parameter must not be `nil`.
 *
 * @see nearableManager:startMonitoringForIdentifier:
 */
- (void)stopMonitoringForIdentifier:(NSString *)identifier;

/**
 * Starts monitoring for nearables with specified type.
 *
 * Events are delivered to the `<[ESTNearableManagerDelegate nearableManager:didEnterTypeRegion:]>` and `<[ESTNearableManagerDelegate nearableManager:didExitTypeRegion:]>` methods of your `<delegate>`. If there is an error, the nearable manager calls the `<[ESTNearableManagerDelegate nearableManager:monitoringFailedWithError:]>` method of your `delegate` instead.
 *
 * @param type Nearable type that you want to monitor for. This parameter must not be `nil.`
 *
 * @see nearableManager:stopMonitoringForIdentifier:
 */
- (void)startMonitoringForType:(ESTNearableType)type;

/**
 * Stops monitoring for nearables with specified type.
 *
 * If objects with specified type are not currently being monitored, this method has no effect.
 *
 * @param type The nearable type currently being monitored. This parameter must not be `nil`.
 *
 * @see nearableManager:startMonitoringForType:
 */
- (void)stopMonitoringForType:(ESTNearableType)type;

/**
 * Stops monitoring for all types and identifiers that were monitored.
 *
 * If there is nothing currently being monitored, this method has no effect.
 *
 * @see nearableManager:stopMonitoringForIdentifier:
 * @see nearableManager:stopMonitoringForType:
 */
- (void)stopMonitoring;

#pragma mark - Nearable ranging related methods
///--------------------------------------------------------------------
/// @name Nearable ranging related methods
///--------------------------------------------------------------------

/**
 * Starts the delivery of notifications for nearables with specified identifier.
 *
 * Once registered, the nearable manager reports any encountered nearable to its delegate by calling the `<[ESTNearableManagerDelegate nearableManager:didRangeNearable:]>` method. If there is an error registering the specified nearable type, the nearable manager calls its delegate's `<[ESTNearableManagerDelegate nearableManager:rangingFailedWithError:]>` method and provides the appropriate error information.
 *
 * @param identifier The identifier of nearables. This parameter must not be `nil`
 *
 * @see stopRangingForType:
 */
- (void)startRangingForIdentifier:(NSString *)identifier;

/**
 * Stops the delivery of notifications for the specified nearable identifier.
 *
 * @param identifier The identifier of nearables. This parameter must not be `nil`
 *
 * @see nearableManager:startRangingForType:
 */
- (void)stopRangingForIdentifier:(NSString *)identifier;

/**
 * Starts the delivery of notifications for nearables with specified type.
 *
 * Once registered, the nearable manager reports any encountered nearable to its delegate by calling the `<[ESTNearableManagerDelegate nearableManager:didRangeNearables:withType:]>` method. If there is an error registering the specified nearable type, the nearable manager calls its delegate's `<[ESTNearableManagerDelegate nearableManager:rangingFailedWithError:]>` method and provides the appropriate error information.
 *
 * @param type The type of nearables. This parameter must not be `nil`
 *
 * @see stopRangingForType:
 */
- (void)startRangingForType:(ESTNearableType)type;

/**
 * Stops the delivery of notifications for the specified nearable type.
 *
 * @param type The type of nearables. This parameter must not be `nil`
 *
 * @see startRangingForType:
 */
- (void)stopRangingForType:(ESTNearableType)type;

/**
 * Stops ranging all types and identifiers that were ranged.
 *
 * If there is nothing currently being ranged, this method has no effect.
 *
 * @see stopRangingForIdentifier:
 * @see stopRangingForType:
 */
- (void)stopRanging;

@end

NS_ASSUME_NONNULL_END
