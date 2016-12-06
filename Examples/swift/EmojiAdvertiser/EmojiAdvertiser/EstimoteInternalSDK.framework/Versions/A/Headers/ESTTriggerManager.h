//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTTrigger.h"
#import "ESTDateRule.h"
#import "ESTNearableRule.h"
#import "ESTProximityRule.h"
#import "ESTTemperatureRule.h"
#import "ESTMotionRule.h"
#import "ESTOrientationRule.h"

NS_ASSUME_NONNULL_BEGIN

@class ESTTriggerManager;


/**
 *  The `ESTTriggerManagerDelegate` protocol defines the delegate methods used to receive trigger state change events from an `<ESTTriggerManager>` object. Trigger manager engine allows to introduce higher level of abstraction and let developer focus on the acctual logic their application should follow. Each trigger is defined by set of rules that should be fulfilled to change make trigger state to positive. Change of trigger state is reported using `<[ESTTriggerManagerDelegate triggerManager:triggerChangedState:]>` method of your `<delegate>`. Out of the box trigger manager supports rules related to nearable proximity, motion and orientation, ambient nearable temperature as well as time and date.
 *
 *  In addition you can create your own rule definition related to parameters you are interested in (eg. weather information, GPS postion). To create new rule just create class that inherits from `<ESTRule>` class.
 */
@protocol ESTTriggerManagerDelegate <NSObject>

@optional

/**
 *  Informs delegate object about change for patricular trigger state (fullfiled or not).
 *
 *  @param manager The trigger manager object reporting the event.
 *  @param trigger trigger that has change its state (ESTTrigger object contains current state in state property).
 */
- (void)triggerManager:(ESTTriggerManager *)manager triggerChangedState:(ESTTrigger *)trigger;

@end

/**
 * The `ESTTriggerManager` class defines the interface for defining real life rules based triggers.
 */

@interface ESTTriggerManager : NSObject <ESTTriggerDelegate>

@property (nonatomic, weak) id<ESTTriggerManagerDelegate> _Nullable delegate;

/**
 *  Array of alraedy registered monitored triggers.
 */
@property (nonatomic, strong, readonly) NSArray<ESTTrigger *> *triggers;

/**
 *  Starts monitoring for defined trigger.
 *
 *  Events are delivered to the `<[ESTTriggerManagerDelegate triggerManager:triggerChangedState:]>` method of your `<delegate>`.
 *
 *  @param trigger Trigger object that you want to monitor for. This parameter must not be `nil`.
 *
 *  @see stopMonitoringForTriggerWithIdentifier:
 */
- (void)startMonitoringForTrigger:(ESTTrigger *)trigger;

/**
 *  Stops monitoring for defined trigger.
 *
 *  If object with specified identifier is not currently being monitored, this method has no effect.
 *
 *  @param identifier Trigger identifier that was defined for trigger passed to startMonitoringForTrigger method. This parameter must not be `nil`.
 *
 *  @see startMonitoringForTrigger:
 */
- (void)stopMonitoringForTriggerWithIdentifier:(NSString *)identifier;

/**
 *  Returns state for trigger with given identifier.
 *
 *  If object with specified identifier is not currently being monitored, this method will return NO.
 *
 *  @param identifier Trigger identifier that was defined for trigger passed to startMonitoringForTrigger method.
 *
 *  @see startMonitoringForTrigger:
 */
- (BOOL)stateForTriggerWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
