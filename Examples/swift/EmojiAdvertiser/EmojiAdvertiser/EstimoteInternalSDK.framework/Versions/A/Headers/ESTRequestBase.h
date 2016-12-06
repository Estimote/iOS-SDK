//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ESTRequestBaseErrorDomain @"ESTRequestBaseErrorDomain"

/**
 *  Describes possible errors that can occur during sending request.
 */
typedef NS_ENUM(NSInteger, ESTRequestBaseError)
{
    /**
     * Error was encountered during the connection attempt.
     */
    ESTRequestBaseErrorConnectionFail = -1,
    /**
     * No data was returned as a response or it couldn't be parsed as JSON.
     */
    ESTRequestBaseErrorNoData = -2,
    /**
     * The server cannot or will not process the request due to an apparent client error.
     */
    ESTRequestBaseErrorBadRequest = 400,
    /**
     * The server is refusing to respond to the request, authorization is required for the resource.
     */
    ESTRequestBaseErrorUnauthorized = 401,
    /**
     * The server is refusing to respond to the request, the user does not have the necessary permissions for the resource.
     */
    ESTRequestBaseErrorForbidden = 403,
    /**
     * The requested resource could not be found.
     */
    ESTRequestBaseErrorNotFound = 404,
    /**
     * Estimote Cloud failed to properly handle the request.
     */
    ESTRequestBaseErrorInternalServerError = 500,
};

typedef void(^ESTRequestBlock)(id _Nullable result, NSError * _Nullable error);


@class ESTRequestBase;


@protocol ESTRequestBaseDelegate <NSObject>

- (void)request:(ESTRequestBase *)request didFinishLoadingWithResposne:(nullable id)response;

- (void)request:(ESTRequestBase *)request didFailLoadingWithError:(NSError *)error;

@end


@interface ESTRequestBase : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate>

@property (nonatomic, weak) id<ESTRequestBaseDelegate> _Nullable delegate;

@property (nonatomic, assign) NSInteger code;
@property (nonatomic, strong) NSURLConnection * _Nullable connection;
@property (nonatomic, strong) NSMutableData * _Nullable receivedData;

- (NSMutableURLRequest *)createRequestWithUrl:(NSString *)url;

- (void)fireRequest:(NSMutableURLRequest *)request;
- (void)parseRespondedData:(nullable id)data;
- (void)parseError:(NSError *)error;
- (void)parseErrorWithCode:(ESTRequestBaseError)errorCode
                    reason:(nullable NSString *)reason;

- (void)sendRequest;
- (void)sendRequestWithCompletion:(ESTRequestBlock)completion;
- (void)cancelRequest;

#pragma mark - Helper methods

- (id _Nullable)objectForKey:(NSString *)aKey inDictionary:(NSDictionary * _Nullable)dict;

#pragma mark - Equality

- (BOOL)isEqualToRequest:(ESTRequestBase *)request;

@end

NS_ASSUME_NONNULL_END
