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

#import "ESTBaseVO.h"

@class ESTDeviceSettings;

typedef NS_ENUM(NSInteger, ESTMeshNetworkType)
{
    ESTMeshNetworkTypeStandard
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTMeshNetworkDetailsVO represents vaule object of Mesh network's details stored in Estimote Cloud.
 */
@interface ESTMeshNetworkDetailsVO : ESTBaseVO <NSCopying, NSCoding>

/**
 *  Mesh network's identifier.
 */
@property (nonatomic, strong, readonly) NSNumber *networkIdentifier;

/**
 *  Mesh network's name.
 */
@property (nonatomic, strong, readonly) NSString *networkName;

/**
 *  Mesh network's type.
 */
@property (nonatomic, assign, readonly) ESTMeshNetworkType networkType;

/**
 *  Temp. warning - Don't modify this! List of devices that Mesh consists of. Each device has already applied Mesh network's settings.
 */
@property (nonatomic, strong, readwrite) NSArray *devices;

/**
 *  Mesh network's settings shared among all devices included in the Mesh.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *settings;

/**
 *  Mesh network's settings version in form of timestamp. Use -updateSettingsVersion when applying any change of settings in device belonging to Mesh network.
 */
@property (nonatomic, assign, readonly) NSTimeInterval settingsVersion;

/**
 *  Method allows to initialize value object.
 *
 *  @param  networkIdentifier    Identifier of Mesh network.
 *  @param  networkName Name of Mesh network.
 *  @param  devices Identifiers of devices to be included in Mesh network.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithIdentifier:(NSNumber *)networkIdentifier
                              name:(NSString *)networkName;

@end

NS_ASSUME_NONNULL_END
