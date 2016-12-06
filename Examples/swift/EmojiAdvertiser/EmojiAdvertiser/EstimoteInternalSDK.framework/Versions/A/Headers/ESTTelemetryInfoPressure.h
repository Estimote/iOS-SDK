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

#import "ESTTelemetryInfo.h"

NS_ASSUME_NONNULL_BEGIN


/**
 * This class contains data read from telemetry packet from beacon device.
 */
@interface ESTTelemetryInfoPressure : ESTTelemetryInfo

/**
 *  Atmospheric pressure in pascals.
 */
@property (nonatomic, strong, readonly) NSNumber *pressureInPascals;

/**
 * Designated initializer of this class.
 *
 * @param pressureInPascals Atmospheric pressure, read from telemetry packet.
 * @param shortIdentifier Short identifier of device that sent telemetry packet.
 *
 * @return Instance of this class.
 */
- (instancetype)initWithPressureInPascals:(NSNumber *)pressureInPascals
                          shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
