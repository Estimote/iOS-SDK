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
    var currentState: ScreenState = .blank {
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
        
        self.updateUIForCurrentState()

        let data   = "👊".data(using: .utf8)
        let packet = Packet.init(data: data!)

        scanner = Scanner.init(packet: packet)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        self.view.backgroundColor = ESTStyleSheet.mintCocktailBackgroundColor()
    }
    
    // MARK: - Screen states
    
    func updateUIForCurrentState() {
        switch self.currentState {
        case .blank:
            self.emojiLabel.text = "🤔"
            self.descriptionLabel.text = "No Emojis around"
        case .nearestEmoji:
            self.emojiLabel.text = "🚀"
            self.descriptionLabel.text = "Nearest Emoji"
        }
    }
}

extension NearestEmojiVC {
    
    enum ScreenState {
        case blank, nearestEmoji
    }
    
}

