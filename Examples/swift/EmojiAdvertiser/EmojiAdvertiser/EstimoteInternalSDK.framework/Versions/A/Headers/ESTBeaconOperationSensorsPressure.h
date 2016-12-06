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
#import "ESTSettingSensorsPressure.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTBeaconOperationSensorsPressure allows to create read operations for Sensors Pressure setting of a device.
 *
 *  Note that the pressure sensor is only available in Location Beacons F3.3 and newer. If you try to perform this operation on a beacon with no pressure sensor, it'll always fail.
 */
@interface ESTBeaconOperationSensorsPressure : ESTSettingOperation <ESTBeaconOperationProtocol>

/**
 *  Method allows to create read operation for Sensors Pressure setting.
 *
 *  @param completion Block invoked when the operation is complete.
 *
 *  @return Initialized object.
 */
+ (instancetype)readOperationWithCompletion:(ESTSettingSensorsPressureCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
