//
//  GenericiBeacon.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 11/24/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

fileprivate let CBUUIDBytes: [UInt8] = [0xDE, 0xFA]

class Packet {
  private var MAC : Data {
    let buf = [Int.randUInt8, Int.randUInt8, Int.randUInt8, Int.randUInt8, Int.randUInt8, Int.randUInt8]
    var data = Data.init(bytes: buf)
    data[5] |= 0xc0
    
    return data
  }
  
  var 📦       : Data = Data.init()
  var power    : ESTGenericAdvertiserPowerLevel
  var interval : UInt16
  
  init(data: Data, interval: UInt16? = 200, power: ESTGenericAdvertiserPowerLevel? = .level6) {
    self.power    = power!
    self.interval = interval!
    self.📦       = packetWith(data: data)!
  }
  
  private func packetWith(data: Data) -> Data? {
    guard data.count <= 20 else {
      print("\nYour data is YUUUUGE! \(data.count) 😵 \nTry \(data.count - 20) less bytes 😉\n")
      return nil
    }
    
    let dataSize   = UInt8(data.count)
    let packetSize = UInt8(dataSize + 17)
    
    let mac              = MAC
    let header           = Data.init(bytes: [0x42, packetSize, 0x00])
    let unsupportedBREDR = Data.init(bytes: [0x02, 0x01, 0x06])
    let UUID             = Data.init(bytes: [0x03, 0x03, CBUUIDBytes[0], CBUUIDBytes[1]])
    var serviceData      = Data.init(bytes: [dataSize + 3, 0x16, CBUUIDBytes[0], CBUUIDBytes[1]])
    
    // append our data 😋
    serviceData.append(data)
    
    let packet = header + mac + unsupportedBREDR + UUID + serviceData
    
    return packet
  }
}

extension Int {
  static var randUInt8: UInt8 {
    return UInt8(arc4random_uniform(UInt32(UInt8.max)))
  }
}
