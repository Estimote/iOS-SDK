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

#import "ESTDeviceSettingsAdvertiser.h"

/**
 *  This Value Object represents settings structure for Estimote EID advertiser.
 */

@interface ESTDeviceSettingsAdvertiserEddystoneEID : ESTDeviceSettingsAdvertiser

/**
 *  Eddystone EID identity key value.
 */
@property (nonatomic, strong, readonly) NSString *identityKey;

/**
 *  Eddystone EID rotation scaler value.
 */
@property (nonatomic, strong, readonly) NSNumber *rotationScaler;

/**
 *  Eddystone EID registered namespace identifier.
 */
@property (nonatomic, strong, readonly) NSString *registeredNamespaceID;

/**
 *  Eddystone EID registered instance identifier.
 */
@property (nonatomic, strong, readonly) NSString *registeredInstanceID;

@end
