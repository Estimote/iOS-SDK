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
#import "ESTBeaconDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTBeaconVO : NSObject <NSCoding>

@property (nonatomic, strong) NSString *proximityUUID;
@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic, strong) NSString *macAddress;
@property (nonatomic, strong) NSString *publicIdentifier;
@property (nonatomic, assign) ESTBroadcastingScheme broadcastingScheme;
@property (nonatomic, assign) ESTBeaconMotionUUID motionUUIDState;

@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSNumber *batteryLifeExpectancy;
@property (nonatomic, strong, nullable) NSString *hardware;
@property (nonatomic, strong, nullable) NSString *firmware;
@property (nonatomic, assign) ESTBeaconPower power;
@property (nonatomic, assign) NSInteger advInterval;

@property (nonatomic, strong, nullable) NSNumber *basicPowerMode;
@property (nonatomic, strong, nullable) NSNumber *smartPowerMode;
@property (nonatomic, strong, nullable) NSNumber *batteryLevel;

@property (nonatomic, strong, nullable) NSNumber *latitude;
@property (nonatomic, strong, nullable) NSNumber *longitude;
@property (nonatomic, strong, nullable) NSDictionary *location;
@property (nonatomic, strong, nullable) NSString *city;
@property (nonatomic, strong, nullable) NSString *country;
@property (nonatomic, strong, nullable) NSString *formattedAddress;
@property (nonatomic, strong, nullable) NSString *stateName;
@property (nonatomic, strong, nullable) NSString *stateCode;
@property (nonatomic, strong, nullable) NSString *streetName;
@property (nonatomic, strong, nullable) NSString *streetNumber;
@property (nonatomic, strong, nullable) NSString *zipCode;

@property (nonatomic, strong, nullable) NSSet <NSString *> *tags;

@property (nonatomic, strong, nullable) NSString *indoorLocationIdentifier;
@property (nonatomic, strong, nullable) NSString *indoorLocationName;

@property (nonatomic, strong, nullable) NSString *eddystoneNamespaceID;
@property (nonatomic, strong, nullable) NSString *eddystoneInstanceID;
@property (nonatomic, strong, nullable) NSString *eddystoneURL;

@property (nonatomic, strong, nullable) NSNumber *motionDetection;
@property (nonatomic, assign) ESTBeaconConditionalBroadcasting conditionalBroadcasting;

@property (nonatomic, strong, nullable) NSNumber *security;
@property (nonatomic, assign) BOOL isSecured __attribute__ ((deprecated(("Starting from SDK 3.7.0 use security property instead"))));

@property (nonatomic, assign) ESTColor color;

- (instancetype)initWithCloudData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
