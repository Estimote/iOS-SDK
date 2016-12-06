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
#import "ESTTelemetryInfoGPIO.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block fired every time new telemetry packet containing GPIO info was ranged.
 *
 *  @param gpio Info object with GPIO ports values.
 */
typedef void(^ESTTelemetryNotificationGPIONotificationBlock)(ESTTelemetryInfoGPIO *gpio);


/**
 *  ESTTelemetryNotificationGPIO allows to register for GPIO related telemetry information
 *  in `ESTUtilityManager` using `registerForTelemetryNotifications:` method. 
 *
 *  As a result of registration each time telemetry packet is ranged provided notification
 *  block is fired providing `ESTTelemetryInfoGPIO` object with current GPIO ports values.
 */
@interface ESTTelemetryNotificationGPIO : NSObject <ESTTelemetryNotificationProtocol>

/**
 *  Method allows to initialize object with notification block.
 *
 *  @param notificationBlock Block fired every time GPIO port values are delivered from telemetry packet.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithNotificationBlock:(ESTTelemetryNotificationGPIONotificationBlock)notificationBlock;

@end

NS_ASSUME_NONNULL_END
