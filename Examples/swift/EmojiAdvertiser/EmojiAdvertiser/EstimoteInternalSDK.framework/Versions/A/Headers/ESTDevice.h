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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESTDevice : NSObject

@property (nonatomic, strong, readonly) NSString * macAddress __attribute ((deprecated(("Starting from SDK 3.7.0 use identifier instead of macAddress."))));
@property (nonatomic, strong, readonly) NSString *identifier;
@property (nonatomic, strong, readonly) NSUUID *peripheralIdentifier;
@property (nonatomic, assign, readonly) NSInteger rssi;
@property (nonatomic, strong, readonly) NSDate *discoveryDate;

/**
 *  Method allows to initialize object.
 *
 *  @param identifier           device identifier
 *  @param peripheralIdentifier CBPeripheral object's identifier
 *  @param rssi                 CBPeripheral object's RSSI
 *  @param discoveryDate        date of discovery
 *
 *  @return Initialized object.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)identifier
                    peripheralIdentifier:(NSUUID *)peripheralIdentifier
                                    rssi:(NSInteger)rssi
                           discoveryDate:(NSDate *)discoveryDate;

@end

NS_ASSUME_NONNULL_END
