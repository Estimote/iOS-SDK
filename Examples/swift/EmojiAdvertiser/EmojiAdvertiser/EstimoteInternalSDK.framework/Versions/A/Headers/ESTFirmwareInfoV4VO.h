//
//  EstimoteSDK
//
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESTFirmwareInfoV4VO : NSObject

@property (nonatomic, assign) BOOL updateAvailable;
@property (nonatomic, strong) NSString * _Nullable version;

@property (nonatomic, strong) NSString * _Nullable hardwareVersion;

@property (nonatomic, strong) NSString * _Nullable applicationVersion;
@property (nonatomic, strong) NSString * _Nullable bootloaderVersion;
@property (nonatomic, strong) NSString * _Nullable softdeviceVersion;

@property (nonatomic, strong) NSString * _Nullable changelog;

@property (nonatomic, strong) NSString * _Nullable tarURL;

+ (BOOL)firmwareVersion:(NSString *)firmwareVersion isBiggerThan:(nonnull NSString *)referenceFirmwareVersion;

@end

NS_ASSUME_NONNULL_END
