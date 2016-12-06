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
#import "ESTBeaconConnection.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTBluetoothBeacon.h"

#define ESTBeaconInternalScannerErrorDomain @"ESTBeaconInternalScannerErrorDomain"

typedef NS_ENUM(NSInteger, ESTBeaconInternalScannerError)
{
    ESTBeaconInternalScannerErrorScanFailed,
    ESTBeaconInternalScannerErrorScanTimeout
};

typedef void (^BluetoothBeaconFindCompletion)(ESTBluetoothBeacon *beacon, NSError *error);

@interface ESTBeaconInternalScanner : NSObject

- (void)findBluetoothBeaconForBeacon:(CLBeacon *)beacon
                      completion:(BluetoothBeaconFindCompletion)completion;

- (void)findBluetoothBeaconForBeaconConnection:(ESTBeaconConnection *)beacon
                                completion:(BluetoothBeaconFindCompletion)completion;

@end
