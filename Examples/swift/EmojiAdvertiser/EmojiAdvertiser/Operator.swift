//
//  Copyright © 2016 Estimote. All rights reserved.
//

struct Operator {
    
    var packet: Packet
    
    init(packet: Packet) {
        self.packet = packet
    }
    
    func configurePacketFor(_ device: ESTDeviceLocationBeacon, completion: @escaping (ESTDeviceLocationBeacon, Error?) -> ()) {
        
        let toOperate: [ESTBeaconOperationProtocol.Type] = [
            ESTBeaconOperationGenericAdvertiserEnable.self,
            ESTBeaconOperationGenericAdvertiserInterval.self,
            ESTBeaconOperationGenericAdvertiserPower.self,
            ESTBeaconOperationGenericAdvertiserData.self
        ]
        
        let packetOperations = self.performPacketOperations(operations: toOperate, packet: self.packet, completion: { (error) in
            if error != nil {
                completion(device, error)
            }
        })
        
        print("Operations to perform 😷:\n", packetOperations)
        
        device.settings?.performOperations(from: packetOperations) { error in
            DispatchQueue.main.async {
                guard error == nil else {
                    completion(device, error)
                    return
                }
                
                let meshHelper = ESTMeshNetworkHelper()
                meshHelper.incrementMeshSettingVersion(forDevice: device) { error in
                    completion(device, error)
                    print("All operations complete! - advertising emojis 🔊")
                }
            }
        }
    }
    
    func performPacketOperations(operations: [ESTBeaconOperationProtocol.Type], packet: Packet, completion: ((Error?) -> Void)?) -> [ESTBeaconOperationProtocol] {
        var ongoingOperations = [ESTBeaconOperationProtocol]()
        
        operations.forEach { operation in
            switch operation {
                
            // enable
            case is ESTBeaconOperationGenericAdvertiserEnable.Type:
                ongoingOperations.append(
                    ESTBeaconOperationGenericAdvertiserEnable.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserEnable(value: true)) { operation, error in
                        print("1️⃣ ", operation?.description ?? "OperationGenericAdvertiserEnable", " finished with error: \(error)")
                        completion?(error)
                })
                
            // interval
            case is ESTBeaconOperationGenericAdvertiserInterval.Type:
                ongoingOperations.append(
                    ESTBeaconOperationGenericAdvertiserInterval.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserInterval(value: packet.interval)) { operation, error in
                        print("2️⃣ ", operation?.description ?? "OperationGenericAdvertiserInterval", " finished with error: \(error)")
                        completion?(error)
                })
                
            // power
            case is ESTBeaconOperationGenericAdvertiserPower.Type:
                ongoingOperations.append(
                    ESTBeaconOperationGenericAdvertiserPower.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserPower(value: .level6)) { operation, error in
                        print("3️⃣ ", operation?.description ?? "OperationGenericAdvertiserPower", " finished with error: \(error)")
                        completion?(error)

                })
                
            // payload
            case is ESTBeaconOperationGenericAdvertiserData.Type:
                ongoingOperations.append(
                    ESTBeaconOperationGenericAdvertiserData.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserData(value: packet.📦)) { operation, error in
                        print("4️⃣ ", operation?.description ?? "OperationGenericAdvertiserData", " finished with error: \(error)")
                        completion?(error)

                })
                
            default:
                break
            }
        }
        
        return ongoingOperations
    }
}
