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
#include <string.h>

/**
 *  User friendly ready to use macros for logging with each `ESTLogLevel`.
 */
#define ESTVerboseLog(fmt, ...) [ESTLogger log:[NSString stringWithFormat:(@"%s:%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] withLevel:ESTLogLevelVerbose]
#define ESTInfoLog(fmt, ...) [ESTLogger log:[NSString stringWithFormat:(@"%s:%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] withLevel:ESTLogLevelInfo]
#define ESTErrorLog(fmt, ...) [ESTLogger log:[NSString stringWithFormat:(@"%s:%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] withLevel:ESTLogLevelError]
#define ESTWarningLog(fmt, ...) [ESTLogger log:[NSString stringWithFormat:(@"%s:%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] withLevel:ESTLogLevelWarning]
#define ESTDebugLog(fmt, ...) [ESTLogger log:[NSString stringWithFormat:(@"%s:%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] withLevel:ESTLogLevelDebug]

/**
 *  Log levels are used to filter out logs to print and cache.
 */
typedef enum : int
{
    /**
     *  No logs.
     */
    ESTLogLevelNone,
    /**
     *  Error logs only.
     */
    ESTLogLevelError,
    /**
     *  Error and warnings logs only.
     */
    ESTLogLevelWarning,
    /**
     *  Error, warning and debug logs only.
     */
    ESTLogLevelDebug,
    /**
     *  Error, warning, debug and info logs only.
     */
    ESTLogLevelInfo,
    /**
     *  All logs.
     */
    ESTLogLevelVerbose
    
} ESTLogLevel;

/**
 *  ESTLogger is a helper class to faciliate handling logs and debugging. Class is compatible with KZLinkedConsole.
 */

@interface ESTLogger : NSObject

/**
 *  Method allows to set `ESTLogLevel` for console. Logs above given level will not be printed to console.
 */
+ (void)setConsoleLogLevel:(ESTLogLevel)level;

/**
 *  Method allows to set `ESTLogLevel` for cache. Logs above given level will not be cached by logger.
 */
+ (void)setCacheLogLevel:(ESTLogLevel)level;

/**
 *  Method retrieves logs from cache.
 */
+ (NSString *)getLogCache;

/**
 *  Method clears cached logs.
 */
+ (void)clearLogCache;

/**
 *  Method logs given string with specific level. @warning *Warning:* Using this method with `ESTLoglevel` higher than currently
 *  set with `enableLogger:withLevel:` or `setConsoleLogLevel:` will not print message.
 */
+ (void)log:(NSString *)message
  withLevel:(ESTLogLevel)level;

/**
 *  Write cached logs to document file. To retrieve it use iTunes File Sharing. For more info visit: https://support.apple.com/en-us/HT201301 .
 *
 *  Remember to set UIFileSharingEnabled to YES (also known as "Application supports iTunes file sharing") in your app's Info.plist.
 */
+ (void)dumpLogCacheToFile;

@end
