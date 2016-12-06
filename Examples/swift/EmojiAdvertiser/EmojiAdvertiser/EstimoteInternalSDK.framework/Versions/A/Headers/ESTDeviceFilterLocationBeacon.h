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
 *  Class defines scanning & filtering attributes required by ESTDeviceManager to discover devices that can be connected to.
 *  Results in -[ESTDeviceManagerDelegate deviceManager:didDiscoverDevices:] being called with a collection of
 *  ESTDeviceLocationBeacon objects.
 *
 *  @see -[ESTDeviceManager startDeviceDiscoveryWithFilter:].
 */
@interface ESTDeviceFilterLocationBeacon : NSObject <ESTDeviceFilter>

/**
 *  Initializes ESTDeviceFilterTypeUtility object without a predicate.
 *  Use this init to discover devices that can be connected to without additional filtering.
 *
 *  @return Initialized filter object.
 */
- (instancetype)init;

/**
 *  Initializes ESTDeviceFilterTypeUtility object with a predicate for filtering by identifier.
 *  Use this method to find a particular device that can be connected to, since the identifier is unique for Estimote devices.
 *
 *  @param identifier Identifier of the searched device.
 *
 *  @return Initialized filter object.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier;

/**
 *  Initializes ESTDeviceFilterTypeUtility object with a predicate for filtering by identifiers.
 *  Use this method to find a particular devices with given identifiers that can be connected to, since the identifier is unique for Estimote devices.
 *
 *  @param identifiers Array of searched devices' identifiers.
 *
 *  @return Initialized filter object.
 */
- (instancetype)initWithIdentifiers:(NSArray <NSString *> *)identifiers;

@end

NS_ASSUME_NONNULL_END
