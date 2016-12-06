//
//  ESTNearableScanner.h
//  EstimoteSDK
//
//  Created by Grzegorz Krukiewicz-Gacek on 21.11.2014.
//  Copyright (c) 2014 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ESTNearableScanner;
@class ESTNearable;

@protocol ESTNearableScannerDelegate <NSObject>

@optional
- (void)scanner:(ESTNearableScanner *)scanner didFindNearable:(ESTNearable *)nearable;
- (void)scanner:(ESTNearableScanner *)scanner didFailWithError:(NSError *)error;

@end


@interface ESTNearableScanner : NSObject

@property (nonatomic, assign) NSTimeInterval nearableTimeout;
@property (nonatomic, assign) NSTimeInterval unknownZoneTimeout;

+ (ESTNearableScanner *)sharedInstance;

- (void)startScanForDelegate:(id)object;
- (void)stopScanForDelegate:(id)object;

- (NSDictionary *)allNearables;

@end
