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
#import "ESTRequestBase.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * ESTRequestPostFormData class allows you to create POST request for sending single file
 * to cloud, if cloud api requires multipart/form-data as Content-Type.
 *
 */
@interface ESTRequestPostFormData : ESTRequestBase

/**
 * Method for setting request paramers.
 *
 * @param filePath path to file that should be sent
 * @param request request that should have it's parameters set
 *
 */
- (void)setFilePath:(NSString *)filePath forRequest:(NSMutableURLRequest *)request;

@end

NS_ASSUME_NONNULL_END
