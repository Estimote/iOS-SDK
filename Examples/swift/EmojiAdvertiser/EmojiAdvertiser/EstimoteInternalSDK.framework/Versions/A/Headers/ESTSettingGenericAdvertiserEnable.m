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

#import "ESTSettingGenericAdvertiserEnable.h"

#import "ESTError.h"
#import "ESTBeaconOperationProtocol.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTBeaconOperationGenericAdvertiserEnable.h"


@interface ESTSettingGenericAdvertiserEnable ()

@property (nonatomic, strong, readonly) NSNumber *advertiserID;
@property (nonatomic, strong) NSNumber *value;

@end


@implementation ESTSettingGenericAdvertiserEnable

#pragma mark - Initialization

- (instancetype)init
{
    NSAssert(NO, @"You should use initWithValue: or initWithData: methods!");
    
    return nil;
}

- (instancetype)initWithValue:(BOOL)genericAdvertiserEnabled
{
    return [self initWithValue:genericAdvertiserEnabled genericAdvertiserID:ESTGenericAdvertiserID0];
}

- (instancetype)initWithValue:(BOOL)genericAdvertiserEnabled
          genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID
{
    self = [super init];
    
    if (self)
    {
        _value = @(genericAdvertiserEnabled);
        _advertiserID = @(genericAdvertiserID);
    }
    
    return self;
}

- (instancetype)initWithData:(NSData *)data
{
    return [self initWithData:data genericAdvertiserID:ESTGenericAdvertiserID0];
}

- (instancetype)initWithData:(NSData *)data genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID
{
    self = [super init];
    
    if (self)
    {
        _value = [self parseData:data];
        _advertiserID = @(genericAdvertiserID);
    }
    
    return self;
}

- (BOOL)getValue
{
    return self.value.boolValue;
}

#pragma mark - Operations

- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]])
    {
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserEnable readOperationForAdvertiser:self.advertiserID
                                                                                                              completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform read operation of GenericAdvertiserEnabled."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

- (void)writeValue:(BOOL)genericAdvertiserEnabled
        completion:(ESTSettingGenericAdvertiserEnableCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]])
    {
        ESTSettingGenericAdvertiserEnable *setting = [[ESTSettingGenericAdvertiserEnable alloc] initWithValue:genericAdvertiserEnabled];
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserEnable writeOperationForAdvertiser:self.advertiserID
                                                                                                                  setting:setting
                                                                                                               completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform write operation of GenericAdvertiserEnabled."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    ESTSettingGenericAdvertiserEnable *copy = [[ESTSettingGenericAdvertiserEnable alloc] initWithValue:[self getValue]];
    copy.device = self.device;
    
    return copy;
}

#pragma mark - Equality

- (BOOL)isEqual:(id)other
{
    if (other == self)
    {
        return YES;
    }
    
    if (!other || ![[other class] isEqual:[self class]])
    {
        return NO;
    }
    
    return [self isEqualToGenericAdvertiserEnabledSetting:other];
}

- (BOOL)isEqualToGenericAdvertiserEnabledSetting:(ESTSettingGenericAdvertiserEnable *)otherGenericAdvertiserEnabled
{
    if ([self getValue] != [otherGenericAdvertiserEnabled getValue])
    {
        return NO;
    }
    
    return YES;
}

- (NSUInteger)hash
{
    NSUInteger hash = [self.value hash];
    
    return hash;
}

#pragma mark - Private helpers

- (NSNumber *)parseData:(NSData *)data
{
    uint8_t byte;
    [data getBytes:&byte];
    BOOL enabled = byte;
    
    return @(enabled);
}

@end
