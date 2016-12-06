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
#import "ESTRequestGetJSON.h"
#import "ESTLocationBeaconBulkUpdateConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block fired when request is complete.
 *
 *  @param result   Array of user's devices identifiers, for which Cloud has pending changes.
 *  @param error    Error of request. No error means success.
 */
typedef void(^ESTRequestV2GetDevicesPendingBlock)(NSArray <NSString *> * _Nullable result, NSError * _Nullable error);


/**
 *  ESTRequestV2GetDevicesPending allows to fetch list of devices' identifiers, that have pending changes in Estimote Cloud.
 */
@interface ESTRequestV2GetDevicesPending : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Request completion block. No error means request was successful.
 */
- (void)sendRequestWithCompletion:(ESTRequestV2GetDevicesPendingBlock)completion;

@end

NS_ASSUME_NONNULL_END
