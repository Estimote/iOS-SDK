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

#import "ESTNearableRule.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTMotionRule` class defines single rule related to motion state of the Estimote nearable device.
 */

@interface ESTMotionRule : ESTNearableRule

@property (nonatomic, assign) BOOL motionState;

+ (instancetype)motionStateEquals:(BOOL)motionState forNearableIdentifier:(NSString *)identifier;
+ (instancetype)motionStateEquals:(BOOL)motionState forNearableType:(ESTNearableType)type;

@end

NS_ASSUME_NONNULL_END
