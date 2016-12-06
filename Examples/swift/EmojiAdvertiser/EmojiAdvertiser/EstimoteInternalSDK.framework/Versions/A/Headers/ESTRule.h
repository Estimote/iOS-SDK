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

/**
 * The `ESTRule` class defines single rule of `<ESTTrigger>` object. Each rule has state value that indicates if it was fulfilled or not.
 */

@interface ESTRule : NSObject

/**
 *  Current state of the rule.
 */
@property (nonatomic, assign) BOOL state;

/**
 *  Method that is invoked by trigger manager object to update state of the rule.
 *  
 *  When creating custom rule, this method should be implemented to update state property of this class, 
 *  based on developer defined conditions.
 */
- (void)update;

@end

NS_ASSUME_NONNULL_END
