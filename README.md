# Estimote SDK for Apple iOS

## Table of Contents

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [Introduction](#introduction)
- [Installation](#installation)
- [Technical overview](#technical-overview)
  - [Client](#client)
    - [Telemetry](#telemetry)
  - [Utility](#utility)
    - [Connecting to devices in SDK 4](#connecting-to-devices-in-sdk-4)
    - [Settings](#settings)
    - [Convenience API](#convenience-api)
    - [Advanced API](#advanced-api)
    - [Bulk Updater](#bulk-updater)
- [Changelog](#changelog)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->


## Introduction

Our SDK provides a wide range of both utility and client-facing features that will save time and make iBeacon development easier than ever. It's built purely on Apple Core Location and Core Bluetooth technologies and is 100% iBeacon compatible.

In addition to the Estimote SDK we've included a lot of examples to show you how to use our SDK in real scenarios. You should also check our utility app that [can be found in the App Store](https://itunes.apple.com/en/app/estimote/id686915066?mt=8).

To learn more, read the [API section on our website](http://estimote.com/api/index.html#). You can review the [SDK documentation](http://estimote.github.io/iOS-SDK/) and check our [Developer Portal](http://developer.estimote.com) to get the answers for the most common questions related to beacons and Estimote tools.

## Installation

Estimote SDK 4.0 comes to you as a **framework**. To setup, you only need to include a single *EstimoteSDK.framework* file in your project to get started:

1. Drag and drop EstimoteSDK.framework file into your Xcode project. It will automatically show up in your project navigator and will be added to *"Linked Frameworks and Libraries"* section in project settings.

2. Estimote SDK depends on Apple's CoreLocation and CoreBlueooth frameworks as well as SystemConfiguration framework to handle Estimote Cloud API requests, so you should include them in your project too. When you add them to your project settings, it should look like on the screenshot below.
<img src="images/build_phases.png" alt="Build Phases" width="840">

3. That's it, congratulations and happy hacking!

## Technical overview

The SDK requires iOS 7+, as it depends on the CoreLocation's support for iBeacon which was first introduced in iOS 7. Features of Estimote SDK are divided into two parts: *Client* and *Utility*.

### Client

**Client** part is dedicated to be used inside your publicly distributed applications featuring Estimote Beacons or Nearables integration. It helps you work with Apple iBeacon objects, adding useful functionality like filtering, ranged object limitation, or combining beacons from few regions into one callback.

Description of most important components are below:

* `ESTBeaconManager` - Simple wrapper around Core Location's CLLocationManager class. It exposes API to range and monitor iBeacon devices with some additional options like sorting or filtering. It works with pure CLBeacon objects.
* `ESTSecureBeaconManager` - CLLocationManager wrapper dedicated to work with devices that are using Estimote Secure UUID. Similarily to ESTBeaconManager it allows to range and monitor secured devices as well as estimate their proximity.
* `ESTNearableManager` - Entry point to work with nearables. It allows to range and monitor stickers with given type or identifier in the similar manner to how it's done with iBeacon.
* `ESTEddystoneManager` - Entry point to work with [Eddystones](https://github.com/google/eddystone). Allows to discover Eddystone packets broadcasted by beacons.
* `ESTDeviceManager` - Use it to be up-to-date with current values of device's sensors (such as temperature) broadcasted in Estimote Telemetry packet.

#### Telemetry

When *EstimoteTLM* packet is enabled (see `ESTSettingsEstimoteTLMEnable` class), beacons broadcast Estimote Telemetry packets. They contain information about current values read by beacon's sensors. Telemetry packet includes readings from:

- Motion sensor (3-axis acceleration & more) [Proximity & Location Beacons]
- Temperature sensor [Proximity & Location Beacons]
- Ambient light sensor [Location Beacons only]
- Magnetometer sensor [Location Beacons only]
- GPIO Ports [Location Beacons only]

**Usage**

```swift
// remember to hold a strong reference to the device manager for as long as you
// want to receive the telemetry notifications
// e.g., make it a class property, and not a local variable, so that it won't get
// prematurely deallocated
let deviceManager = ESTDeviceManager()

// ...

let temperatureNotification = ESTTelemetryNotificationTemperature { (temperature) in
    print("Current temperature: \(temperature.temperatureInCelsius) C")
}
deviceManager.register(forTelemetryNotification: temperatureNotification)
```

Make sure to check out the other `ESTTelemetryNotification` classes in the [SDK reference](http://estimote.github.io/iOS-SDK/) (e.g., [`ESTTelemetryNotificationMotion`](http://estimote.github.io/iOS-SDK/Classes/ESTTelemetryNotificationMotion.html))

### Utility

**Utility** was created to support apps that manage Estimote Beacons and Nearables. It provides beacon connectivity and configuration methods, so you can easily change settings like Proximity UUID, Major, Minor, Power Modes and much more. It also allows you to easily perform Over The Air firmware update. It works mainly with Core Bluetooth framework.

#### Connecting to devices in SDK 4

Connecting to device lets you change its settings (broadcasting power, advertising interval etc.). You have to be the beacon's owner in Estimote Cloud; every attempt to connect with a device not linked to your Estimote account will fail.

Connectivity packets are represented by `ESTDeviceConnectable` subclasses:
- `ESTDeviceLocationBeacon` represents Estimote Location Beacon (hardware revision "F") and next-gen Proximity Beacon (hardware revision "G") … yes, we know it's a bit weird to use `ESTDeviceLocationBeacon` to connect to your next-gen Proximity Beacons, but you do have to trust us on this one ^\_^
- `ESTDeviceNearable` represents Estimote Nearable.

Following steps are required to connect to a device:

1. Create `ESTDeviceManager`, make sure your class conforms to `ESTDeviceManagerDelegate` protocol.

2. Start discovery by calling `startDiscoveryWithFilter:` with filter object. This can be either `ESTDeviceFilterLocationBeacon` or `ESTDeviceFilterNearable`.

3. Method `deviceManager:didDiscoverDevices:` provides discovered devices matching filter.

4. Make sure your class conforms to `ESTDeviceConnectableDelegate` protocol and call `connect` on discovered `ESTDeviceConnectable` object. Now, the SDK verifies if the device is linked to account specified by AppID + AppToken pair, authorizes user, connects on the Bluetooth level and synchronizes settings by fetching their values from Cloud and writing to the device.

In order to connect to the first-generation Estimote Proximity Beacon (hardware revision "D"), use  the [SDK 3 API](SDK_3_x_README.md).

#### Settings
In SDK 4.0 each device setting is represented by an `ESTSettingBase` subclass. There are two ways of reading/writing settings - [Convenience API](#convenience-api) and [Advanced API](#advanced-api).

These classes are wrappers around basic types (both primitives and objects) such as `unsigned integer` or `NSString`,



- `ESTSetting*` classes are wrappers around values providing validation.
- `ESTBeaconOperation*` classes specify details used to read or write setting to the device.

#### Convenience API
To simply change a device setting you can use the **Conveniece API tree**.
Each device has one, here's an example of `ESTDeviceLocationBeacon` settings tree:
```
device
  |- settings
    |- iBeacon
      |- proximityUUID
      |- major
      |- minor
      ...
    |- estimote
      |- enable
      |- power
      ...
    |- deviceInfo
      |- color
      |- name
      ...
    ...
```
To read/write s device setting value call `readValueWithCompletion:` or `writeValue:completion:` method on one of the tree's leaf.

**Usage example**

I have an Estimote Location Beacon and I want to turn iBeacon packet on, change its Major value to 500, and read its Proximity UUID.
```objective-c
[device.settings.iBeacon.enable writeValue:YES completion:^(ESTSettingIBeaconEnable *enableSetting, NSError *error) {
  NSLog(@"iBeacon packet enabled");
}];

[device.settings.iBeacon.major writeValue:500 completion:^(ESTSettingIBeaconMajor *majorSetting, NSError *error) {
  NSLog(@"Major set to 500");
}];

[device.settings.iBeacon.proximityUUID readValueWithCompletion:^(ESTSettingIBeaconProximityUUID *uuidSetting, NSError *error) {
  NSLog(@"Proximity UUID is %@", [uuidSetting getValue]);  
}];
```

#### Advanced API

To speed up interacting with multiple settings at once you can use the **Advanced API**. Each setting has its own setting and operation classes pair.
* Setting classes are subclasses of `ESTSettingBase` and have their names constructed by concatenating `ESTSetting` + SettingGroupName + SettingShortName (i.e. ESTSettingIBeaconMajor). They are wrappers around setting values (both primitive types and object types), they also provide value validation.
* Operation classes are subclasses of `ESTSettingOperation` and have their name constructed by concatenating `ESTBeaconOperation` (if it's a setting stored in the device memory, such as iBeacon Major) or `ESTCloudOperation` (if it's a setting stored only in Cloud, such as DeviceInfo Name) + SettingGroupName + SettingShortName (i.e. ESTBeaconOperationIBeaconMajor or ESTCloudOperationDeviceInfoName).

**Usage example**

I have an Estimote Location Beacon and I want to turn iBeacon packet on, change its Major value to 200, read its Proximity UUID, perform many other operations and want to do this as fast as possible.
```objective-c
ESTSettingIBeaconEnable *enableSetting = [[ESTSettingIBeaconEnable alloc] initWithValue:YES];
ESTBeaconOperationIBeaconEnable *enableOperation = [ESTBeaconOperationIBeaconEnable writeOperationWithSetting:enableSetting completion:^(ESTSettingIBeaconEnable *setting, NSError *error)
  NSLog(@"iBeacon packet enabled");
}];

unsigned short major = 200;
ESTSettingIBeaconMajor *majorSetting = [[ESTSettingIBeaconMajor alloc] initWithValue:major];
ESTBeaconOperationIBeaconMajor *majorOperation = [ESTBeaconOperationIBeaconMajor writeOperationWithSetting:majorSetting completion:^(ESTSettingIBeaconMajor *setting, NSError *error) {
  NSLog(@"Major set to 200");
}];

ESTBeaconOperationIBeaconProximityUUID *uuidOperation = [ESTBeaconOperationIBeaconProximityUUID readValueWithCompletion:^(ESTSettingIBeaconProximityUUID *setting, NSError *error) {
  NSLog(@"Proximity UUID is %@", [uuidSetting getValue]);
}];

...

[device.settings performOperations:enableOperation, majorOperation, uuidOperation, ..., nil];
```

#### Bulk Updater

To perform bulk update operations on devices represented by `ESTDeviceLocationBeacon` class you should use the `ESTLocationBeaconBulkUpdater` class. Contrary to the `ESTBulkUpdater` it is not designed to be used as a singleton. `ESTLocationBeaconBulkUpdater` requires an array of of `ESTLocationBeaconBulkUpdaterConfiguration` objects to start. `ESTLocationBeaconBulkUpdaterConfiguration` consists of an identifier of the device which settings you want to modify and an array of `ESTSettingOperation` described in the **Advanced API** section. All bulk updater events will be delivered to the object assigned as it's delegate which should conform to `ESTLocationBeaconBulkUpdaterDelegate` protocol.

**Usage example**

I have an array of identifiers for my Location Beacons that should have their iBeacon packet on and major value set to 200.
```objective-c
NSMutableArray *bulkUpdateConfigurations = [NSMutableArray new];

NSArray *identifiers = @[@"identifier1", @"identifier2", @"identifier3"];
for (NSString *identifier in identifiers) {

    ESTSettingIBeaconEnable *enableSetting = [[ESTSettingIBeaconEnable alloc] initWithValue:YES];
    ESTBeaconOperationIBeaconEnable *enableOperation = [ESTBeaconOperationIBeaconEnable writeOperationWithSetting:enableSetting completion:^(ESTSettingIBeaconEnable *iBeaconEnableSetting, NSError *error) {
    }];

    unsigned short major = 200;
    ESTSettingIBeaconMajor *majorSetting = [[ESTSettingIBeaconMajor alloc] initWithValue:major];
    ESTBeaconOperationIBeaconMajor *majorOperation = [ESTBeaconOperationIBeaconMajor writeOperationWithSetting:majorSetting completion:^(ESTSettingIBeaconMajor *major, NSError *error) {
    }];

    ESTLocationBeaconBulkUpdateConfiguration *configuration = [[ESTLocationBeaconBulkUpdateConfiguration alloc] initWithDeviceIdentifier:identifier settingsOperations:@[enableOperation, majorOperation]];
    [bulkUpdateConfigurations addObject:configuration];
}

[self.bulkUpdater startWithUpdateConfigurations:[NSArray arrayWithArray:bulkUpdateConfigurations]];
```

## Changelog

To see what has changed in recent versions of Estimote SDK, see the [CHANGELOG](CHANGELOG.md).
