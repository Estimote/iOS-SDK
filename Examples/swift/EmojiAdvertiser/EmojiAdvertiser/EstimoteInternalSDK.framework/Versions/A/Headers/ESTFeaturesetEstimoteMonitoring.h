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

#import <Foundation/Foundation.h>
#import "ESTDeviceLocationBeacon.h"


NS_ASSUME_NONNULL_BEGIN

/**
 *  ESTFeaturesetEstimoteMonitoring encapsulates operations required for Estimote Monitoring's functionality.
 *  The algorithm relies on Estimote Location being advertised, and this helper tool ensures that 
 *  the settings are set properly.
 *
 *  It doesn't modify settings of packets other than Estimote Location.
 */
@interface ESTFeaturesetEstimoteMonitoring : NSObject

/**
 *  Designated initializer.
 *
 *  @param device Next Gen device the settings are to be applied to.
 */
- (instancetype)initWithDevice:(ESTDeviceLocationBeacon *)device;

/**
 *  Perform read operations for settings related to Estimote Monitoring, decide whether they satisfy
 *  prerequisites for Estimote Monitoring and call <code>completion</code> when all are done.
 *
 *  @param completion Completion block invoked after all operations are done (either successfully or not).
 *
 *  @discussion
 *  If all underlying operations succeed, <code>completion</code>'s <code>featuresetEnabled</code> tells 
 *  whether Estimote Monitoring prerequisites are met, <code>errors</code> is nil.
 *
 *  If any of underlying operation fails, <code>completion</code>'s <code>featuresetEnabled</code> 
 *  is set to <code>NO</code>, and <code>errors</code> array errors resulting from failed operations.
 */
- (void)readSettingsWithCompletion:(void (^)(BOOL featuresetEnabled, NSArray<NSError*> * _Nullable errors))completion;

/**
 *  Write Estimote Monitoring values for settings related to EM algorithms.
 *  Call <code>completion</code> when all setting operations are done.
 *
 *  @param completion Completion block invoked after all operations are done (either successfully or not).
 *
 *  @discussion
 *  If all underlying operations succeed, <code>completion</code>'s <code>errors</code> is nil.
 *
 *  If any of underlying operation fails, <code>completion</code>'s <code>errors</code> array
 *  contains errors resulting from failed operations.
 */
- (void)writeEnableSettings:(BOOL)enabled withCompletion:(void (^)(NSArray<NSError*> * _Nullable errors))completion;

@end

NS_ASSUME_NONNULL_END
