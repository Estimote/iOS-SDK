//
//  ESTRequestNearableDetails.h
//  EstimoteSDK
//
//  Created by Estimote Polska on 8/20/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESTRequestGetJSON.h"


@interface ESTRequestNearableDetails : ESTRequestGetJSON

@property (nonatomic, strong, readonly) NSString *nearableUID; // mac or proximityUUID:major:minor

- (instancetype)initWithNearableUID:(NSString *)nearableUID;

@end
