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
#import "ESTRequestBase.h"


@protocol ESTRequestManagerDelegate <NSObject>

@optional

- (void)requestManagerDidSendRequest:(ESTRequestBase *)request
                   withResponseData:(id)data
                          withError:(NSError *)error;

- (void)requestManagerDidCancelAllConnections;

@end


@interface ESTRequestManager : NSObject <ESTRequestBaseDelegate>

@property (nonatomic, weak) id<ESTRequestManagerDelegate> delegate;

- (BOOL)addRequest:(ESTRequestBase *)request;
- (void)addRequestArray:(NSArray *)request;
- (void)sendRequests;

- (void)cancelAllRequests;

@end
