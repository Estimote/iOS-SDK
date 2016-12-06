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

typedef NS_ENUM(int, ESTColor)
{
    ESTColorUnknown,
    ESTColorMintCocktail,
    ESTColorIcyMarshmallow,
    ESTColorBlueberryPie,
    ESTColorSweetBeetroot,
    ESTColorCandyFloss,
    ESTColorLemonTart,
    ESTColorVanillaJello,
    ESTColorLiquoriceSwirl,
    ESTColorWhite,
    ESTColorBlack,
    ESTColorTransparent
};

typedef NS_ENUM(int, ESTConnectionStatus)
{
    ESTConnectionStatusDisconnected,
    ESTConnectionStatusConnecting,
    ESTConnectionStatusConnected,
    ESTConnectionStatusUpdating
};

typedef NS_ENUM(char, ESTBroadcastingScheme)
{
    ESTBroadcastingSchemeUnknown,
    ESTBroadcastingSchemeEstimote,
    ESTBroadcastingSchemeIBeacon,
    ESTBroadcastingSchemeEddystoneURL,
    ESTBroadcastingSchemeEddystoneUID
};

typedef void(^ESTCompletionBlock)(NSError * _Nullable error);
typedef void(^ESTObjectCompletionBlock)(id _Nullable result, NSError * _Nullable error);
typedef void(^ESTDataCompletionBlock)(NSData * _Nullable result, NSError * _Nullable error);
typedef void(^ESTNumberCompletionBlock)(NSNumber * _Nullable value, NSError * _Nullable error);
typedef void(^ESTUnsignedShortCompletionBlock)(unsigned short value, NSError * _Nullable error);
typedef void(^ESTBoolCompletionBlock)(BOOL value, NSError * _Nullable error);
typedef void(^ESTStringCompletionBlock)(NSString * _Nullable value, NSError * _Nullable error);
typedef void(^ESTProgressBlock)(NSInteger value, NSString * _Nullable description, NSError * _Nullable error);
typedef void(^ESTArrayCompletionBlock)(NSArray * _Nullable value, NSError * _Nullable error);
typedef void(^ESTDictionaryCompletionBlock)(NSDictionary * _Nullable value, NSError * _Nullable error);
typedef void(^ESTCsRegisterCompletonBlock)(NSError * _Nullable error);

@interface ESTDefinitions : NSObject

+ (NSString *)nameForEstimoteColor:(ESTColor)color;

@end

NS_ASSUME_NONNULL_END
