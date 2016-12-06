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
#import "ESTRequestGetJSON.h"
#import "ESTBeaconVO.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestGetBeaconsErrorDomain @"ESTRequestGetBeaconsErrorDomain"

/**
 *  Errors occurring for request.
 */
typedef NS_ENUM(NSInteger, ESTRequestGetBeaconsError)
{
    /**
     *  Unknown request error.
     */
    ESTRequestGetBeaconsErrorUnknown
};

typedef void(^ESTRequestGetBeaconsBlock)(NSArray<ESTBeaconVO *> * _Nullable beaconVOs, NSError * _Nullable error);

/**
 *  ESTRequestGetBeacons is used to fetch list of all beacons 
 *  that belongs to currently authorised user. All details are provided
 *  including beacon's settings.
 */

@interface ESTRequestGetBeacons : ESTRequestGetJSON

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (NSArray containing ESTBeaconVO objects).
 */
- (void)sendRequestWithCompletion:(ESTRequestGetBeaconsBlock)completion;

@end

NS_ASSUME_NONNULL_END
