//
//  EmojiScanner.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 11/24/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

protocol EmojiScannerDelegate {
    
    func emojiScanner(_ scanner: EmojiScanner, didUpdateNearestEmoji emoji: String?);
    func emojiScanner(_ scanner: EmojiScanner, didFailWithError error: Error?);
    
}

class EmojiScanner: NSObject {
    
    fileprivate var centralManager: CBCentralManager!
    fileprivate var emojiMeasurements: [(emoji: String, rssi: Int)] = []
    fileprivate let services: [CBUUID] = [CBUUID(string: "0xABBA")] // 🎤
    
    var delegate: EmojiScannerDelegate?
    var nearestEmoji: String? = nil {
        didSet {
            print("Updated Emoji ~ \(self.nearestEmoji)")
            self.delegate?.emojiScanner(self, didUpdateNearestEmoji: self.nearestEmoji)
        }
    }
    
    override init() {
        super.init()
        self.centralManager = CBCentralManager(delegate: nil, queue: nil, options: [CBCentralManagerScanOptionAllowDuplicatesKey: true])
    }
    
    func start() {
        self.centralManager.delegate = self
    }
    
    func stop() {
        self.centralManager.delegate = nil
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
            if let emoji = String(data: advData, encoding: .utf8) // TODO: What do we do otherwise?
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
        
        // TODO: Set nil and clear the measurements array if haven't found anything in e.g. 5 seconds
        
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
