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

#import "ESTSettingGenericAdvertiserData.h"

#import "ESTError.h"
#import "ESTDeviceConnectable.h"
#import "ECODataParserUtilities.h"
#import "ESTBeaconOperationProtocol.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTBeaconOperationGenericAdvertiserData.h"


@interface ESTSettingGenericAdvertiserData ()

@property (nonatomic, strong) NSData *value;
@property (nonatomic, strong, readonly) NSNumber *advertiserID;

@end


@implementation ESTSettingGenericAdvertiserData

#pragma mark - Initialization

- (instancetype)init
{
    NSAssert(NO, @"You should use initWithValue: or initWithData: methods!");
    
    return nil;
}

- (instancetype)initWithValue:(NSData *)genericAdvertiserData
{
    self = [super init];
    
    if (self)
    {
        if ([[self class] validationErrorForValue:genericAdvertiserData])
        {
            return nil;
        }

        _value = genericAdvertiserData;
    }
    
    return self;
}

- (instancetype)initWithValue:(NSData *)genericAdvertiserData
                 advertiserID:(ESTGenericAdvertiserID)advertiserID
{
    self = [super init];
    
    if (self)
    {
        if ([[self class] validationErrorForValue:genericAdvertiserData])
        {
            return nil;
        }
        _advertiserID = @(advertiserID);
        _value = genericAdvertiserData;
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

- (NSData *)getValue
{
    return [self.value copy];
}

#pragma mark - Operations

- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserDataCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]] && self.advertiserID)
    {
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserData readOperationForAdvertiser:self.advertiserID
                                                                                                            completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform read operation of GenericAdvertiserData."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

- (void)writeValue:(NSData *)genericAdvertiserData completion:(ESTSettingGenericAdvertiserDataCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]] && self.advertiserID)
    {
        ESTSettingGenericAdvertiserData *setting = [[ESTSettingGenericAdvertiserData alloc] initWithValue:genericAdvertiserData];
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserData writeOperationForAdvertiser:self.advertiserID
                                                                                                                setting:setting
                                                                                                             completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform write operation of GenericAdvertiserData."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

+ (NSError *)validationErrorForValue:(NSData *)genericAdvertiserData
{
    if (!genericAdvertiserData)
    {
        return [ESTError errorWithDomain:ESTSettingGenericAdvertiserDataErrorDomain
                                    code:ESTSettingGenericAdvertiserDataErrorCanNotBeNil
                             description:@"Provided data can not be nil."
                                recovery:@"Provide non nil value."
                                  reason:nil];
    }
    
    return nil;
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    ESTSettingGenericAdvertiserData *copy = [[ESTSettingGenericAdvertiserData alloc] initWithValue:[self getValue]];
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
    
    return [self isEqualToGenericAdvertiserDataSetting:other];
}

- (BOOL)isEqualToGenericAdvertiserDataSetting:(ESTSettingGenericAdvertiserData *)otherGenericAdvertiserData
{
    if (![[self getValue] isEqualToData:[otherGenericAdvertiserData getValue]])
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

- (NSData *)parseData:(NSData *)data
{
    return data;
}

@end
