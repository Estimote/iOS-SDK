//
//  NearestEmojiVC.swift
//  EmojiAdvertiser
//
//  Created by @ferologics on 12/5/16.
//  Copyright © 2016 Estimote. All rights reserved.
//

import UIKit

class NearestEmojiVC: UIViewController {

    // MARK: - Properties
    
    var scanner: Scanner!
    var currentState: NearestEmojiVC.ScreenState = .noBeaconsFound {
        didSet {
            self.updateUIForCurrentState()
        }
    }
    
    // MARK: - Outlets

    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var emojiLabel: UILabel!
    
    // MARK: - Actions
    
    @IBAction func changeEmojiTapped(_ sender: Any) {
        self.performSegue(withIdentifier: Segue.nearestEmoji👉🏻changeEmoji, sender: self)
    }
    
    // MARK: - Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()

        let data   = "👊".data(using: .utf8)
        let packet = Packet.init(data: data!)

        self.scanner = Scanner.init(packet: packet)
        self.scanner.delegate = self
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        self.updateUIForCurrentState()
        self.view.backgroundColor = ESTStyleSheet.mintCocktailBackgroundColor()
    }
    
    // MARK: - Screen states
    
    func updateUIForCurrentState() {
        switch self.currentState {
        case .noBeaconsFound:
            self.emojiLabel.text = "🕵️"
            self.descriptionLabel.text = "Can't see meshed beacons around"
        case .noEmoji:
            self.emojiLabel.text = "❓"
            self.descriptionLabel.text = "Nearest beacon has no Emoji yet"
        case .nearestEmoji:
            self.emojiLabel.text = self.scanner.nearestEmoji
            self.descriptionLabel.text = "Nearest Emoji"
        }
    }
    
    // MARK: - Navigation
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        self.scanner.delegate = nil
        
        if segue.identifier == Segue.nearestEmoji👉🏻changeEmoji {
            let changeEmojiVC = segue.destination as! ChangeEmojiVC
            changeEmojiVC.selectedEmoji = self.emojiLabel.text
        }
    }
    
}

extension NearestEmojiVC {
    
    enum ScreenState {
        case noBeaconsFound, noEmoji, nearestEmoji
    }
    
}

extension NearestEmojiVC: ScannerDelegate {
    
    func scanner(_ scanner: Scanner, didUpdateNearestEmoji emoji: String?) {
        if emoji == nil {
            self.currentState = .noEmoji
        }
        else {
            self.currentState = .nearestEmoji
        }
    }
    
    func scannerDidPowerOn(_ scanner: Scanner) {
        self.scanner.scanForBeacons(services: [CBUUID(string: "0xFADE")])
    }
    
    func scanner(_ scanner: Scanner, didFailToPowerOnWithError: NSError?) {
        
    }
    
    func scannerDidPowerOff(_ scanner: Scanner) {
        
    }
    
}

