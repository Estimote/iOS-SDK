//
//  ESTBeaconUpdateInfo.h
//  EstimoteSDK
//
//  Version : 1.2.0
//  Created by Marcin Klimek on 27/11/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ESTBeaconUpdateInfo : NSObject

@property (nonatomic, strong) NSString* currentFirmwareVersion;
@property (nonatomic, strong) NSArray*  supportedHardware;

@end
