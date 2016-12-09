//
//  ChangeEmojiVC.swift
//  EmojiAdvertiser
//
//  Created by Przemyslaw Blasiak on 08/12/2016.
//  Copyright © 2016 Estimote. All rights reserved.
//

import UIKit

class ChangeEmojiVC: UIViewController {
    
    // MARK: - Properties
    
    var currentState: ChangeEmojiVC.ScreenState = .noEmojiSelected {
        didSet {
            self.updateUIForCurrentState()
        }
    }
    var selectedEmoji: String? {
        didSet {
            // TODO: Selecting an Emoji
        }
    }
    
    // MARK: - Outlets
    
    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var selectableEmojiLabels: [UILabel]!
    @IBOutlet var savingSpinner: UIActivityIndicatorView!
    @IBOutlet var saveEmojiButton: ESTButton!
    
    // MARK: - Actions

    @IBAction func saveEmojiTapped(_ sender: Any) {
    }
    
    // MARK: - Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.setupAppearance()
    }
    
    // MARK: - Appearance
    
    func setupAppearance() {
        self.view.backgroundColor = ESTStyleSheet.mintCocktailBackgroundColor()
        self.saveEmojiButton.setTitle("", for: UIControlState.disabled)
        
        // Dim all Emojis (if it's not a selected one)
        for emojiLabel in self.selectableEmojiLabels {
            if emojiLabel.text != self.selectedEmoji {
                emojiLabel.alpha = 0.25
            }
        }
        
        self.updateUIForCurrentState()
    }
    
    func updateUIForCurrentState() {
        switch self.currentState {
        
        case .noEmojiSelected:
            self.descriptionLabel.text = "Select an Emoji"
            self.savingSpinner.isHidden = true
            
            // Save Emoji button
            self.saveEmojiButton.isHidden = true
        
        case .saveEmoji:
            self.descriptionLabel.text = "Select an Emoji"
            self.savingSpinner.isHidden = true
            
            // Save Emoji button
            self.saveEmojiButton.isEnabled = true
            self.saveEmojiButton.isHidden = false
        
        case .savingInProgress:
            self.descriptionLabel.text = "Saving Emoji..."
            self.savingSpinner.isHidden = false
            
            // Save Emoji button
            self.saveEmojiButton.isEnabled = false
            self.saveEmojiButton.isHidden = false
        }
    }
}

extension ChangeEmojiVC {
    
    enum ScreenState {
        case noEmojiSelected, saveEmoji, savingInProgress
    }
    
}

