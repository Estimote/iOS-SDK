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
#import "ESTSettingBase.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTCloudOperationProtocol has to be implemented by Cloud-only setting operations.
 */
@protocol ESTCloudOperationProtocol <NSObject>

/**
 *  Return ESTSettingBase subclass associated with the operation.
 *
 *  @return Setting class.
 */
- (Class)settingClass;

/**
 *  Replaces operation setting with another one containing value fetched from Cloud.
 *
 *  @param setting New setting object.
 */
- (void)updateSettingWithSetting:(ESTSettingBase *)setting;

@end

NS_ASSUME_NONNULL_END
