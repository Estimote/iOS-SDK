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

#define PRODUCTION_CLOUD_DOMAIN_URL @"https://cloud.estimote.com"
#define STAGING_CLOUD_DOMAIN_URL @"https://cloud-staging.estimote.com"

#define PRODUCTION_SANTA_CRUZ_DOMAIN_URL @"https://order.estimote.com"
#define STAGING_SANTA_CRUZ_DOMAIN_URL @"https://estimote-preorder-staging.herokuapp.com"

@interface ESTRequestConst : NSObject

+ (NSString *)AppToken;
+ (void)setAppToken:(NSString *)key;

+ (NSString *)AppID;
+ (void)setAppID:(NSString *)aid;

+ (NSString *)cloudDomainURL;
+ (void)setCloudDomainURL:(NSString *)cloudDomainURL;

+ (NSString *)santaCruzDomainURL;
+ (void)setSantaCruzDomainURL:(NSString *)santaCruzDomainURL;

+ (NSString *)createCloudURLWithSuffix:(NSString *)suffix;
+ (NSString *)createSantaCruzURLWithSuffix:(NSString *)suffix;

@end
