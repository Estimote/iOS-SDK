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

#import "ESTBeaconOperationGenericAdvertiserEnable.h"


@interface ESTBeaconOperationGenericAdvertiserEnable ()

@property (nonatomic, copy) ESTSettingGenericAdvertiserEnableCompletionBlock completion;
@property (nonatomic, strong) ESTSettingGenericAdvertiserEnable *setting;
@property (nonatomic, strong) NSNumber *advertiserID;

@end


@implementation ESTBeaconOperationGenericAdvertiserEnable

+ (instancetype)readOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion
{
    return [[ESTBeaconOperationGenericAdvertiserEnable alloc] initWithAdvertiserID:advertiserID
                                                                        completion:completion];
}

+ (instancetype)writeOperationForAdvertiser:(ESTGenericAdvertiserID)advertiserID
                                    setting:(ESTSettingGenericAdvertiserEnable *)setting
                                 completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion
{
    return [[ESTBeaconOperationGenericAdvertiserEnable alloc] initWithAdvertiserID:advertiserID
                                                                             value:[setting copy]
                                                                        completion:completion];
}

- (instancetype)initWithAdvertiserID:(ESTGenericAdvertiserID)advertiserID
                          completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion
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
                               value:(ESTSettingGenericAdvertiserEnable *)setting
                          completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion
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
                return 0x0100;

            case ESTGenericAdvertiserID1:
                return 0x0200;
                
            case ESTGenericAdvertiserID2:
                return 0x0300;
        }
    }
    
    return 0xFFFF;
}

- (NSData *)valueData
{
    BOOL enable = [self.setting getValue];
    
    return [NSData dataWithBytes:&enable length:sizeof(enable)];
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
    self.setting = [[ESTSettingGenericAdvertiserEnable alloc] initWithData:data];
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
