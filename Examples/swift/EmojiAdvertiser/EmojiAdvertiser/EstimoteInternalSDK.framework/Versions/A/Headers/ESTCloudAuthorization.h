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


@interface ESTCloudAuthorization : NSObject

+ (void)setupDefaultAuthorizationForRequest:(NSMutableURLRequest *)request;

+ (void)setupCloudAuthorizationForRequest:(NSMutableURLRequest *)request;

+ (void)setupSantaCruzAuthorizationForRequest:(NSMutableURLRequest *)request;

+ (void)setupAuthorizationWithMail:(NSString *)mail
                       andPassword:(NSString *)pass
                        forRequest:(NSMutableURLRequest *)request;

+ (NSString *)generateUserAgent;

@end
