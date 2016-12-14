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
#import "ESTMeshNetworkDetailsVO.h"
#import "ESTDeviceLocationBeacon.h"
#import "ESTDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

#define ESTMeshHelperErrorDomain @"ESTMeshHelperErrorDomain"

/**
 *  Describes Mesh Network Helper validation errors.
 */
typedef NS_ENUM(NSUInteger, ESTMeshNetworkHelperError)
{
    /**
     *  Provided value is incorrect.
     */
    ESTMeshNetworkHelperErrorInvalidParameter = 1,
    ESTMeshNetworkHelperErrorDisconnected,
    ESTMeshNetworkHelperErrorDeviceAlreadyInMesh,
    ESTMeshNetworkHelperErrorDeviceNotAssignedToMesh,
    ESTMeshNetworkHelperErrorDeviceMeshSettingsSynchronisationFailed,
    ESTMeshNetworkHelperErrorNotAuthorized,
};

/**
 *  ESTMeshNetworkHelper is responsible for offline Mesh networks management.
 */
@interface ESTMeshNetworkHelper : NSObject

/**
 *  Method for creating value object of Mesh network's details.
 *
 *  @param  name    Mesh network's name.
 *  @param  devices Array of Location Beacon's identifiers to be included in Mesh network.
 *
 *  @return Initialised value object of Mesh network details.
 */
- (ESTMeshNetworkDetailsVO *)createNewMeshNetworkNamed:(NSString *)name;

/**
 *  Method returning list of Mesh networks value objects currently stored by ESTMeshNetworkHelper.
 */
- (NSArray <ESTMeshNetworkDetailsVO *> *)meshNetworks;

/**
 *  Method returning Mesh network for specified device
 *
 *  @param identifier Device identifier that the Mesh network is tied to
 *
 *  @return ESTMeshNetworkDetailsVO Mesh network or nil of none exists
 */
- (ESTMeshNetworkDetailsVO *)existingMeshNetworkForDevice:(NSString *)identifier;

/**
 *  Method to add specified device to a Mesh network
 *
 *  @param device     Device to add to the Mesh network
 *  @param mesh       Mesh network for the device to be added to
 *  @param completion Completion block with error. If no error, adding the device was a success.
 */
- (void)addDevice:(ESTDeviceLocationBeacon *)device
    toMeshNetwork:(ESTMeshNetworkDetailsVO *)mesh
   withCompletion:(ESTCompletionBlock)completion;

/**
 *  Method to remove sepecified device from a Mesh network
 *
 *  @param device     Device to remove from the Mesh network
 *  @param mesh       Mesh network for the device to be removed from
 *  @param completion Completion block with error. If no error, removing the device was a success.
 */
- (void)removeDevice:(ESTDeviceLocationBeacon *)device
     fromMeshNetwork:(ESTMeshNetworkDetailsVO *)mesh
      withCompletion:(ESTCompletionBlock)completion;

/**
 *  Increments settings version so it can be propagated over the mesh network.
 *
 *  @param device     Device to increment settings version for
 *  @param completion Completion block with error. If no error, incrementing settings version was a success.
 */
- (void)incrementMeshSettingVersionForDevice:(ESTDeviceLocationBeacon *)device
                                  completion:(ESTCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
