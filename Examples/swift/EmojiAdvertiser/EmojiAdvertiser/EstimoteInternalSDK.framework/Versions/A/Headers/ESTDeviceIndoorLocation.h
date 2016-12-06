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

#import "ESTBaseVO.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents Indoor Location location the device is assigned to.
 */
@interface ESTDeviceIndoorLocation : ESTBaseVO

/**
 *  Indoor Location identifer.
 */
@property (nonatomic, strong, readonly, nonnull) NSString *identifier;

/**
 *  Indoor Location name.
 */
@property (nonatomic, strong, readonly) NSString *name;

@end

@interface ESTDeviceIndoorLocation (Internal)

/**
 *  Cloud parsing initalizer.
 *
 *  @param dictionary Dictionary returned from Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
