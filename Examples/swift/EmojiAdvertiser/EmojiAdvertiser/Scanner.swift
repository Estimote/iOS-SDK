//
//  Scanner.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 11/24/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

fileprivate let _CBUUID: CBUUID = CBUUID.init(string: "0xFADE")
fileprivate let identifiers = [ // TODO @ferologics: replace these with your beacon identifiers
    "584daef4c210261eb66c8ccfe4e9d505",
    "9d6568ac02799236af43f4f2329b4333"
]

protocol ScannerDelegate {
    
    func scannerDidPowerOn(_ scanner: Scanner);
    func scannerDidPowerOff(_ scanner: Scanner);
    func scanner(_ scanner: Scanner, didFailToPowerOnWithError: NSError?);
    
    func scanner(_ scanner: Scanner, didUpdateNearestEmoji emoji: String?);
}

class Scanner: NSObject {
    var deviceManager : ESTDeviceManager!
    var beaconManager : CBCentralManager!
    var `operator`    : Operator!
    var 📡            : ESTDeviceLocationBeacon!
    
    var delegate: ScannerDelegate?
    var nearestEmoji: String? = nil {
        didSet {
            self.delegate?.scanner(self, didUpdateNearestEmoji: self.nearestEmoji)
        }
    }
    
    var filter: ESTDeviceFilterLocationBeacon {
        return ESTDeviceFilterLocationBeacon.init(identifiers: (identifiers))
    }
    
    init(packet: Packet) {
        super.init()
        
        self.operator = Operator.init(packet: packet)
        
        self.deviceManager = ESTDeviceManager.init()
        self.beaconManager = CBCentralManager.init()
        
        self.beaconManager.delegate = self
        self.deviceManager.delegate = self
    }
    
    func scanForConnection(filter: ESTDeviceFilterLocationBeacon) {
        self.deviceManager.startDeviceDiscovery(with: filter)
    }
    
    func scanForBeacons(services: [CBUUID]) {
        self.beaconManager.scanForPeripherals(withServices: services, options: nil)
    }
}

extension Scanner: ESTDeviceManagerDelegate {
    
    func deviceManager(_ manager: ESTDeviceManager, didDiscover devices: [ESTDevice]) {
        guard let device = devices.first as? ESTDeviceLocationBeacon else { return }
        self.deviceManager.stopDeviceDiscovery()
        
        print("Discovered 👁 \(device.identifier)")
        
        self.📡 = device
        self.📡.delegate = self
        self.📡.connect()
        
        print("Connecting ☝️ to \(device.identifier)")
    }
    
    func estDeviceConnectionDidSucceed(_ device: ESTDeviceConnectable) {
        print("Connected 🤘")
        
        // configure packet
        self.operator.configurePacketFor(self.📡) { beacon in
            
            // send notification to view controller to stop
            
            // start discovery for remaining devices
            self.deviceManager.startDeviceDiscovery(with: self.filter)
            self.📡.disconnect()
        }
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didFailConnectionWithError error: Error) {
        print("Failed to connect with error 🤔\n\(error)")
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didDisconnectWithError error: Error?) {
        if error != nil {
            print("Disconnected with error 🤔 \n\(error)")
        } else {
            print("Disconnected 🛰")
        }
    }
}

extension Scanner: ESTDeviceConnectableDelegate { }

extension Scanner: CBCentralManagerDelegate {
    
    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        switch central.state {
        case .poweredOff   : print("🔌"); self.delegate?.scannerDidPowerOff(self)
        case .poweredOn    : print("🔋"); self.delegate?.scannerDidPowerOn(self)
        case .resetting    : print("🔁")
        case .unauthorized : print("👮🏼‍♀️"); self.delegate?.scanner(self, didFailToPowerOnWithError: nil) // TODO: Pass error here
        case .unknown      : print("❓"); self.delegate?.scanner(self, didFailToPowerOnWithError: nil) // TODO: Pass error here
        case .unsupported  : print("🙈"); self.delegate?.scanner(self, didFailToPowerOnWithError: nil) // TODO: Pass error here
        }
    }
    
    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {
        print("Peripheral discovered 🕵🏽‍♀️")
        
        let advData = (advertisementData[CBAdvertisementDataServiceDataKey] as! Dictionary<CBUUID, Any>)[_CBUUID] as! Data
        let emoji = String.init(data: advData, encoding: .utf8)
        
        if self.nearestEmoji != emoji {
            self.nearestEmoji = emoji
        }
        
        print("Data ~ \(emoji!)")
    }
    
    func centralManager(_ central: CBCentralManager, didDisconnectPeripheral peripheral: CBPeripheral, error: Error?) {
        print("Disconnected 🛰")
    }
    
    func deviceManagerDidFailDiscovery(_ manager: ESTDeviceManager) {
        print("Failed discovery 🤔")
    }
}
