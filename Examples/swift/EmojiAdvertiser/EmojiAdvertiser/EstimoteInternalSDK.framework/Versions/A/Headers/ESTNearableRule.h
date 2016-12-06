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

#import "ESTRule.h"
#import "ESTNearable.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The `ESTNearableRule` is abstract class defining base methods for all Estimote nearable related rules. It should not be used itself as it is not
 * defining any conditions.
 */

@interface ESTNearableRule : ESTRule

/**
 *  Identifier of nearable that is going to be associated with this rule.
 */
@property (nonatomic, strong, readonly) NSString * _Nullable nearableIdentifier;

/**
 *  Type of nearable that is going to be associated with this rule.
 */
@property (nonatomic, assign, readonly) ESTNearableType nearableType;

/**
 *  Initialization method creating rule based on specific Estimote nearable identifier.
 *
 *  @param identifier Estimote nearable identifier
 *
 *  @return created rule object
 */
- (instancetype)initWithNearableIdentifier:(NSString *)identifier;

/**
 *  Initialization method creating rule based on specific Estimote nearable type.
 *
 *  @param type Estimote nearable type
 *
 *  @return created rule object
 */
- (instancetype)initWithNearableType:(ESTNearableType)type;

/**
 *  Method that is invoked by trigger manager object to update state of the rule.
 *
 *  When creating custom nearable related rule, this method should be implemented to update state property of this class,
 *  based on passed nearable object. For not nearable related rules `update` method of `<ESTRule>` should be used instead.
 *
 *  @param nearable Estimote nearable object with most recent settings
 *
 */
- (void)updateWithNearable:(ESTNearable *)nearable;

@end

NS_ASSUME_NONNULL_END
