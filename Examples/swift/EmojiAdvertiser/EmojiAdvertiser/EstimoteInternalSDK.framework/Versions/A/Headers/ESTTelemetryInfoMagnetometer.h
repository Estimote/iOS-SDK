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
@interface ESTTelemetryInfoMagnetometer : ESTTelemetryInfo

/**
 * Strength of magnetic field in X axis in normalized values (-1, 1).
 */
@property (nonatomic, strong, readonly) NSNumber *normalizedMagneticFieldX;

/**
 * Strength of magnetic field in Y axis in normalized values (-1, 1).
 */
@property (nonatomic, strong, readonly) NSNumber *normalizedMagneticFieldY;

/**
 * Strength of magnetic field in Z axis in normalized values (-1, 1).
 */
@property (nonatomic, strong, readonly) NSNumber *normalizedMagneticFieldZ;

/**
 * Designated initializer of this class.
 *
 * @param fieldX Magnetic field in X axis, read from telemetry packet.
 * @param fieldY Magnetic field in Y axis, read from telemetry packet.
 * @param fieldZ Magnetic field in Z axis, read from telemetry packet.
 * @param shortIdentifier Short identifier of device that sent telemetry packet.
 *
 * @return Instance of this class.
 */
- (instancetype)initWithNormalizedMagneticFieldX:(NSNumber *)fieldX
                        normalizedMagneticFieldY:(NSNumber *)fieldY
                        normalizedMagneticFieldZ:(NSNumber *)fieldZ
                                 shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
