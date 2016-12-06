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
#import "ESTTelemetryNotificationProtocol.h"
#import "ESTTelemetryInfoAmbientLight.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ESTTelemetryNotificationAmbientLightNotificationBlock)(ESTTelemetryInfoAmbientLight *ambientLight);


/**
 * ESTTelemetryNotificationAmbientLight class is used to
 * initialize block that will be fired everytime
 * new telemetry packet was ranged.
 * As a parameter of ESTTelemetryNotificationAmbientLightCompletionBlock
 * expect ESTTelemetryInfoAmbientLight object that transmits
 * ambient light value (in lux) read by beacon.
 */
@interface ESTTelemetryNotificationAmbientLight : NSObject <ESTTelemetryNotificationProtocol>

/**
 * This init takes notificationBlock as a parameter, which will be fired
 * with every telemetry packet discovered.
 *
 * @param block ESTTelemetryNotificationAmbientLightCompletionBlock
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationAmbientLightNotificationBlock)block;

@end

NS_ASSUME_NONNULL_END
