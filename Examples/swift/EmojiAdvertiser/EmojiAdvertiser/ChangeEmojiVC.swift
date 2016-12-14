//
//  Copyright © 2016 Estimote. All rights reserved.
//

import UIKit

class ChangeEmojiVC: UIViewController {
    
    // MARK: - Properties
    
    fileprivate lazy var deviceManager: ESTDeviceManager = {
        let manager = ESTDeviceManager()
        manager.delegate = self
        return manager
    }()
    fileprivate var emojiOperator: Operator?
    fileprivate var nearestDevice: ESTDeviceLocationBeacon?
    fileprivate var discoveryAttemptCounter: Int = 0
    
    var currentState: ChangeEmojiVC.ScreenState = .connectingToDevice {
        didSet {
            self.updateUIForCurrentState()
        }
    }
   
    var selectedEmoji: String? {
        didSet {
             self.updateEmojiSelection()
        }
    }
    var initialEmoji: String?
    
    // MARK: - Outlets
    
    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var selectableEmojiLabels: [UILabel]!
    @IBOutlet var savingSpinner: UIActivityIndicatorView!
    @IBOutlet var saveEmojiButton: ESTButton!
    
    // MARK: - Actions

    @IBAction func saveEmojiTapped(_ sender: Any) {
        self.currentState = .savingInProgress
        self.updateEmoji()
    }
    
    // MARK: - Update
    
    func updateEmoji() {
        if self.selectedEmoji != nil && self.nearestDevice != nil {
            let data = self.selectedEmoji!.data(using: String.Encoding.utf8)!
            let packet = Packet(data: data)
            self.emojiOperator = Operator(packet: packet)
            
            self.emojiOperator!.configurePacketFor(self.nearestDevice!, onComplete: { (device) in
                self.nearestDevice!.disconnect()
                self.finishUpdate()
            })
        }
    }
    
    func finishUpdate() {
        _ = self.navigationController?.popViewController(animated: true)
    }
    
    // MARK: - Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
    
        for emojiLabel in self.selectableEmojiLabels {
            emojiLabel.addGestureRecognizer(UITapGestureRecognizer(target: self, action: #selector(emojiTapped)))
            if self.initialEmoji == emojiLabel.text {
                self.selectedEmoji = self.initialEmoji
            }
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.setupAppearance()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        self.deviceManager.startDeviceDiscovery(with: ESTDeviceFilterLocationBeacon())
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        self.deviceManager.stopDeviceDiscovery()
        self.nearestDevice?.disconnect()
    }
    
    // MARK: - Appearance
    
    func setupAppearance() {
        self.view.backgroundColor = ESTStyleSheet.mintCocktailBackgroundColor()
        self.updateUIForCurrentState()
    }
    
    func updateUIForCurrentState() {
        switch self.currentState {
        
        case .connectingToDevice:
            self.view.isUserInteractionEnabled = false
            self.navigationItem.hidesBackButton = false
            
            self.descriptionLabel.text = "Connecting to the beacon..."
            self.savingSpinner.isHidden = false
            
            // Save Emoji button
            self.saveEmojiButton.isHidden = true
            
        case .initialEmojiSelected:
            self.view.isUserInteractionEnabled = true
            self.navigationItem.hidesBackButton = false
            
            self.descriptionLabel.text = "Select an Emoji"
            self.savingSpinner.isHidden = true
            
            // Save Emoji button
            self.saveEmojiButton.isHidden = true
            
        case .saveEmoji:
            self.view.isUserInteractionEnabled = true
            self.navigationItem.hidesBackButton = false
            
            self.descriptionLabel.text = "Select an Emoji"
            self.savingSpinner.isHidden = true
            
            // Save Emoji button
            self.saveEmojiButton.isEnabled = true
            self.saveEmojiButton.isHidden = false
        
        case .savingInProgress:
            self.view.isUserInteractionEnabled = false
            self.navigationItem.hidesBackButton = true
            
            self.descriptionLabel.text = "Saving Emoji..."
            self.savingSpinner.isHidden = false
            
            // Save Emoji button
            self.saveEmojiButton.isHidden = true
        }
        
        self.updateEmojiSelection()
    }
    
    // MARK: - Emoji selection
    
    func updateEmojiSelection()
    {
        for emojiLabel in self.selectableEmojiLabels {
            if emojiLabel.text == self.selectedEmoji && self.currentState != .connectingToDevice {
                emojiLabel.alpha = 1
            } else {
                emojiLabel.alpha = 0.25
            }
        }
    }
    
    func emojiTapped(sender: UITapGestureRecognizer){
        let emoji = sender.view as! UILabel
        self.selectedEmoji = emoji.text
        
        if self.selectedEmoji == self.initialEmoji {
            self.currentState = .initialEmojiSelected
        } else {
            self.currentState = .saveEmoji
        }
    }
}

extension ChangeEmojiVC {
    
    enum ScreenState {
        case connectingToDevice, initialEmojiSelected, saveEmoji, savingInProgress
    }
    
}

extension ChangeEmojiVC: ESTDeviceManagerDelegate {
    
    struct Parameter {
        static let maxDiscoveriesAttemptsCount: Int = 3
    }
    
    func deviceManager(_ manager: ESTDeviceManager, didDiscover devices: [ESTDevice]) {
        self.discoveryAttemptCounter += 1
        if self.discoveryAttemptCounter >= Parameter.maxDiscoveriesAttemptsCount {
            self.deviceManager.stopDeviceDiscovery()
            self.discoveryAttemptCounter = 0
            
            if devices.isEmpty { // Still haven't detected any devices
                let alertController = UIAlertController(title: "Couldn't Find Beacons", message: "Put beacons closer to your phone.", preferredStyle: .alert)
                alertController.addAction(UIAlertAction(title: "Retry", style: .cancel, handler: { action in
                    self.deviceManager.startDeviceDiscovery(with: ESTDeviceFilterLocationBeacon())
                }))
                self.present(alertController, animated: true, completion: nil)
            }
            else {
                self.nearestDevice = (devices.first as! ESTDeviceLocationBeacon)
                self.nearestDevice!.delegate = self
                self.nearestDevice!.connect()
                
                print("Connecting ☝️ to  \(self.nearestDevice?.identifier)")
            }
        }
    }
    
    func estDeviceConnectionDidSucceed(_ device: ESTDeviceConnectable) {
        print("Connected 🤘")
        
        self.currentState = .initialEmojiSelected
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didFailConnectionWithError error: Error) {
        let alertController = UIAlertController(title: "Failed to Connect", message: "Your beacons may be too far away or not in a mesh.", preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "Retry", style: .cancel, handler: { action in
            self.deviceManager.startDeviceDiscovery(with: ESTDeviceFilterLocationBeacon())
        }))
        self.present(alertController, animated: true, completion: nil)
        
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

extension ChangeEmojiVC: ESTDeviceConnectableDelegate {}

