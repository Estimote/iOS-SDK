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

#import <Foundation/Foundation.h>
#import "ESTDeviceFilter.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Class defines scanning & filtering attributes required by ESTDeviceManager to discover iBeacon devices.
 *  Results in -[ESTDeviceManagerDelegate deviceManager:didDiscoverDevices:] being called with collection of
 *  ESTBluetoothBeacon objects.
 *
 *  Note.
 *  For now, ESTDeviceManager cannot retrieve Proximity UUID of the scanned devices.
 *  To find a particular iBeacon device use -initWithIdentifier: (the identifier property is unique for Estimote devices).
 *
 *  @see -[ESTDeviceManager startDeviceDiscoveryWithFilter:].
 */
@interface ESTDeviceFilterBeaconV1 : NSObject <ESTDeviceFilter>

/**
 *  Initializes ESTDeviceFilterIBeacon object without a predicate. 
 *  Use this init to discover iBeacon devices without additional filtering.
 *
 *  @return Initialized filter object.
 */
- (instancetype)init;

/**
 *  Initializes ESTDeviceFilterIBeacon object with a predicate for filtering by identifier.
 *  Use this method to find a particular iBeacon device, since the identifier is unique for Estimote devices.
 *
 *  @param identifier Identifier of the searched iBeacon device.
 *
 *  @return Initialized filter object.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
