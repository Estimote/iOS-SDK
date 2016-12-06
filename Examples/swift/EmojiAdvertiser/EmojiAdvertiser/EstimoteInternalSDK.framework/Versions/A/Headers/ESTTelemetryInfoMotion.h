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
@interface ESTTelemetryInfoMotion : ESTTelemetryInfo

/**
 *  Accelerometer data related to X axis.
 */
@property (nonatomic, strong, readonly) NSNumber *accelerationX;

/**
 *  Accelerometer data related to Y axis.
 */
@property (nonatomic, strong, readonly) NSNumber *accelerationY;

/**
 *  Accelerometer data related to Z axis.
 */
@property (nonatomic, strong, readonly) NSNumber *accelerationZ;

/**
 * Duration of previous motion state.
 */
@property (nonatomic, strong, readonly) NSNumber *previousMotionStateDurationInSeconds;

/**
 * Duration of current motion state.
 */
@property (nonatomic, strong, readonly) NSNumber *currentMotionStateDurationInSeconds;

/**
 * Motion state of device. 0 means not moving, 1 means moving.
 */
@property (nonatomic, strong, readonly) NSNumber *motionState;

/**
 * Designated initializer of this class.
 *
 * @param accelerationX Data from beacons X axis, read from telemetry packet.
 * @param accelerationY Data from beacons Y axis, read from telemetry packet.
 * @param accelerationZ Data from beacons Z axis, read from telemetry packet.
 * @param previousMotionStateDurationInSeconds Duration of previous motion state, read from telemetry packet.
 * @param currentMotionStateDurationInSeconds Duration of current motion, read from telemetry packet.
 * @param motionState Current motion state, read from telemetry packet.
 * @param shortIdentifier Short identifier of device that sent telemetry packet
 *
 * @return Instance of this class.
 */
- (instancetype)initWithAccelerationX:(NSNumber *)accelerationX
                        accelerationY:(NSNumber *)accelerationY
                        accelerationZ:(NSNumber *)accelerationZ
 previousMotionStateDurationInSeconds:(NSNumber *)previousMotionStateDurationInSeconds
  currentMotionStateDurationInSeconds:(NSNumber *)currentMotionStateDurationInSeconds
                          motionState:(NSNumber *)motionState
                      shortIdentifier:(NSString *)shortIdentifier;

@end

NS_ASSUME_NONNULL_END
