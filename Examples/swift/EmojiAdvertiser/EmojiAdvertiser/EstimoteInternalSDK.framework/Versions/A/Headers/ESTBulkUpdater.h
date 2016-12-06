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

#import "ESTBeaconUpdateConfig.h"
#import "ESTBeaconUpdateInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ESBulkUpdaterStatus)
{
    ESBulkUpdaterStatusIdle,
    ESBulkUpdaterStatusUpdating,
    ESBulkUpdaterStatusCompleted
};

typedef NS_ENUM(NSInteger, ESTBulkUpdaterMode)
{
    ESTBulkUpdaterModeForeground,
    ESTBulkUpdaterModeBackground
};

/**
 *  Notification used when Bulk updater starts
 */
extern NSString * const ESTBulkUpdaterBeginNotification;

/**
 *  The object associated with the notification is the bulk updater.
 *  User info dictionary contains progress (float value) under progress key.
 */
extern NSString * const ESTBulkUpdaterProgressNotification;

/**
 *  The object associated with the notification is the bulk updater.
 */
extern NSString * const ESTBulkUpdaterCompleteNotification;

/**
 *  The object associated with the notification is the bulk updater.
 */
extern NSString * const ESTBulkUpdaterFailNotification;

/**
 *  Notification used to inform user about timeout.
 */
extern NSString * const ESTBulkUpdaterTimeoutNotification;

/**
 *  Main class of the bulk updater that performs all update operations
    handled by objects of `<ESBulkUpdaterSingleOperation>` class. Updates are performed
    in the concurent queue and can work both in foreground and background.
 *
 *  To star bulk update you need to prepare array of `<ESBeaconUpdateInfo>` objects containg beacons
 *  and update configuration. Then just invoke `startWithBeaconInfos:timeout:` method of this class
 *  to start update procedure. This class defines notifications that can be used to get progress
 *  of update procedure state.
 */

@interface ESTBulkUpdater : NSObject

/**
 *  Array with information about beacons update status. Contains objects of ESBeaconUpdateInfo.
 */
@property (nonatomic, strong) NSArray<ESTBeaconUpdateInfo *> * _Nullable beaconInfos;

/**
 *  Indicating what mode is bulk updater currently running.
 */
@property (nonatomic, readonly) ESTBulkUpdaterMode mode;

/**
 *  Status of bulk updater.
 */
@property (nonatomic, readonly) ESBulkUpdaterStatus status;

/**
 *  ESBulkUpdater
 *
 *  @return Returns singleton instance of bulk updater.
 */
+ (ESTBulkUpdater *)sharedInstance;

/**
 *  Verify if incoming Push Notification is related
 *  to pending settings update comming from the Estimote Cloud
 *
 *  @param payload userInfo field comming from application:didReceiveRemoteNotification:fetchCompletionHandler:
 *
 *  @return result of verification
 */
+ (BOOL)verifyPushNotificationPayload:(NSDictionary *)payload;

/**
 *  Starts update process based on changes applied in the cloud.
 *
 *  @param timeout  Timeout for bulk update operation in seconds. 0 means no timeout.
 */
- (void)startWithCloudSettingsAndTimeout:(NSTimeInterval)timeout;

/**
 *  Starts update process for given beacons and updates them accordingly to given config.
 *
 *  @param beaconInfos  Array with `<ESBeaconUpdateInfo>` objects, defining updates for beacons.
 *  @param timeout      Timeout for bulk update operation in seconds. 0 means no timeout.
 */
- (void)startWithBeaconInfos:(NSArray *)beaconInfos
                     timeout:(NSTimeInterval)timeout;

/**
 *  Verify if beacon is currently in update process
 *
 * @param macAddress Mac Address of device to verify
 *
 * @return BOOL value indicating if beacon is waiting for update
 */
- (BOOL)isUpdateInProgressForBeaconWithMacAddress:(NSString *)macAddress;

/**
 * Verify if beacon is currently waiting for update
 *
 * @param macAddress Mac Address of device to verify
 *
 * @return BOOL value indicating if beacon is waiting for update
 */
- (BOOL)isBeaconWaitingForUpdate:(NSString *)macAddress;

/**
 * Get all possible infos for particular beacon
 *
 * @param macAddress Mac Address of device to get beacon infos for
 *
 * @return NSArray containing all related beacon infos
 */
- (NSArray *)getBeaconUpdateInfosForBeaconWithMacAddress:(NSString *)macAddress;

/**
 * Returns time left to bulk update timeout
 */
- (NSTimeInterval)getTimeLeftToTimeout;

/**
 * Cancels update process. Note that currently updating beacon will finish.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
