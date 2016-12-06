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

@class ESTLocation;
@class ESTLocationManager;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTLocationManagerDelegateProtocol defines delegate protocol for `ESTLocationManager` class objects.
 */
@protocol ESTLocationManagerDelegateProtocol <NSObject>

@optional
/**
 *  Method returns all discovered Estimote Locations in the nearby surrounding.
 *
 *  @param locationManager Manager that discovered Estimote Location.
 *  @param locations       Array of locations discovered by the manager.
 *
 *  @see `startLocationDiscoveryWithIdentifier`
 */
- (void)locationManager:(ESTLocationManager *)locationManager didDiscoverLocations:(NSArray<ESTLocation *> *)locations;

/**
 *  Methods invoked when Discovery process failed. The reason of failure 
 *  Is provided in Error message.
 *
 *  @param locationManager Manager that was used for discovery.
 *  @param error           Error with information about error of failure.
 */
- (void)locationManager:(ESTLocationManager *)locationManager didFailLocationDiscoveryWithError:(NSError *)error;

@end


/**
 *  ESTLocationManager allows to scan for all Estimote Location Packets.
 *  Location packets can be broadcasted among other packets by Estimote
 *  Location Beacons.
 */
@interface ESTLocationManager : NSObject

/**
 *  Delegate of Location Manager object that handles discovered
 *  locations.
 */
@property (nonatomic, strong) id<ESTLocationManagerDelegateProtocol> delegate;

/**
 *  Initializer of that class allowing to set delegate object.
 *
 *  @param delegate Delegate object for Location Manager object.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDelegate:(nullable id<ESTLocationManagerDelegateProtocol>)delegate;

/**
 *  Method allows to start location discovery process.
 *
 *  @param locationIdentifier Identifier of desired location.
 *
 *  @see locationManager:didDiscoverLocations:
 */
- (void)startLocationDiscoveryWithIdentifier:(nullable NSString *)locationIdentifier;

/**
 *  Method allows to stop location discovery.
 */
- (void)stopLocationDiscovery;

@end

NS_ASSUME_NONNULL_END
