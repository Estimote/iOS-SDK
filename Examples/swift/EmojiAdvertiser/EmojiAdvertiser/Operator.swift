//
//  Operator.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 11/24/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

struct Operator {
    
    var packet: Packet
    
    init(packet: Packet) {
        self.packet = packet
    }
    
    func configurePacketFor(_ device: ESTDeviceLocationBeacon, onComplete: @escaping (ESTDeviceLocationBeacon) -> ()) {
        
        let toOperate: [ESTBeaconOperationProtocol.Type] = [
            ESTBeaconOperationGenericAdvertiserEnable.self,
            ESTBeaconOperationGenericAdvertiserInterval.self,
            ESTBeaconOperationGenericAdvertiserPower.self,
            ESTBeaconOperationGenericAdvertiserData.self
        ]
        
        guard let toPerform = self.performPacketOperations(operations: toOperate, packet: packet) else { return }
        
        print("Operations to perform 😷:\n", toPerform)
        
        device.settings?.performOperations(from: toPerform) { error in
            DispatchQueue.main.async {
                guard error == nil else { print("Could not operate 😔, reason:\n",error ?? "error"); NSException(name: NSExceptionName("GG"), reason: "nore", userInfo: nil).raise(); return }
                
                print("All operations complete! - advertising sexy emojis 💋❤️")
                
                let meshHelper = ESTMeshNetworkHelper()
                meshHelper.incrementMeshSettingVersion(forDevice: device) { error in
                    // TODO: Handle errors
                    onComplete(device)
                }
            }
        }
    }
    
    func performPacketOperations(operations: [ESTBeaconOperationProtocol.Type], packet: Packet) -> [ESTBeaconOperationProtocol]? {
        var ranOperations = [ESTBeaconOperationProtocol]()
        
        operations.forEach { operation in
            switch operation {
                
            // enable
            case is ESTBeaconOperationGenericAdvertiserEnable.Type:
                ranOperations.append(
                    ESTBeaconOperationGenericAdvertiserEnable.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserEnable(value: true)) { operation, error in
                        guard error == nil else { print("\nEMERGENCY 🚑!\n\n", error ?? "error", "\n"); return }
                        
                        print("1️⃣ ", operation?.description ?? "OperationGenericAdvertiserEnable", " init complete")
                })
                
            // interval
            case is ESTBeaconOperationGenericAdvertiserInterval.Type:
                ranOperations.append(
                    ESTBeaconOperationGenericAdvertiserInterval.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserInterval(value: packet.interval)) { operation, error in
                        guard error == nil else { print("\nEMERGENCY 🚑!\n\n", error ?? "error", "\n"); return }
                        print("2️⃣ ", operation?.description ?? "OperationGenericAdvertiserInterval", " init complete")
                })
                
            // power
            case is ESTBeaconOperationGenericAdvertiserPower.Type:
                ranOperations.append(
                    ESTBeaconOperationGenericAdvertiserPower.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserPower(value: .level6)) { operation, error in
                        guard error == nil else { print("\nEMERGENCY 🚑!\n\n", error ?? "error", "\n"); return }
                        
                        print("3️⃣ ", operation?.description ?? "OperationGenericAdvertiserPower", " init complete")
                })
                
            // payload
            case is ESTBeaconOperationGenericAdvertiserData.Type:
                ranOperations.append(
                    ESTBeaconOperationGenericAdvertiserData.writeOperation(forAdvertiser: .ID0, setting: ESTSettingGenericAdvertiserData(value: packet.📦)) { operation, error in
                        guard error == nil else { print("\nEMERGENCY 🚑!\n\n", error ?? "error", "\n"); return }
                        
                        print("4️⃣ ", operation?.description ?? "OperationGenericAdvertiserData", " init complete")
                })
                
            default:
                break
            }
        }
        
        return ranOperations
    }
}
