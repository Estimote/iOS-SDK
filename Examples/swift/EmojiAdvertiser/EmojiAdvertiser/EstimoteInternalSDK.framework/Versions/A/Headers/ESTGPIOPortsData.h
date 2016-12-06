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
#import "ESTGPIOPort.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Error domain for ESTGPIOPortsData class errors.
 */
#define ESTGPIOPortsDataErrorDomain @"ESTGPIOPortsDataErrorDomain"

/**
 *  Possible error codes for setting port value operation.
 */
typedef NS_ENUM(NSInteger, ESTGPIOPortsDataError)
{
    /**
     *  Error code for incorrect port provided.
     */
    ESTGPIOPortsDataErrorIncorrectPort,
    /**
     *  Error code for incorrect value provided.
     */
    ESTGPIOPortsDataErrorIncorrectValue
};

/**
 *  Possible values of GPIO ports.
 */
typedef NS_ENUM(NSInteger, ESTGPIOPortValue)
{
    /**
     *  Unknown value of GPIO port used for
     *  incorrect port or missing proper value.
     */
    ESTGPIOPortValueUnknown = -1,
    /**
     *  LOW value of GPIO port.
     */
    ESTGPIOPortValueLow = 0,
    /**
     *  HIGH value of GPIO port.
     */
    ESTGPIOPortValueHigh = 1
};


/**
 *  ESTGPIOPortData is Value Object representing state
 *  of all available GPIO port.
 */
@interface ESTGPIOPortsData : NSObject <NSCopying>

/**
 *  Initialize object with values for GPIO ports 0 and 1.
 *  For incorrect port values nil is returned. 
 *
 *  Basic init method ([ESTGPIOPortsData alloc] init]) should not
 *  be used. NSAssert will be thrown in that case.
 *
 *  @param port0Value Desired value for port 0.
 *  @param port1Value Desired value for port 1.
 *
 *  @return Initialized object or nil (for incorrect values).
 */
- (instancetype)initWithPort0Value:(ESTGPIOPortValue)port0Value
                        port1Value:(ESTGPIOPortValue)port1Value;

/**
 *  Method allows to set value for particular port.
 *
 *  @param port  Port should the value be set to.
 *  @param value Desired value for port.
 *
 *  @return Error of operation. No error means success.
 */
- (NSError *)setPort:(ESTGPIOPort)port value:(ESTGPIOPortValue)value;

/**
 *  Method allows to get value for GPIO port.
 *
 *  @param port Port should the value be get from.
 */
- (ESTGPIOPortValue)getValueForPort:(ESTGPIOPort)port;

@end

NS_ASSUME_NONNULL_END
