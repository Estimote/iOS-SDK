EstimoteSDK for iOS 7
=======

Overview
-------


Estimote SDK is a wrapper around Apple's CoreLocation framework. It is dedicated for iOS 7 as it's based on newly introduced CoreLocation framework functionality called iBeacon. It consists of 3 classes: ESTBeaconManager, ESTBeaconRegion and ESTBeacon. Each of them is an equivalent of CoreLocation classes (CLLocationManager, CLBeaconRegion, CLBeacon) created in particular for Estimote Beacons Platform.

ESTBeaconManager is a starting point of the library. It can get a list of all Estimote beacon devices (represented by ESTBeacon objects). It exposes monitoring and ranging methods similar to CLLocationManager. In addition to location functionality it can get a list of beacons via CoreBluetooth framework. It is extremely important to have this option in case a device stops advertising in an iBeacon manner.

ESTBeaconRegion directly extends CoreLocation framework class CLBeaconRegion. As Estimote Beacon Platform is using single ProximityUUID, this class helps create a region object faster. You don't need to remember and play with ProximityUUID parameter.

ESTBeacon represents a single beacon device. Objects of this class are generated using ESTBeaconManager. (There is no sense to create them manually.) The most important difference (compared to CLBeacon class) is two way communication with the beacon device. By keeping a reference to the original CLBeacon object it enables connecting and interacting with the device. All available Bluetooth characteristics (like signal power or major/minor value) can be read and changed to create customised behaviour. Firmware update option is available using this class as well. 


Installation
-------

Follow steps described below to install EstimoteSDK library:

1. Copy EstimoteSDK directory (containing libEstimoteSDK7.a and Headers) into your project directory.

2. Open your project settings target and go to Build Phases tab. In the Link library with binaries section click +. In the popup window click add another at the bottom and select libEstimoteSDK7.a library file. 

  In addition EstimoteSDK requires the following native iOS frameworks:
  * CoreBluetooth.framework
  * CoreLocation.framework
  * SystemConfiguration.framework

  After you add them your project settings should look like on the screenshot below.

  ![ScreenShot LinkWithBinaryLibraries](http://estimote.com/api/BuildPhasesScreenshot.png)

3. In project settings go to Build Settings tab. Search for Header Search Paths and add a line containing "$(SRCROOT)/../EstimoteSDK/Headers".

4. Congratulations! You are done.
 
