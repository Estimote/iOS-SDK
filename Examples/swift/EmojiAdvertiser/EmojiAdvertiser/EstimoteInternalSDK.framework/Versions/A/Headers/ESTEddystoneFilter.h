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
#import "ESTEddystone.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Generic Eddystone based filter used by `ESTEddystoneManager` in discovery process.
 *  Instance of `ESTEddystoneFilter` can be used as a base for other filters.
 */
@interface ESTEddystoneFilter : NSObject

/**
 *  Method allows to check if provided eddystones belong to filter.
 *
 *  @param eddystones Eddystones to validate.
 *
 *  @return Properly validated eddystones.
 */
- (NSArray<ESTEddystone *> *)filterEddystones:(NSArray<ESTEddystone *> *)eddystones;

@end

NS_ASSUME_NONNULL_END
