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

#import "ESTDefinitions.h"
#import "ESTNearableDefinitions.h"
#import "ESTBeaconDefinitions.h"


@interface ESTCloudMapper : NSObject

+ (ESTColor)colorForCloudName:(NSString *)cloudName;

+ (NSString *)cloudNameForColor:(ESTColor)color;

+ (ESTNearableType)nearableTypeForCloudName:(NSString *)cloudName;

+ (NSString *)cloudNameForNearableType:(ESTNearableType)nearableType;

+ (NSString *)cloudNameForBroadcastingType:(ESTBeaconConditionalBroadcasting)type;

+ (NSString *)cloudNameForBroadcastingScheme:(ESTBroadcastingScheme)scheme;

+ (ESTBroadcastingScheme)broadcastingSchemeForCloudName:(NSString *)name;

+ (ESTBeaconConditionalBroadcasting)broadcastingTypeForCloudName:(NSString *)name;

+ (NSDate *)dateForCloudDate:(NSString *)cloudDate;

+ (ESTNearableBroadcastingScheme)nearableBroadcastingSchemeForName:(NSString *)scheme;

+ (NSString *)nameForNearableBroadcastingScheme:(ESTNearableBroadcastingScheme)scheme;

@end
