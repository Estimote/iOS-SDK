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
#import "ESTSettingBase.h"
#import "ESTBeaconOperationProtocol.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTSettingReadOnly serves as a base class for Read Only settings defining 
 *  set of methods required to create read operations.
 */
@interface ESTSettingReadOnly : ESTSettingBase

/**
 *  Method allows to read setting for already initialized setting object.
 *
 *  @param completion Block invoked when read operation is complete.
 */
- (void)readValueWithCompletion:(ESTSettingCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
