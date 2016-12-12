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
    
    var scanner: EmojiScanner!
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

        self.scanner = EmojiScanner()
        self.scanner.delegate = self
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

