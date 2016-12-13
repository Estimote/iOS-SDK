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

#import "ESTBaseVO.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ESTDeviceSettingsAdvertiserSettingsPower)
{
    ESTDeviceSettingsAdvertiserSettingsPower1 = -30,
    ESTDeviceSettingsAdvertiserSettingsPower2 = -20,
    ESTDeviceSettingsAdvertiserSettingsPower3 = -16,
    ESTDeviceSettingsAdvertiserSettingsPower4 = -12,
    ESTDeviceSettingsAdvertiserSettingsPower5 = -8,
    ESTDeviceSettingsAdvertiserSettingsPower6 = -4,
    ESTDeviceSettingsAdvertiserSettingsPower7 = 0,
    ESTDeviceSettingsAdvertiserSettingsPower8 = 4
};


/**
 *  This Value Object represents settings structure for generic packet.
 */
@interface ESTDeviceSettingsAdvertiser : ESTBaseVO <NSCopying>

/**
 *  Index of advertiser;
 */
@property (nonatomic, strong, readonly) NSNumber *index;

/**
 *  Name of the advertiser.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
 *  Flag indicating if advertiser is enabled.
 */
@property (nonatomic, strong, readonly) NSNumber *enabled;

/**
 *  Broadcasting power of packet advertiser represented by ESTDeviceSettingsPacketSettingsPower1 enum.
 */
@property (nonatomic, strong, readonly) NSNumber *powerInDBm;

/**
 *  Advertising interval of packet advertiser;
 */
@property (nonatomic, strong, readonly) NSNumber *intervalInSeconds;

/**
 *  Designated initializer.
 *
 *  @param dictionary Dictionary delivered from Estimote Cloud.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithCloudDictionary:(NSDictionary *)dictionary;

/**
 *  Method allows to update all fields of advertiser settings using
 *  other object of the same class. When field exists settings is overwritten
 *  if nil nothing happens.
 *
 *  @param generalSettings Object should be used to update settings.
 */
- (void)updateWithAdvertiserSettings:(ESTDeviceSettingsAdvertiser *)advertiserSettings;

/**
 *  Method for returning dictionary represantation of advertiser settings.
 */
- (NSDictionary *)cloudDictionary;

@end

NS_ASSUME_NONNULL_END
