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

#import "ESTBaseVO.h"
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for iBeacon advertiser.
 */
@interface ESTDeviceSettingsAdvertiserIBeacon : ESTDeviceSettingsAdvertiser

/**
 *  Broadcasted iBeacon Proximity UUID value.
 */
@property (nonatomic, strong, readonly) NSUUID *proximityUUID;

/**
 *  Broadcasted iBeacon major value.
 */
@property (nonatomic, strong, readonly) NSNumber *major;

/**
 *  Broadcasted iBeacon minor value.
 */
@property (nonatomic, strong, readonly) NSNumber *minor;

/**
 *  Flag indications if Non Strict Mode is enabled. When YES it is possible
 *  to change Advertising interval of advertiser and enable Smart Power Mode.
 */
@property (nonatomic, strong, readonly) NSNumber *nonStrictModeEnabled;

/**
 *  Flag indicates if Secure Proximity UUID is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *securityEnabled;

/**
 *  Security interval scaler indicates how often Secure Proximity UUID is rotated.
 */
@property (nonatomic, strong, readonly) NSNumber *securityIntervalScaler;

/**
 *  Flag indicates if Motion UUID is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *motionUUIDEnabled;

@end

NS_ASSUME_NONNULL_END
