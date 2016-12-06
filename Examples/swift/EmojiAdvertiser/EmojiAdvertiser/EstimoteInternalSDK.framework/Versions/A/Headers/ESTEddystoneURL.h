//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTEddystone.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTEddystoneURL represents Eddystone URL packet coming from `ESTEddystoneManager` class.
 */
@interface ESTEddystoneURL : ESTEddystone

/**
 *  URL address advertised by the beacon device
 *  packet type is set to ESTBeaconPacketTypeEddystoneURL
 */
@property (nonatomic, strong, readonly) NSString * _Nullable url;

/**
 *  Initialized ESTEddystoneURL object with url.
 *
 *  @param url URL broadcasted by the device.
 */
- (instancetype)initWithURL:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
