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

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSemverComparer is a helper class to faciliate comparing semver strings.
 */
@interface ESTSemverComparer : NSObject

/**
 *  Method compares semantic version strings using "≥" check. Useful for checking if given feature is supported.
 *
 *  @param version          Semver string under check.
 *  @param referenceVersion Semver string the first argument is compared against.
 *
 *  @return Boolean, YES if the check passed.
 */
+ (BOOL)version:(NSString *)version isBiggerOrEqualToVersion:(NSString *)referenceVersion;

/**
 *  Method compares semantic version strings using ">" check. Useful for checking if firmware update is available.
 *
 *  @param version          Semver string under check.
 *  @param referenceVersion Semver string the first argument is compared against.
 *
 *  @return Boolean, YES if the check passed.
 */
+ (BOOL)version:(NSString *)version isStrictlyBiggerThanVersion:(NSString *)referenceVersion;

@end

NS_ASSUME_NONNULL_END
