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
#import "ESTDeviceSettingProtocol.h"
#import "ESTSettingBase.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTDeviceSettingsCollection represents collection of device settings.
 */
@interface ESTDeviceSettingsCollection : NSObject <NSCopying>

/**
 *  Method allows to initialize object with array of settings.
 *
 *  @param settingsArray    Array of settings.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithSettingsArray:(NSArray<ESTSettingBase *> *)settingsArray;

/**
 *  Method allows to set device setting represented by object implementing 
 *  `ESTSettingProtocol` protocol. When setting was already set, it will be
 *  updated with value from provided one.
 *
 *  @param setting Setting should be set.
 */
- (void)addOrReplaceSetting:(ESTSettingBase *)setting;

/**
 *  Method allows to set device settings represented by objects implementing
 *  `ESTSettingProtocol` protocol. When a setting was already set, it will be
 *  updated with value from provided one.
 *
 *  Batch version of -addOrReplaceSetting method.
 *
 *  @param setting Setting should be set.
 */
- (void)addOrReplaceSettings:(NSArray<ESTSettingBase *> *)settings;

/**
 *  Method allows to get Setting represented by particular class.
 *
 *  @param targetedClass Class of setting that should be get.
 *
 *  @return Setting for class. Nil means no setting was set for this class.
 */
- (id)getSettingForClass:(Class)targetedClass;

/**
 *  Methods allows to get all settings that was set in NSArray representation.
 *
 *  @return Array of all set settings.
 */
- (NSArray *)getSettings;

@end

NS_ASSUME_NONNULL_END
