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
#import "ESTRequestPutJSON.h"
#import "ESTBeaconVO.h"

typedef void(^ESTRequestSaveBeaconBlock)(ESTBeaconVO *beaconVO, NSError *error);


@interface ESTRequestSaveBeacon : ESTRequestPutJSON

@property (nonatomic, strong) ESTBeaconVO *beaconVO;
@property (nonatomic, assign) NSString *nextName;

/**
 *  Methods allows to send request with completion block invoked as a result.
 *
 *  @param completion Completion block with returned data (ESTBeaconVO object with color and macAddress property filled).
 */
- (void)sendRequestWithCompletion:(ESTRequestSaveBeaconBlock)completion;

@end
