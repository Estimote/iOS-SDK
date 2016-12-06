//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  ESTEddystoneAttachment class represents attachments from resolving EID.
 */
@interface ESTEddystoneAttachment : NSObject <NSCopying>

/*
 *  Specifies what kind of attachment this is and how to interpret data. Format is namespace/type.
 */
@property (nonatomic, readonly) NSString * _Nullable namespacedType;

/**
 *  Opaque data container for client-provided data.
 */
@property (nonatomic, readonly) NSString * _Nullable data;

/**
 *  Initialize object with specified namespacedType and data.
 *
 *  @param namespacedType   String representing what kind of attachment is this.
 *  @param data User-provided data.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithNamespacedType:(nullable NSString *)namespacedType data:(nullable NSString *)data;

/**
 *  Initialize object with cloud data.
 *
 *  @param cloudData Cloud data associated with Eddystone attachment
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudData:(NSDictionary *)cloudData;

@end

NS_ASSUME_NONNULL_END
