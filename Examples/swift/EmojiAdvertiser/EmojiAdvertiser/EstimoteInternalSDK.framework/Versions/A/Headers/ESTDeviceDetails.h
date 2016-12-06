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

#import "ESTBaseVO.h"
#import "ESTDefinitions.h"

@class ESTDeviceShadow, ESTDeviceSettings, ESTDeviceStatusReport;

NS_ASSUME_NONNULL_BEGIN


/**
 *  This Value Object represents complete information about particular
 *  beacon or nearable device including status, settings and pending settings.
 */
@interface ESTDeviceDetails : ESTBaseVO

/**
 *  Device identifier.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 *  Type of hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareType;

/**
 *  Revision of hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareRevision;
/**
 *  Footprint of hardware.
 */
@property (nonatomic, strong, readonly) NSString *hardwareFootprint;

/**
 *  Color of the device.
 */
@property (nonatomic, readonly) ESTColor color;

/**
 *  Form-factor of the device.
 */
@property (nonatomic, strong, readonly) NSString *formFactor;

/**
 *  Shadow object representing high level context device belongs to.
 */
@property (nonatomic, strong, readonly) ESTDeviceShadow *shadow;

/**
 *  Object containing all settings of the device.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *settings;

/**
 *  Object containing all pending settings of the device applied from both 
 *  Estimote Cloud and SDK.
 */
@property (nonatomic, strong, readonly) ESTDeviceSettings *pendingSettings;

/**
 *  Object containing all status information like battery level.
 */
@property (nonatomic, strong, readonly) ESTDeviceStatusReport *statusReport;

/**
 *  Method allows to initialize value object with data
 *  coming from Estimote Cloud request ESTRequestV2GetDeviceDetails.
 *
 *  @param dictionary Dictionary containing parsed JSON data coming from cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
