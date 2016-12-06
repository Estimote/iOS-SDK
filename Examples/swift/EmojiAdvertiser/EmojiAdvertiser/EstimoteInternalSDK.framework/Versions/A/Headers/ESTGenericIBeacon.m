//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import "ESTGenericIBeacon.h"
#import "ECODataParserUtilities.h"
#import <CommonCrypto/CommonDigest.h>

@interface ESTGenericIBeacon ()



@end


@implementation ESTGenericIBeacon

- (instancetype)initWithProximityUUID:(NSUUID *)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                        measuredPower:(int8_t)measuredPower
                           macAddress:(NSData *)macAddress
{
    self = [super init];
    
    if (self)
    {
        _proximityUUID = proximityUUID;
        _major = major;
        _minor = minor;
        _measuredPower = measuredPower;
        _macAddress = macAddress;
    }
    
    return self;
}

- (NSData *)getPayloadData
{
    uuid_t proximityUUIDBytes;
    [self.proximityUUID getUUIDBytes:proximityUUIDBytes];
    NSData *proximityUUIDData = [NSData dataWithBytes:proximityUUIDBytes length:sizeof(proximityUUIDBytes)];

    uint16_t swapedMajor = CFSwapInt16(_major);
    uint16_t swapedMinor = CFSwapInt16(_minor);
    
    NSData *majorData = [NSData dataWithBytes:&swapedMajor length:sizeof(swapedMajor)];
    NSData *minorData = [NSData dataWithBytes:&swapedMinor length:sizeof(swapedMinor)];
    NSData *measuredPowerData = [NSData dataWithBytes:&_measuredPower length:sizeof(_measuredPower)];
    
    NSMutableData *payload = [ECODataParserUtilities bytesFromHexString:@"422400"];
    [payload appendData:_macAddress];
    [payload appendData:[ECODataParserUtilities bytesFromHexString:@"0201061aff4c000215"]];
    [payload appendData:proximityUUIDData];
    [payload appendData:majorData];
    [payload appendData:minorData];
    [payload appendData:measuredPowerData];
    
    return payload;
}

+ (NSData *)randomStaticMacAddressForIdentifier:(NSString *)deviceIdentifier
                                           seed:(int32_t)seed
{
    unsigned char digest[CC_SHA1_DIGEST_LENGTH];
    NSString *combinedIdentifierSeed = [NSString stringWithFormat:@"%@%i", deviceIdentifier, seed];
    NSData *combinedIdentifierSeedData = [combinedIdentifierSeed dataUsingEncoding:NSUTF8StringEncoding];
    
    if (CC_SHA1([combinedIdentifierSeedData bytes], (int)[combinedIdentifierSeedData length], digest))
    {
        // Random static type
        digest[5] |= 0xc0;
        return [NSData dataWithBytes:(const void *)digest length:sizeof(unsigned char) * 6];
    }
    
    return nil;
}

#pragma mark - Debug methods

- (NSString *)description
{
    return [NSString stringWithFormat:@"[ESTGenericIBeacon]"];
}

@end
