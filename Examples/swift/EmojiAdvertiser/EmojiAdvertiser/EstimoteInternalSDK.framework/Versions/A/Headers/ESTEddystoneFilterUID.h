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

#import "ESTEddystoneFilter.h"
#import "ESTEddystoneUID.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Eddystone-UID based filter used by `ESTEddystoneManager` in discovery process.
 *  Filter should be initialized with namespaceID and instanceID 
 *  that is matching device(s) should be discovered. Only Namespace ID is required,
 *  Instance ID can be provided optionally for better flexibility.
 */
@interface ESTEddystoneFilterUID : ESTEddystoneFilter

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
- (instancetype)initWithNamespaceID:(NSString *)namespaceID instanceID:(NSString *)instanceID;

@end

NS_ASSUME_NONNULL_END
