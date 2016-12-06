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

#define ESTIMOTE_EDDYSTONE_NAMESPACE_ID @"EDD1EBEAC04E5DEFA017"

/**
 * ESTEddystoneUID represents Eddystone UID packet coming from `ESTEddystoneManager` class.
 */
@interface ESTEddystoneUID : ESTEddystone

/**
 *  Namespace ID required for device identification.
 *  Value usually defined on the company level.
 */
@property (nonatomic, strong, readonly) NSString * _Nullable namespaceID;

/**
 *  Instance ID required for device identification.
 *  Value defined per device.
 */
@property (nonatomic, strong, readonly) NSString * _Nullable instanceID;

/**
 * Initialize Eddystone UUID object instance with Namespace ID only.
 *
 * @param namespaceID Eddystone Namespace ID.
 */
- (instancetype)initWithNamespaceID:(NSString *)namespaceID;

/**
 * Initialize Eddystone UUID object instance with Namespace ID and Instance ID.
 *
 * @param namespaceID Eddystone Namespace ID.
 * @param instanceID Eddystone Instance ID.
 */
- (instancetype)initWithNamespaceID:(NSString *)namespaceID
                         instanceID:(nullable NSString *)instanceID;

@end

NS_ASSUME_NONNULL_END
