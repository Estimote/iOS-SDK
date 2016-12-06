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
#import "ESTDefinitions.h"

@class ESTPeripheralTypeUtility;

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTStorageManager class is responsible for managing Location Beacon's non-volatile storage.
 */
@interface ESTStorageManager : NSObject

/**
 *  Dictionary of data stored in Estimote Storage.
 */
@property (nonatomic, strong, readonly) NSDictionary *storageDictionary;

/**
 *  Designated initializer.
 *
 *  @param deviceIdentifier Identifier of device
 *  @param peripheral ESTPeripheralTypeUtility object of device
 *
 *  @return Initilized ESTStorageManager object with empty storageDictionary property.
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier peripheral:(ESTPeripheralTypeUtility *)peripheral;

/**
 *  Method for reading storageDictionary from Estimote Storage. Authorized conenction is optional.
 *
 *  @param completion Completion block with Estimote Storage current dictionary content.
 */
- (void)readStorageDictionaryWithCompletion:(ESTDictionaryCompletionBlock)completion;

/**
 *  Method for overwriting storageDictionary. Authorized connection required.
 *
 *  @param dictionary NSDictionary object that will overwrite storageDictionary.
 *  @param completion Completion block returning NSError if saving to Estimote Storage would fail.
 */
- (void)saveStorageDictionary:(NSDictionary *)dictionary withCompletion:(ESTCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
