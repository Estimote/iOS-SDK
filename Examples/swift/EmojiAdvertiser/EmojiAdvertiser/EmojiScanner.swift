//
//  Copyright © 2016 Estimote. All rights reserved.
//

protocol EmojiScannerDelegate {
    
    func emojiScanner(_ scanner: EmojiScanner, didUpdateNearestEmoji emoji: String?);
    func emojiScanner(_ scanner: EmojiScanner, didFailWithError error: Error?);
    
}

class EmojiScanner: NSObject {
    
    struct Parameter {
        static let measurementsCount:Int = 5
        static let minimumRSSI:Int = -70
        static let outOfRangeTimeout: TimeInterval = 10
    }
    
    fileprivate var centralManager: CBCentralManager!
    fileprivate var emojiMeasurements: [(emoji: String, rssi: Int)] = []
    fileprivate let services: [CBUUID] = [CBUUID(string: "0xABBA")] // 🎤
    fileprivate var outOfRangeTimer: Timer? = nil
    
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
    
    fileprivate func restartOutOfRangeTimer() {
        self.outOfRangeTimer?.invalidate()
        self.outOfRangeTimer = Timer.scheduledTimer(timeInterval: Parameter.outOfRangeTimeout, target: self, selector: #selector(EmojiScanner.wentOutOfRange), userInfo: nil, repeats: false)
    }
    
    @objc fileprivate func wentOutOfRange() {
        print("Went out of range 🙉 of beacons")
        self.nearestEmoji = nil
    }
}

extension EmojiScanner: ESTDeviceConnectableDelegate { }

extension EmojiScanner: CBCentralManagerDelegate {
    
    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        switch central.state {
        case .poweredOff:
            print("🔌");
            self.centralManager.stopScan()
            let error = NSError(domain: EmojiScannerError.domain, code: EmojiScannerError.bluetoothOff.code, userInfo: [NSLocalizedDescriptionKey: EmojiScannerError.bluetoothOff.description])
            self.delegate?.emojiScanner(self, didFailWithError: error)

        case .poweredOn:
            print("🔋");
            self.centralManager.scanForPeripherals(withServices: self.services, options: nil)
            
        case .resetting:
            print("🔁")
            
        case .unauthorized:
            print("👮🏼‍♀️");
            self.centralManager.stopScan()
            let error = NSError(domain: EmojiScannerError.domain, code: EmojiScannerError.unauthorized.code, userInfo: [NSLocalizedDescriptionKey: EmojiScannerError.unauthorized.description])
            self.delegate?.emojiScanner(self, didFailWithError: error)
            
        case .unknown:
            print("❓");
            self.centralManager.stopScan()
            let error = NSError(domain: EmojiScannerError.domain, code: EmojiScannerError.unknown.code, userInfo: [NSLocalizedDescriptionKey: EmojiScannerError.unknown.description])
            self.delegate?.emojiScanner(self, didFailWithError: error)
            
        case .unsupported:
            print("🙈");
            let error = NSError(domain: EmojiScannerError.domain, code: EmojiScannerError.unsupported.code, userInfo: [NSLocalizedDescriptionKey: EmojiScannerError.unsupported.description])
            self.delegate?.emojiScanner(self, didFailWithError: error)        }
    }
    
    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {
        print("Peripheral discovered 🕵🏽‍♀️")
        
        self.restartOutOfRangeTimer()
        
        let rssiValue = RSSI.intValue
        if rssiValue != 127 && rssiValue > Parameter.minimumRSSI {
            
            // Extract an emoji
            let advData = (advertisementData[CBAdvertisementDataServiceDataKey] as! Dictionary<CBUUID, Any>)[services.first!] as! Data
            if let emoji = String(data: advData, encoding: .utf8)
            {
                // Insert the measurement at right position in the sorted array
                let measurement = (emoji: emoji, rssi: rssiValue)
                self.emojiMeasurements.append(measurement)
            }
            else {
                print("Couldn't read Emoji 😞")
                return
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

extension EmojiScanner {
    
    enum EmojiScannerError: Int, Error, CustomStringConvertible {
        
        case bluetoothOff, unauthorized, unknown, unsupported
        
        var description: String {
            switch self {
            case .bluetoothOff: return "Turn Bluetooth on 💙"
            case .unauthorized: return "The application is not authorized to use the Bluetooth Low Energy role ⛔️"
            case .unknown: return "State unknown, update imminent ❓"
            case .unsupported: return "The platform doesn't support the Bluetooth Low Energy Central/Client role 📵"
            }
        }
        
        var code: Int { self.rawValue }
        
        static let domain = "EmojiScannerErrorDomain"
    }
    
}
