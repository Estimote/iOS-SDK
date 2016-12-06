//
//  ESTBeaconInternalUtilities.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 26.08.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTNearableDefinitions.h"
#import "ESTBeaconDefinitions.h"
#import "ESTNearable.h"
#import "ESTRequestConst.h"


@interface ESTBeaconInternalUtilities : NSObject

/**
 * Request user account creation with provided email.
 *
 * @param emailAddress email address you want to signup with
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)signupWithEmail:(NSString *)emailAddress
            completion:(ESTCompletionBlock)completion;

/**
 * Login into Estimote Cloud to get access to API methods.
 *
 * @param email Estimote Cloud email address of the user
 * @param password Estimote Cloud password
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)loginWithEmail:(NSString *)email
             password:(NSString *)password
           completion:(ESTCompletionBlock)completion;

/**
 * Logout from Estimote Cloud
 *
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)logoutWithCompletion:(ESTCompletionBlock)completion;

/**
 *  Refresh user beacons cache
 *
 *  @param completion completion block
 */
- (void)refreshUserBeaconsCache:(ESTCompletionBlock)completion;

// configuration methods

- (void)registerBeacon:(CLBeacon *)beacon
            macAddress:(NSString *)macAddress
                 color:(ESTColor)color
               orderId:(NSNumber *)orderId
            completion:(ESTCompletionBlock)completion;


- (void)unassignBeaconWithMacAddress:(NSString *)macAddress
                 fromOrderCompletion:(ESTCompletionBlock)completion;


- (void)assignBeacon:(CLBeacon *)beacon
          macAddress:(NSString *)macAddress
               color:(ESTColor)color
                mail:(NSString *)emailAddress
          completion:(ESTCompletionBlock)completion;


- (void)getOwnerOfBeacon:(CLBeacon *)beacon
              completion:(ESTObjectCompletionBlock)completion;

- (void)getOwnerEmailHintOfBeacon:(CLBeacon *)beacon
                       completion:(ESTStringCompletionBlock)completion;

- (void)getOwnerEmailHintOfBeaconWithMacAddress:(NSString *)macAddress
                                     completion:(ESTStringCompletionBlock)completion;

- (void)getOrderInfoOfBeaconWithMacAddress:(NSString *)macAddress
                                completion:(ESTObjectCompletionBlock)completion;


+ (NSTimeInterval)lifetimeForBatteryLevel:(int)batteryLevel
                              batteryType:(ESTBeaconBatteryType)batteryType
                       advertisingInteval:(int)advertisingInterval
                               powerLevel:(int)powerLevel;

- (void)getBatteryLifetimesForBeaconUID:(NSString *)beaconUID
                             completion:(ESTObjectCompletionBlock)completion;

- (void)fetchBeaconSettingsForBulkUpdater:(ESTArrayCompletionBlock)block;

- (void)claimBeaconWithBeaconMac:(NSString *)macAdress andUserEmail:(NSString *)email completion:(ESTBoolCompletionBlock)completion;

- (void)resetPasswordForUser:(NSString *)userEmail completion:(ESTCompletionBlock)completion;

// nearable management tools

- (void)registerNearable:(ESTNearable *)nearable
             withOrderID:(NSNumber *)orderID
                    type:(ESTNearableType)type
                   color:(ESTColor)color
              completion:(ESTCompletionBlock)completion;


- (void)trackNearableRegistration:(NSString *)identifier completion:(ESTCompletionBlock)completion;

@end
