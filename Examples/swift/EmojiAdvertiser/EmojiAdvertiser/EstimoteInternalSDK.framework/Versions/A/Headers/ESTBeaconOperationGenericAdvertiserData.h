//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingGenericAdvertiserData.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationGenericAdvertiserData allows to create read/write operations for GenericAdvertiser GenericAdvertiserData setting of a device.
 */
@interface ESTBeaconOperationGenericAdvertiserData : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for GenericAdvertiser GenericAdvertiserData setting.
 *
 *  @param advertiserID Advertiser ID.
 *  @param completion   Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                completion:(ESTSettingGenericAdvertiserDataCompletionBlock)completion;

/**
 *  Method allows to create write operation for GenericAdvertiser GenericAdvertiserData setting.
 *
 *  @param advertiserID Advertiser ID.
 *  @param setting      Setting to be written to a device.
 *  @param completion   Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)writeOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                    setting:(ESTSettingGenericAdvertiserData *)setting
                                 completion:(ESTSettingGenericAdvertiserDataCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
