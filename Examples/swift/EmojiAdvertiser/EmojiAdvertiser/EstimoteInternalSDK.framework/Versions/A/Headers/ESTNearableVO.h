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
#import "ESTNearable.h"

NS_ASSUME_NONNULL_BEGIN

@interface ESTNearableVO : NSObject <NSCoding>

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, assign) ESTNearableType type;
@property (nonatomic, assign) ESTColor color;
@property (nonatomic, strong) NSString * _Nullable indoorLocationName;
@property (nonatomic, strong) NSString * _Nullable indoorLocationIdentifier;
@property (nonatomic, strong) NSNumber *advInterval;
@property (nonatomic, strong) NSNumber *power;
@property (nonatomic, strong) NSString *hardware;
@property (nonatomic, strong) NSString *firmware;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSNumber *motionOnly;
@property (nonatomic, strong) NSNumber *broadcastingScheme;
@property (nonatomic, strong) NSString *proximityUUID;
@property (nonatomic, strong) NSNumber *major;
@property (nonatomic, strong) NSNumber *minor;
@property (nonatomic, strong) NSString *eddystoneURL;

- (instancetype)initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
