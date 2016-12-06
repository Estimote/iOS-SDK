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

/**
 * Class for objects carying data from telemetry packet.
 */
@interface ESTTelemetryInfo : NSObject

/**
 *  Half (8 bytes) of the full device identifier (16 bytes)
 *  represented in hex string.
 */
@property (nonatomic, strong, readonly) NSString *shortIdentifier;

- (instancetype)initWithShortIdentifier:(NSString *)shortIdentifier;

@end
