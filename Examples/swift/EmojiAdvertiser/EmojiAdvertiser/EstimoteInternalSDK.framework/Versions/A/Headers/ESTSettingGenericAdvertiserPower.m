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

#import "ESTSettingGenericAdvertiserPower.h"

#import "ESTError.h"
#import "ESTDeviceConnectable.h"
#import "ECODataParserUtilities.h"
#import "ESTBeaconOperationProtocol.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTBeaconOperationGenericAdvertiserPower.h"


@interface ESTSettingGenericAdvertiserPower ()

@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, strong, readonly) NSNumber *advertiserID;

@end


@implementation ESTSettingGenericAdvertiserPower

#pragma mark - Initialization

- (instancetype)init
{
    NSAssert(NO, @"You should use initWithValue: or initWithData: methods!");
    
    return nil;
}

- (instancetype)initWithValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower
{
    self = [super init];
    
    if (self)
    {
        if ([[self class] validationErrorForValue:genericAdvertiserPower])
        {
            return nil;
        }
        
        _value = @(genericAdvertiserPower);
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

- (instancetype)initWithValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower
                 advertiserID:(ESTGenericAdvertiserID)advertiserID
{
    self = [super init];
    
    if (self)
    {
        if ([[self class] validationErrorForValue:genericAdvertiserPower])
        {
            return nil;
        }
        
        _advertiserID = @(advertiserID);
        _value = @(genericAdvertiserPower);
    }
    
    return self;
}

- (instancetype)initWithData:(NSData *)data
         genericAdvertiserID:(ESTGenericAdvertiserID)genericAdvertiserID
{
    self = [super init];
    
    if (self)
    {
        _value = [self parseData:data];
        _advertiserID = @(genericAdvertiserID);
    }
    
    return self;
}

- (ESTGenericAdvertiserPowerLevel)getValue
{
    return self.value.integerValue;
}

#pragma mark - Operations

- (void)readValueWithCompletion:(ESTSettingGenericAdvertiserPowerCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]] && self.advertiserID)
    {
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserPower readOperationForAdvertiser:self.advertiserID.integerValue completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform read operation of GenericAdvertiserPower."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

- (void)writeValue:(ESTGenericAdvertiserPowerLevel)genericAdvertiserPower completion:(ESTSettingGenericAdvertiserPowerCompletionBlock)completion
{
    if ([self.device isKindOfClass:[ESTDeviceLocationBeacon class]] && self.advertiserID)
    {
        ESTSettingGenericAdvertiserPower *setting = [[ESTSettingGenericAdvertiserPower alloc] initWithValue:genericAdvertiserPower];
        id<ESTBeaconOperationProtocol> operation = [ESTBeaconOperationGenericAdvertiserPower writeOperationForAdvertiser:self.advertiserID.integerValue setting:setting completion:completion];
        ESTDeviceLocationBeacon *utility = (ESTDeviceLocationBeacon *)self.device;
        [utility.settings performOperation:operation];
    }
    else
    {
        completion(nil, [ESTError errorWithDomain:ESTSettingBaseErrorDomain
                                             code:ESTSettingBaseErrorDeviceReferenceNotAvailable
                                      description:@"Device is not available to peform write operation of GenericAdvertiserPower."
                                         recovery:@"Use instance of setting that was provided by the device."
                                           reason:nil]);
    }
}

+ (NSError *)validationErrorForValue:(ESTGenericAdvertiserPowerLevel)power
{
    NSArray *allowedPowers =
    @[
      @(ESTGenericAdvertiserPowerLevel1),
      @(ESTGenericAdvertiserPowerLevel1A),
      @(ESTGenericAdvertiserPowerLevel2),
      @(ESTGenericAdvertiserPowerLevel3),
      @(ESTGenericAdvertiserPowerLevel4),
      @(ESTGenericAdvertiserPowerLevel5),
      @(ESTGenericAdvertiserPowerLevel6),
      @(ESTGenericAdvertiserPowerLevel7),
      @(ESTGenericAdvertiserPowerLevel8),
      @(ESTGenericAdvertiserPowerLevel9)
      ];
    
    if (![allowedPowers containsObject:@(power)])
    {
        return [ESTError errorWithDomain:ESTSettingGenericAdvertiserPowerErrorDomain
                                    code:ESTSettingGenericAdvertiserPowerErrorValueNotAllowed
                             description:@"Provided value does not belong to the ESTGenericAdvertiserPowerLevel enum."
                                recovery:@"Use one of the ESTGenericAdvertiserPowerLevel values."
                                  reason:[NSString stringWithFormat:@"%@ doesn't belong to the ESTGenericAdvertiserPowerLevel enum.", @(power)]];
    }
    
    return nil;
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    ESTSettingGenericAdvertiserPower *copy = [[ESTSettingGenericAdvertiserPower alloc] initWithValue:[self getValue]];
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
    
    return [self isEqualToGenericAdvertiserPowerSetting:other];
}

- (BOOL)isEqualToGenericAdvertiserPowerSetting:(ESTSettingGenericAdvertiserPower *)otherGenericAdvertiserPower
{
    if ([self getValue] != [otherGenericAdvertiserPower getValue])
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
    if (!data)
    {
        return nil;
    }
    
    NSString *hexString = [ECODataParserUtilities removeAngleBracketsAndSpacesFromString:data.description];
    unsigned power = [ECODataParserUtilities unsignedFromHex:hexString
                                               withHexOffset:0
                                           withLengthInBytes:1
                                               withDirection:ECOByteDirectionOldYoung];
    
    int intPower = power;
    if (power > 128)
    {
        intPower = power - 256;
    }
    
    return @(intPower);
}

@end
