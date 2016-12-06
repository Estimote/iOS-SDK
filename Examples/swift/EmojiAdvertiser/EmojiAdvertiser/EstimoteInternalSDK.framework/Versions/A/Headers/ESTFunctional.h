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

/**
 *  Helper class providing collection methods known from functional languages.
 */
@interface ESTFunctional<T> : NSObject

/**
 *  Iterates over array, executes block and returns collection of values returned by that block.
 *
 *  @param array Array to iterate over.
 *  @param block Block to be executed on each element.
 *
 *  @return Array of values returned by block.
 */
+ (NSArray<T> *)mapArray:(NSArray<T> *)array block:(id(^)(T element))block;

/**
 *  Iterates over array and leaves given element only if it passes block.
 *
 *  @param array Array to iterate over.
 *  @param block Block used for check.
 *
 *  @return Array of elements for which block returned YES.
 */
+ (NSArray<T> *)filterArray:(NSArray<T> *)array block:(BOOL(^)(T element))block;

@end
