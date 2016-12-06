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

#import "ESTEddystoneFilter.h"

NS_ASSUME_NONNULL_BEGIN


/**
*  Eddystone-URL based filter used by `ESTEddystoneManager` in discovery process.
*  Filter should be initialized with URL string that is matching device(s)
*  should be discovered.
*
*  Default domain used by Estimote Devices is http://go.esti.be
*/
@interface ESTEddystoneFilterURL : ESTEddystoneFilter

@property (nonatomic, strong, readonly) NSString *eddystoneURL;

/**
* Initialize filter object with URL provided as NSString;
*/
- (instancetype)initWithURL:(NSString *)eddystoneURL;

@end

NS_ASSUME_NONNULL_END
