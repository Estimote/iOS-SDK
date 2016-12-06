//
//  ESTNearable+Internal.h
//  EstimoteSDK
//
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTNearable.h"
#import "ESTStabilizedZone.h"


@interface ESTNearable (Internal)

#define RSSI_INVALID 127

@property (nonatomic, strong) NSDate *timestamp;
@property (nonatomic, strong) ESTStabilizedZone *stabilizedZone;

- (id)initWithIdentifier:(NSString *)identifier;
- (id)initWithCloudData:(NSDictionary *)data;

- (void)_intUpdateWithPacket:(NSDictionary *)packet;
- (void)_intUpdateType:(ESTNearableType)type;
- (void)_intUpdateColor:(ESTColor)color;
- (void)_intUpdateRSSI:(NSInteger)rssi;
- (BOOL)isWorkingProperly;

- (NSDictionary *)jsonDictionary;

@end
