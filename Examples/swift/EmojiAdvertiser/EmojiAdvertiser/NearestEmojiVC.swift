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
    
    lazy var scanner: EmojiScanner = {
        let scanner = EmojiScanner()
        scanner.delegate = self
        return scanner
    }()
    var currentState: NearestEmojiVC.ScreenState = .noBeaconsFound {
        didSet {
            self.updateUIForCurrentState()
        }
    }
    
    // MARK: - Outlets

    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var emojiLabel: UILabel!
    @IBOutlet weak var changeEmojiButton: ESTButton!
    
    // MARK: - Actions
    
    @IBAction func changeEmojiTapped(_ sender: Any) {
        self.performSegue(withIdentifier: Segue.nearestEmoji👉🏻changeEmoji, sender: self)
    }
    
    // MARK: - Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        self.updateUIForCurrentState()
        self.view.backgroundColor = ESTStyleSheet.mintCocktailBackgroundColor()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        self.scanner.start()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        self.scanner.stop()
    }
    
    // MARK: - Screen states
    
    func updateUIForCurrentState() {
        switch self.currentState {
        case .noBeaconsFound:
            self.emojiLabel.text = "🕵️"
            self.descriptionLabel.text = "Looking for meshed beacons"
            self.changeEmojiButton.isHidden = true
        case .noEmoji:
            self.emojiLabel.text = "❓"
            self.descriptionLabel.text = "Nearest beacon has no Emoji yet"
            self.changeEmojiButton.isHidden = false
        case .nearestEmoji:
            self.emojiLabel.text = self.scanner.nearestEmoji
            self.descriptionLabel.text = "Nearest Emoji"
            self.changeEmojiButton.isHidden = false
        }
    }
    
    // MARK: - Navigation
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == Segue.nearestEmoji👉🏻changeEmoji {
            let changeEmojiVC = segue.destination as! ChangeEmojiVC
            changeEmojiVC.initialEmoji = self.emojiLabel.text
        }
    }
    
}

extension NearestEmojiVC {
    
    enum ScreenState {
        case noBeaconsFound, noEmoji, nearestEmoji
    }
    
}

extension NearestEmojiVC: EmojiScannerDelegate {
    
    func emojiScanner(_ scanner: EmojiScanner, didUpdateNearestEmoji emoji: String?) {
        if emoji != nil {
            self.currentState = .nearestEmoji
        }
        else {
            self.currentState = .noBeaconsFound
        }
    }
    
    func emojiScanner(_ scanner: EmojiScanner, didFailWithError error: Error?) {
        self.scanner.stop()
        let alertController = UIAlertController(title: "Emoji Scanning Failed", message: "Turn on bluetooth", preferredStyle: .alert) // TODO: Use error description instead
        alertController.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: { (action) in
                self.scanner.start()
        }))
        self.present(alertController, animated: true, completion: nil)
        return
    }
    
}

