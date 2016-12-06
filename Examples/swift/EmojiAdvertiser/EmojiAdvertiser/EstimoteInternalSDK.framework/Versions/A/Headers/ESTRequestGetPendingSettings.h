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

#import "ESTRequestGetJSON.h"
#import "ESTBeaconUpdateInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ESTRequestGetPendingSettingsBlock)(NSArray<ESTBeaconUpdateInfo *> * _Nullable beaconUpdateInfos, NSError * _Nullable error);

/**
 *  This request is fetching all the pending settings from the Estimote Cloud for authorized user.
 */

@interface ESTRequestGetPendingSettings : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (NSArray containing ESTBeaconUpdateInfo objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetPendingSettingsBlock)completion;

@end

NS_ASSUME_NONNULL_END
