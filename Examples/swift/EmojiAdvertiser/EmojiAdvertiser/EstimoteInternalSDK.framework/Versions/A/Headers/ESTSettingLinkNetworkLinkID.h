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
#import "ESTSettingReadWrite.h"

#define ESTSettingLinkNetworkLinkIDErrorDomain @"ESTSettingLinkNetworkLinkIDErrorDomain"

/**
 *  Describes Link Network Domain validation error.
 */
typedef NS_ENUM(NSUInteger, ESTSettingLinkNetworkLinkIDError)
{
    /**
     *  Provided value is too small. Should be equal or bigger than zero.
     */
    ESTSettingLinkNetworkLinkIDErrorTooSmall = 1,
    
    /**
     *  Provided value is too big. Should be lesser or equal to 16777215.
     */
    ESTSettingLinkNetworkDomainErrorTooBig = 2
};

@class ESTSettingLinkNetworkLinkID;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of read/write setting LinkID operation for Link Network packet.
 *
 *  @param linkID LinkID setting carrying value.
 *  @param error Operation error. No error means success.
 */
typedef void(^ESTSettingLinkNetworkLinkIDCompletionBlock)(ESTSettingLinkNetworkLinkID * _Nullable linkIDSetting, NSError * _Nullable error);


/**
 *  ESTSettingLinkNetworkLinkID represents Link Network LinkID value.
 */
@interface ESTSettingLinkNetworkLinkID : ESTSettingReadWrite <NSCopying>

/**
 *  Designated initializer. Validates provided value internally with +validationErrorForValue:.
 *
 *  @see +[ESTSettingLinkNetworkLinkID validationErrorForValue:]
 *
 *  @param linkID Link Network LinkID value.
 *
 *  @return Initialized object. Nil if validation fails.
 */
- (instancetype)initWithValue:(uint32_t)linkID;

/**
 *  Returns current value of Link Network LinkID setting.
 *
 *  @return Link Network LinkID value.
 */
- (uint32_t)getValue;

/**
 *  Method allows to read value of initialized Link Network LinkID setting object.
 *
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)readValueWithCompletion:(ESTSettingLinkNetworkLinkIDCompletionBlock)completion;

/**
 *  Method allows to create write operation from already initialized Link Network LinkID setting object.
 *  Value provided during initialization will be used as a desired value.
 *
 *  @param linkID LinkID value to be written to the device.
 *  @param completion Block to be invoked when operation is complete.
 *
 *  @return Initialized operation object.
 */
- (void)writeValue:(uint32_t)linkID completion:(ESTSettingLinkNetworkLinkIDCompletionBlock)completion;

/**
 *  Method checks if provided value is allowed. Returns nil if validation passes.
 *
 *  @param linkID LinkID value.
 *
 *  @return Error object describing why validation failed. Nil if validation passes.
 */
+ (NSError * _Nullable)validationErrorForValue:(uint32_t)linkID;

@end

NS_ASSUME_NONNULL_END
