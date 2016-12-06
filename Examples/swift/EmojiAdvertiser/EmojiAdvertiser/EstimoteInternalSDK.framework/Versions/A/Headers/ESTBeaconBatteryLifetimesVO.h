//
//  ESTBeaconBatteryLifetimesVO.h
//  EstimoteSDK
//
//  Created by Łukasz Pikor on 25.06.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTBeaconBatteryLifetimesVO : NSObject

- (instancetype)initWithLifetimes:(NSDictionary *)lifetimes;

- (NSString *)lifetimeForAdvertisingInterval:(int)interval;
- (NSString *)lifetimeForBroadcastingPower:(int)power;
- (NSString *)lifetimeForBasicPowerMode:(ESTBeaconPowerSavingMode)basic
                               andSmart:(ESTBeaconPowerSavingMode)smart;
- (NSString *)lifetimeForBroadcastingScheme:(ESTBroadcastingScheme)scheme;

- (BOOL)shouldDisplayAlertForAdvertisingInterval:(int)interval;
- (BOOL)shouldDisplayAlertForBroadcastingPower:(int)power;
- (BOOL)shouldDisplayAlertForBasicPowerMode:(ESTBeaconPowerSavingMode)basic
                                   andSmart:(ESTBeaconPowerSavingMode)smart;

@end

NS_ASSUME_NONNULL_END
