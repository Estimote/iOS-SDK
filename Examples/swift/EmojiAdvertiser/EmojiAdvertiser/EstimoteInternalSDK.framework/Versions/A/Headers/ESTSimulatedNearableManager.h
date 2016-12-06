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

#import "ESTNearableManager.h"

NS_ASSUME_NONNULL_BEGIN

/**
* ESTSimulatedNearableManager is a class for simulating Nearables (ESTNearable) objects.
*/

@interface ESTSimulatedNearableManager : ESTNearableManager <ESTNearableManagerDelegate>

/**
* Array with simulated ESTNearable objects.
*/
@property (nonatomic, strong, readonly) NSMutableArray<ESTNearable *> *nearables;

/**
*  Initializer with delegate.
*
*  @param delegate       Set delegate for ESTNearableManagerDelegate updates.
*
*  @return Instance of this object.
*/
- (instancetype)initWithDelegate:(id<ESTNearableManagerDelegate> _Nullable)delegate;

/**
*  Use this initializer if you want to specify nearables in JSON.
*  Providing only filename is sufficient, but remember that your file
*  should be *.json type and accessible from MainBundle.
*  By default, order of nearables in the list will be reflected in nearables array,
*  which means, this class do not provide simulation of fluctuating RSSI or proximity.
*  However, you can set those values in JSON file, they will be parsed into ESTNearable object.
*
*  @param delegate        Set delegate for ESTNearableManagerDelegate updates.
*  @param path            Path for json file with description of nearables you want to simulate.
*
*  @return Instance of this object.
*/
- (instancetype)initWithDelegate:(id<ESTNearableManagerDelegate> _Nullable)delegate
                     pathForJSON:(NSString *)path;

- (ESTNearable *)generateRandomNearableAndAddToSimulator:(BOOL)add;

#pragma mark - Adding Nearables

/**
* Add single nearable by specifying params. ESTNearable object
* will be inserted into nearables array.
*
* @param identifier Identifier for ESTNearable object.
* @param type       Nearable type
* @param zone       Nearable zone
* @param rssi       Nearable rssi
*/
- (void)addNearableToSimulation:(NSString *)identifier
                       withType:(ESTNearableType)type
                           zone:(ESTNearableZone)zone
                           rssi:(NSInteger)rssi;

/**
*  If you used initWithDelegate: initializer to create this class
*  and later you want to range nearables with type, use this method
*  to set array of nearables.
*
* @param path   Path for json file with description of nearables you want to simulate.
*/
- (void)addNearablesToSimulationWithPath:(NSString *)path;

#pragma mark - Simulations

/**
 *  Set desired zone for your simulated ESTNearableObject.
 *
 *  @param zone         ESTNearableZone to set.
 *  @param identifier   Identifier of ESTNearable you want to change.
 */
- (void)simulateZone:(ESTNearableZone)zone forNearable:(NSString *)identifier;

/**
 *  Simulate enter region event for your nearable.
 *  Ranging will automatically start after calling this method.
 *  Callback method is nearableManager:didEnterIdentifierRegion from ESTNearableManagerDelegate protocol.
 *  If you do not implement didEnterIdentifierRegion code will crash,
 *  it's not checking whether delegate implemented method or not.
 *  This is 'by design'. During testing you probably want to know
 *  when your class don't implement ESTNearableManager delegates.
 *
 *  @param nearable Nearable object for this event.
 */
- (void)simulateDidEnterRegionForNearable:(ESTNearable *)nearable;

/**
 *  Simulate exit region event for your nearable.
 *  Ranging will automatically stop after calling this method.
 *  Callback method is nearableManager:didExitIdentifierRegion from ESTNearableManagerDelegate protocol.
 *  If you do not implement didExitIdentifierRegion code will crash,
 *  it's not checking whether delegate implemented method or not.
 *  This is 'by design'. During testing you probably want to know
 *  when your class don't implement ESTNearableManager delegates.
 *
 *  @param nearable Nearable object for this event.
 */
- (void)simulateDidExitRegionForNearable:(ESTNearable *)nearable;

@end

NS_ASSUME_NONNULL_END
