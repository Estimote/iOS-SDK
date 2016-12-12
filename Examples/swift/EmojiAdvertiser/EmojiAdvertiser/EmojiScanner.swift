//
//  EmojiScanner.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 11/24/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

let meshedDeviceIdentifiers = [ // TODO: Prepare as template parameters
    "584daef4c210261eb66c8ccfe4e9d505",
    "9d6568ac02799236af43f4f2329b4333",
    "ebf8f5d4749319d2e978dab8e1163420"
]

protocol EmojiScannerDelegate {
    
    func emojiScanner(_ scanner: EmojiScanner, didUpdateNearestEmoji emoji: String?);
    func emojiScanner(_ scanner: EmojiScanner, didFailWithError error: Error?);
    
}

class EmojiScanner: NSObject {
    
    fileprivate var deviceManager: ESTDeviceManager!
    fileprivate var centralManager: CBCentralManager!
    fileprivate var 📡: ESTDeviceLocationBeacon!
    fileprivate let services: [CBUUID] = [CBUUID(string: "0xFADE")]
    fileprivate var emojiMeasurements: [(emoji: String, rssi: Int)] = []
    
    var `operator`: Operator!
    var delegate: EmojiScannerDelegate?
    var nearestEmoji: String? = nil {
        didSet {
            print("Updated Emoji ~ \(self.nearestEmoji)")
            self.delegate?.emojiScanner(self, didUpdateNearestEmoji: self.nearestEmoji)
        }
    }
    var nearestEmojiRSSI: Int = -70 // Don't take lower RSSI into consideration, because the connection later on could be unstable
    
    fileprivate var filter: ESTDeviceFilterLocationBeacon {
        return ESTDeviceFilterLocationBeacon.init(identifiers: (meshedDeviceIdentifiers))
    }
    
    override init() {
        super.init()
        
        self.centralManager = CBCentralManager(delegate: nil, queue: nil, options: [CBCentralManagerScanOptionAllowDuplicatesKey: true])
    }
    
    // TODO: Refactor
//    init(packet: Packet) {
//        super.init()
//        
//        self.operator = Operator.init(packet: packet)
//        
//        self.deviceManager = ESTDeviceManager.init()
//        self.centralManager = CBCentralManager.init()
//        
//        self.centralManager.delegate = self
//        self.deviceManager.delegate = self
//    }
    
    fileprivate func scanForConnection(filter: ESTDeviceFilterLocationBeacon) {
        self.deviceManager.startDeviceDiscovery(with: filter)
    }
    
    func start() {
        self.centralManager.delegate = self
    }
    
    func stop() {
        self.centralManager.delegate = nil
    }
}

extension EmojiScanner: ESTDeviceManagerDelegate {
    
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

extension EmojiScanner: ESTDeviceConnectableDelegate { }

extension EmojiScanner: CBCentralManagerDelegate {
    
    struct Parameter {
        static let measurementsCount:Int = 5
        static let minimumRSSI:Int = -70
    }
    
    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        switch central.state {
        case .poweredOff:
            print("🔌");
            self.centralManager.stopScan()
            self.delegate?.emojiScanner(self, didFailWithError: nil) // TODO: Pass error here (Bluetooth off)
            
        case .poweredOn:
            print("🔋");
            self.centralManager.scanForPeripherals(withServices: self.services, options: nil)
            
        case .resetting:
            print("🔁")
            
        case .unauthorized:
            print("👮🏼‍♀️");
            self.centralManager.stopScan()
            self.delegate?.emojiScanner(self, didFailWithError: nil) // TODO: Pass error here
            
        case .unknown:
            print("❓");
            self.centralManager.stopScan()
            self.delegate?.emojiScanner(self, didFailWithError: nil) // TODO: Pass error here
            
        case .unsupported:
            print("🙈");
            self.delegate?.emojiScanner(self, didFailWithError: nil) // TODO: Pass error here
        }
    }
    
    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {
        print("Peripheral discovered 🕵🏽‍♀️")
        
        let rssiValue = RSSI.intValue
        if rssiValue != 127 && rssiValue > Parameter.minimumRSSI {
            
            // Extract an emoji
            let advData = (advertisementData[CBAdvertisementDataServiceDataKey] as! Dictionary<CBUUID, Any>)[services.first!] as! Data
            if let emoji = String.init(data: advData, encoding: .utf8) // TODO: What do we do otherwise?
            {
                // Insert the measurement at right position in the sorted array
                let measurement = (emoji: emoji, rssi: rssiValue)
                self.emojiMeasurements.append(measurement)
            }
        }
        
        // Keep only certain number of measurements
        if self.emojiMeasurements.count > Parameter.measurementsCount {
            self.emojiMeasurements.removeSubrange(0..<(self.emojiMeasurements.count - Parameter.measurementsCount))
        }
        
        // Determine the nearest Emoji (nil if none)
        let nearest = self.emojiMeasurements.max(by: { (measurement1, measurement2) -> Bool in
            measurement2.rssi > measurement1.rssi
        })
        self.nearestEmoji = nearest?.emoji
        
        // Remove out-of-range devices
        print("Emoji measurements: \(self.emojiMeasurements)")
        print("Nearest: \(nearest)")
    }
    
    func centralManager(_ central: CBCentralManager, didDisconnectPeripheral peripheral: CBPeripheral, error: Error?) {
        print("Disconnected 🛰")
    }
    
    func deviceManagerDidFailDiscovery(_ manager: ESTDeviceManager) {
        print("Failed discovery 🤔")
    }
}
