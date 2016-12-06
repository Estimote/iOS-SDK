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

@interface ESTFirmwareInfoVO : NSObject

@property (nonatomic, strong) NSString * _Nullable hardwareVersion;
@property (nonatomic, strong) NSString * _Nullable firmwareVersion;
@property (nonatomic, strong) NSString * _Nullable changelog;
@property (nonatomic, assign) BOOL isUpdateAvailable;

@end

NS_ASSUME_NONNULL_END
