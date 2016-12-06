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
#import "ESTEddystoneFilter.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Eddystone-EID based filter used by `ESTEddystoneManager` in discovery process.
 */
@interface ESTEddystoneFilterEID : ESTEddystoneFilter

/**
 * Initialize Eddystone EID filter object.
 */
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
