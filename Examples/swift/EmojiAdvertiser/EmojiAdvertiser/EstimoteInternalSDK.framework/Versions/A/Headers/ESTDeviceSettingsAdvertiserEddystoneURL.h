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
#import "ESTDeviceSettingsAdvertiser.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents settings structure for Eddystone URL advertiser.
 */
@interface ESTDeviceSettingsAdvertiserEddystoneURL : ESTDeviceSettingsAdvertiser

/**
 *  URL address broadcasted in Eddystone URL packet.
 */
@property (nonatomic, strong, readonly) NSString *url;

@end

NS_ASSUME_NONNULL_END
