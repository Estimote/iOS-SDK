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
#import <CoreLocation/CoreLocation.h>
#import "ESTRequestPostJSON.h"
#import "ESTBeaconDefinitions.h"
#import "ESTAnalyticsEventVO.h"

typedef void(^ESTRequestAnalyticsGroupTrackBlock)(NSError *error);


@interface ESTRequestAnalyticsTrack : ESTRequestPostJSON

- (instancetype)initWithEvents:(NSArray *)events;

- (void)sendRequestWithCompletion:(ESTRequestAnalyticsGroupTrackBlock)completion;

@end
