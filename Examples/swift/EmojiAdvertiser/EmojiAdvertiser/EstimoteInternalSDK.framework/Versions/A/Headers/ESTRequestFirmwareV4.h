//
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTRequestGetJSON.h"


@interface ESTRequestFirmwareV4 : ESTRequestGetJSON

- (id)init __attribute__((unavailable("Must use initWithPublicID: instead.")));

+ (id)new __attribute__((unavailable("Must use initWithPublicID: instead.")));

- (instancetype)initWithPublicID:(NSString *)publicID;

@end
