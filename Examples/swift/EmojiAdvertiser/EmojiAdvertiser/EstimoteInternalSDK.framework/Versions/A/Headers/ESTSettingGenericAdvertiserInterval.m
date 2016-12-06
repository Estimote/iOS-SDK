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

#import "ESTSettingGenericAdvertiserInterval.h"

#import "ESTError.h"
#import "ESTDeviceConnectable.h"
#import "ESTBeaconOperationProtocol.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTBeaconOperationGenericAdvertiserInterval.h"


@interface ESTSettingGenericAdvertiserInterval ()

@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, strong, readonly) NSNumber *advertiserID;

@end


@implementation ESTSettingGenericAdvertiserInterval

#pragma mark - Initialization

- (instancetype)init
{
    NSAssert(NO, @"You should use initWithValue: or initWithData: methods!");
    
    return nil;
}

- (instancetype)initWithValue:(unsigned short)genericAdvertiserInterval
{
    self = [super init];
    
    if (self)
    {
        if ([[self class] validationErrorForValue:genericAdvertiserInterval])
        {
            return nil;
        }
        
        _value = @(genericAdvertiserInterval);
    }
    
    return self;
}

- (instancetype)initWithValue:(unsigned short)genericAdvertiserInterval
                 advertiserID:(ESTGenericAdvertiserID)advertiserID
{
    self = [super init];
    
    if (self)
    {
        if ([[self class] validationErrorForValue:genericAdvertiserInterval])
        {
            return nil;
        }
        
        _value = @(genericAdvertiserInterval);
        _advertiserID = @(advertiserID);
    }
    
    return self;
}

- (instancetype)initWithData:(NSData *)data
         genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID
{
    self = [super init];
    
    if (self)
    {
        _advertiserID = @(genericAdvertiserID);
        _value = [self parseData:data];
    }
    
    return self;
}

- (instancetype)initWithData:(NSData *)data
{
    self = [super init];
    
    if (self)
    {
        _value = [self parseData:data];
    }
    
    return self;
}

- (unsigned short)getValue
{
    return self.value.unsignedShortValue;
}

#pragma mark - Operations

- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]] && self.advertiserID)
    {
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserInterval readOperationForAdvertiser:self.advertiserID.integerValue completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform read operation of GenericAdvertiserInterval."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

- (void)writeValue:(NSTimeInterval)genericAdvertiserInterval completion:(ESTSettingGenericAdvertiserIntervalCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]] && self.advertiserID)
    {
        ESTSettingGenericAdvertiserInterval *setting = [[ESTSettingGenericAdvertiserInterval alloc] initWithValue:genericAdvertiserInterval];
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserInterval writeOperationForAdvertiser:self.advertiserID.integerValue setting:setting completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform write operation of GenericAdvertiserInterval."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

+ (NSError *)validationErrorForValue:(unsigned short)interval
{
    NSInteger min = 100;
    NSInteger max = 10000;
    
    if (interval < min)
    {
        return [ESTError errorWithDomain:ESTSettingGenericAdvertiserIntervalErrorDomain
                                    code:ESTSettingGenericAdvertiserIntervalErrorValueTooSmall
                             description:@"Provided value is out of allowed bounds."
                                recovery:[NSString stringWithFormat:@"Use advertising interval value between %@ and %@.", @(min), @(max)]
                                  reason:[NSString stringWithFormat:@"%@ is less than %@.", @(interval), @(min)]];
    }
    
    if (interval > max)
    {
        return [ESTError errorWithDomain:ESTSettingGenericAdvertiserIntervalErrorDomain
                                    code:ESTSettingGenericAdvertiserIntervalErrorValueTooBig
                             description:@"Provided value is out of allowed bounds."
                                recovery:[NSString stringWithFormat:@"Use advertising interval value between %@ and %@.", @(min), @(max)]
                                  reason:[NSString stringWithFormat:@"%@ is greater than %@.", @(interval), @(max)]];
    }
    
    return nil;
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    ESTSettingGenericAdvertiserInterval *copy = [[ESTSettingGenericAdvertiserInterval alloc] initWithValue:[self getValue]];
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
    
    return [self isEqualToGenericAdvertiserIntervalSetting:other];
}

- (BOOL)isEqualToGenericAdvertiserIntervalSetting:(ESTSettingGenericAdvertiserInterval *)otherGenericAdvertiserInterval
{
    if ([self getValue] != [otherGenericAdvertiserInterval getValue])
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
    unsigned short interval;
    [data getBytes:&interval length:sizeof(interval)];
    
    return @(interval);
}

@end
