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

#import "ESTRequestDelete.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ESTRequestCancelPendingSettingsBlock)(NSError * _Nullable error);

/**
 *  This request is deleting the device's pending settings from the Estimote Cloud for authorized user.
 */

@interface ESTRequestCancelPendingSettings : ESTRequestDelete

@property (nonatomic, readonly) NSString *macAddress;

/**
 *  Initialise request with MAC address.
 *
 *  @param macAddress MAC address of device provided as NSString
 *
 *  @return instance of request
 */
- (instancetype)initWithMacAddress:(NSString *)macAddress;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with optional NSError object.
 */
- (void)sendRequestWithCompletion:(ESTRequestCancelPendingSettingsBlock)completion;

@end

NS_ASSUME_NONNULL_END
