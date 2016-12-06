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
#import "ESTEddystone.h"
#import "ESTEddystoneUID.h"
#import "ESTEddystoneURL.h"
#import "ESTEddystoneTLM.h"
#import "ESTEddystoneEID.h"
#import "ESTEddystoneFilter.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ESTEddystoneManagerState)
{
    ESTEddystoneManagerStateIdle,
    ESTEddystoneManagerStateScanning
};

@class ESTEddystoneManager;

/**
* Protocol for `ESTEddystoneManager` delegate object. Allows to handle callbacks
* from Eddystone devices discovery process.
*/

@protocol ESTEddystoneManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that one or more beacons were discovered in the vicinity of the device.
 *
 * @param manager The Eddystone Manager object reporting the event.
 * @param eddystones An array of `<ESTEddystone>` objects representing the beacons discovered.
 * @param eddystoneFilter Filter represented by subclass of `<ESTEddystoneFilter>` applied to discovery.
 */
- (void)eddystoneManager:(ESTEddystoneManager *)manager
   didDiscoverEddystones:(NSArray<ESTEddystone *> *)eddystones
              withFilter:(ESTEddystoneFilter * _Nullable)eddystoneFilter;

/**
 * Tells the delegate that Google beacons discovery error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 */
- (void)eddystoneManagerDidFailDiscovery:(ESTEddystoneManager *)manager
                               withError:(NSError * _Nullable)error;

@end

/**
 * The `ESTEddystoneManager` class defines entry point to interact with Google Eddystones.
 * As a core functionality it allows to discover Eddystone devices available in range.
 *
 * Discovery process is based on simple filtering mechanism. As Eddystone devices can
 * advertise Eddystone-UID or Eddystone-URL packets, separate filters are available.
 * Multiple filters can be used at the same time. When using more then one filter, manager
 * will call `eddystoneManager:didDiscoverEddystones:withFilter` callback for each filter
 * separately with corresponding filter provided.
 */

@interface ESTEddystoneManager : NSObject

/**
 *  Delegate object.
 */
@property (nonatomic, weak) id<ESTEddystoneManagerDelegate> _Nullable delegate;

/**
 *  Array containg `ESTEddystoneFilter` objects for requested UUID discovery.
 */
@property (nonatomic, strong, readonly) NSArray<ESTEddystoneFilter *> *filtersInDiscovery;

/**
 * Starts Eddystone discovery process. Filter param is optional. 
 * When not provided (nil) manager discovers all devices in range.
 * Optional filters are:
 * - UID identifier - consists of Namespace ID (10 bytes) and Instance ID (6 bytes).
 * - URL - URL address eg. 'http://go.esti.be'
 * - URL Domain - URL domain eg. 'esti.be'
 */
- (void)startEddystoneDiscoveryWithFilter:(ESTEddystoneFilter * _Nullable)eddystoneFilter;

/**
 * Stops discovery of Eddystones for particular filter.
 */
- (void)stopEddystoneDiscoveryWithFilter:(ESTEddystoneFilter * _Nullable)eddystoneFilter;

@end

NS_ASSUME_NONNULL_END
