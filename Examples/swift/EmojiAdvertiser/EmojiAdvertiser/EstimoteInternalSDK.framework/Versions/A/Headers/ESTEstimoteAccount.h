// Copyright (c) 2015 Estimote. All rights reserved.


/** Same as `ESTConfig` but for handling Estimote Account (logging in via login/password). */

#import <Foundation/Foundation.h>


@interface ESTEstimoteAccount : NSObject

/** Returns YES if user is logged in to Estimote Cloud */
+ (BOOL)isLoggedIn;

/** Returns YES if superuser in to Estimote Cloud. */
+ (BOOL)isSuperUser;

/** Sets whenever current user is super user. */
+ (void)setSuperUser:(BOOL)isSuperUser;

/** Returns email address of current user. */
+ (NSString *)userEmail;

/** Sets email address for current user. */
+ (void)setUserEmail:(NSString *)email;

/** Returns name of current user. */
+ (NSString *)userName;

/** Sets name for current user. */
+ (void)setUserName:(NSString *)name;

/** Returns ID of current user. */
+ (NSString *)userID;

/** Sets ID for current user. */
+ (void)setUserID:(NSString *)ID;

/** Cleans all user credentials (email, auth cookie, is super user flag). */
+ (void)cleanCredentials;

/** Persists cookie from NSHTTPCookieStorage to storage. */
+ (void)cacheCookie;

/** Sets cookie from storage to NSHTTPCookieStorage so it can be used in NSURLRequests. */
+ (void)refreshCookieFromCache;

/** Provides unique identifier per app instalation */
+ (NSString *)identifier;

@end
