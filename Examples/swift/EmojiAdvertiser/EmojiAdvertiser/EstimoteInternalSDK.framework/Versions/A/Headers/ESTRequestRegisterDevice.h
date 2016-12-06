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

#import "ESTRequestPostJSON.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ESTRequestRegisterDeviceBlock)(NSError * _Nullable error);

/**
 *  Request allows to register device in Estimote Cloud. After registration device can remotely receive information
 *  about pending settings.
 */

@interface ESTRequestRegisterDevice : ESTRequestPostJSON

@property (nonatomic, strong, readonly) NSData *deviceToken;

/**
 *  Initialise request with Device Token.
 *
 *  @param deviceToken Device token delivered in application:didRegisterForRemoteNotificationsWithDeviceToken: method of App Delegate.
 *
 *  @return Instance of request.
 */
- (instancetype)initWithDeviceToken:(NSData *)deviceToken;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (NSError object optional).
 */
- (void)sendRequestWithCompletion:(ESTRequestRegisterDeviceBlock)completion;

@end

NS_ASSUME_NONNULL_END
