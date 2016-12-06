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

//  Config object for |ESBulkUpdater|. It describes what needs to be updated
//  in each beacon. If the value is nil, that beacon's property won't be changed.

#import <Foundation/Foundation.h>
#import "ESTBeaconDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Object of this class contains all settings that should be applied to the Estimote beacon device. 
 *  It's used by `ESTBulkUpdater` class as a part of `ESTBeaconUpdateInfo` object.
 */

@interface ESTBeaconUpdateConfig : NSObject <NSCoding, NSCopying>

/**
 *  To what proximity UUID beacon should be changed.
 */
@property (nonatomic, strong) NSString * _Nullable proximityUUID;

/**
 *  To what major beacon should be changed.
 */
@property (nonatomic, strong) NSNumber * _Nullable major;

/**
 *  To what minor beacon should be changed.
 */
@property (nonatomic, strong) NSNumber * _Nullable minor;

/**
 *  To what advertising interval beacon should be changed.
 */
@property (nonatomic, strong) NSNumber * _Nullable advInterval;

/**
 *  To what broadcasting power beacon should be changed.
 */
@property (nonatomic, strong) NSNumber * _Nullable power;

/**
 *  Flag for switching state of basic power mode.
 *  Recommended use: [NSNumber numberWithInt:ESTBeaconPowerSavingMode].
 */
@property (nonatomic, strong) NSNumber * _Nullable basicPowerMode;

/**
 *  Flag for switching state of smart power mode.
 *  Recommended use: [NSNumber numberWithInt:ESTBeaconPowerSavingMode].
 */
@property (nonatomic, strong) NSNumber * _Nullable smartPowerMode;

/**
 *  Flag for switching state of Estimote Secure UUID.
 *  Recommended use: [NSNumber numberWithInt:ESTBeaconPowerSavingMode].
 */
@property (nonatomic, strong) NSNumber * _Nullable estimoteSecureUUIDState;

/**
 *  Flag for switching conditional broadcasting mode.
 */
@property (nonatomic, strong) NSNumber * _Nullable conditionalBroadcasting;

@end

NS_ASSUME_NONNULL_END
