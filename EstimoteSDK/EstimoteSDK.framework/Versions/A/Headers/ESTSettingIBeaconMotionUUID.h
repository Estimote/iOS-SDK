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
#import "ESTSettingReadOnly.h"

@class ESTSettingIBeaconMotionUUID;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read setting MotionUUID operation for iBeacon packet.
 *
 *  @param motionUUIDSetting MotionUUID setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingIBeaconMotionUUIDCompletionBlock)(ESTSettingIBeaconMotionUUID * _Nullable motionUUIDSetting, NSError * _Nullable error);


/**
 *  ESTSettingIBeaconMotionUUID represents iBeacon MotionUUID value.
 *  This is the iBeacon Proximity UUID device broadcasts when MotionUUID feature is enabled, and the device is in motion.
 */
@interface ESTSettingIBeaconMotionUUID : ESTSettingReadOnly <NSCopying>

/**
 *  Designated initializer.
 *
 *  @param motionUUID iBeacon MotionUUID value.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithValue:(NSUUID *)motionUUID;

/**
 *  Returns current value of iBeacon MotionUUID setting.
 *
 *  @return iBeacon MotionUUID value.
 */
- (NSUUID *)getValue;

/**
 *  Method allows to read value of initialized iBeacon MotionUUID setting object.
 *
 *  @param completion Block to be invoked when the operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingIBeaconMotionUUIDCompletionBlock)completion;

/**
 *  Method allows to generate Proximity Motion UUID based on regular Proximity UUID.
 *
 *  @param proximityUUID Regular proximity UUID.
 *
 *  @return Generated Motion UUID.
 */
+ (NSUUID *)motionProximityUUIDForProximityUUID:(NSUUID *)proximityUUID;

@end

NS_ASSUME_NONNULL_END
