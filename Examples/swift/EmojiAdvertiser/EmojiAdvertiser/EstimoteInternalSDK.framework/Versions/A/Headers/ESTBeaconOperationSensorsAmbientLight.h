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

#import <Foundation/Foundation.h>
#import "ESTBeaconOperationProtocol.h"
#import "ESTSettingOperation.h"
#import "ESTSettingSensorsAmbientLight.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationSensorsAmbientLight allows to create read operations for Sensors AmbientLight setting of a device.
 */
@interface ESTBeaconOperationSensorsAmbientLight : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Sensors AmbientLight setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingSensorsAmbientLightCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
