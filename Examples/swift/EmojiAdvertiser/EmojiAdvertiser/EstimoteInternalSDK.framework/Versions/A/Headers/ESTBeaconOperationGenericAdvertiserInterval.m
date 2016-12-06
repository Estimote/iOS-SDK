//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import "ESTBeaconOperationGenericAdvertiserInterval.h"


@interface ESTBeaconOperationGenericAdvertiserInterval ()

@property (nonatomic, copy) ESTSettingGenericAdvertiserIntervalCompletionBlock completion;
@property (nonatomic, strong) ESTSettingGenericAdvertiserInterval *setting;
@property (nonatomic, strong) NSNumber *advertiserID;

@end


@implementation ESTBeaconOperationGenericAdvertiserInterval

+ (instancetype)readOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion
{
    return [[ESTBeaconOperationGenericAdvertiserInterval alloc] initWithAdvertiserID:advertiserID
                                                                          completion:completion];
}

+ (instancetype)writeOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                    setting:(ESTSettingGenericAdvertiserInterval *)setting
                                 completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion
{
    return [[ESTBeaconOperationGenericAdvertiserInterval alloc] initWithAdvertiserID:advertiserID
                                                                               value:[setting copy]
                                                                          completion:completion];
}

- (instancetype)initWithAdvertiserID:(ESTGenericAdvertiserID)advertiserID
                          completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion
{
    self = [super initWithType:ESTSettingOperationTypeRead];
    
    if (self)
    {
        _advertiserID = @(advertiserID);
        _completion = completion;
    }
    
    return self;
}

- (instancetype)initWithAdvertiserID:(ESTGenericAdvertiserID)advertiserID
                               value:(ESTSettingGenericAdvertiserInterval *)setting
                          completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion
{
    self = [super initWithType:ESTSettingOperationTypeWrite];
    
    if (self)
    {
        _advertiserID = @(advertiserID);
        _setting = setting;
        _completion = completion;
    }
    
    return self;
}

- (uint16_t)registerID
{
    if (self.advertiserID)
    {
        switch (self.advertiserID.integerValue)
        {
            case ESTGenericAdvertiserID0:
                return 0x0102;
                
            case ESTGenericAdvertiserID1:
                return 0x0202;
                
            case ESTGenericAdvertiserID2:
                return 0x0302;
        }
    }
    
    return 0xFFFF;
}


- (NSData *)valueData
{
    unsigned short newInterval = [self.setting getValue];
    
    return [NSData dataWithBytes:&newInterval length:sizeof(newInterval)];
}

- (id)valueCloud
{
    return nil;
}

- (ESTSettingBase *)getSetting
{
    return [self.setting copy];
}

- (NSString *)supportedFirmwareVersion
{
    return @"4.3.0";
}

- (BOOL)shouldSynchronize
{
    return NO;
}

- (void)updateSettingWithData:(NSData *)data
{
    self.setting = [[ESTSettingGenericAdvertiserInterval alloc] initWithData:data genericAdvertiserID:self.advertiserID.integerValue];
}

- (void)fireSuccessBlockWithData:(NSData *)data
{
    dispatch_async(dispatch_get_main_queue(), ^{
        if (self.completion)
            self.completion(self.setting, nil);
    });
}

- (void)fireFailureBlockWithError:(NSError *)error
{
    dispatch_async(dispatch_get_main_queue(), ^{
        if (self.completion)
            self.completion(nil, error);
    });
}

@end
