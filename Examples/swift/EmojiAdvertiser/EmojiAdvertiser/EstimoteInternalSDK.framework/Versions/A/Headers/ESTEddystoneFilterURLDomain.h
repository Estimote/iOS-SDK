//
//  ESTEddystoneFilterURLDomain.h
//  EstimoteSDK
//
//  Created by Marcin Klimek on 11/05/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

#import "ESTEddystoneFilter.h"

NS_ASSUME_NONNULL_BEGIN

/**
*  Eddystone-URLDomain based filter used by `ESTEddystoneManager` in discovery process.
*  Filter should be initialized with URL Domain string that is matching device(s)
*  should be discovered. URL domain gives more flexibility then regular URL based filter.
*  It allows to scan family of devices sharing same url domain in broadcasted packet.
*
*  For example you can have two devices broadcasting http://go.esti.be/kitchen and
*  http://go.esti.be/bedroom urls. In that case scanning with URL Domain defined as 'go.esti.be'
*  will provided both devices as discovery process result.
*/

@interface ESTEddystoneFilterURLDomain : ESTEddystoneFilter

/**
 *  URL Domain broadcasted by the device (based on `ESTEddystoneURL`).
 */
@property (nonatomic, strong, readonly) NSString *eddystoneURLDomain;

/**
 * Initialize filter object with URL Domain provided as NSString;
 */
- (instancetype)initWithURLDomain:(NSString *)eddystoneURLDomain;

@end

NS_ASSUME_NONNULL_END
