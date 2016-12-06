//
//  ViewController.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 12/5/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

  var scanner: Scanner!
  
  override func viewDidLoad() {
    super.viewDidLoad()
   
    let data   = "😎".data(using: .utf8)
    let packet = Packet.init(data: data!)
    
    scanner = Scanner.init(packet: packet)
    scanner.operator.packet.📦 = "🤗".data(using: .utf8)!
  }
}

