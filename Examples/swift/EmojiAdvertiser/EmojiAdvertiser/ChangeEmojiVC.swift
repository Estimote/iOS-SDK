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
        _ = Timer.scheduledTimer(timeInterval: 3, target: self, selector: #selector(self.updateEmoji), userInfo: nil, repeats: true);
    }
    
    // MARK: - Update
    
    func updateEmoji() {
        // do the magic!
        finishUpdate()
    }
    
    func finishUpdate() {
        navigationController?.popViewController(animated: true)
    }
    
    // MARK: - Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.initialEmoji = self.selectedEmoji
        self.refreshLabelStates()
        for emojiLabel in self.selectableEmojiLabels {
            emojiLabel.addGestureRecognizer(UITapGestureRecognizer(target: self, action: #selector(emojiTapped)))
        }
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
    
    func refreshLabelStates()
    {
        for emojiLabel in self.selectableEmojiLabels {
            if emojiLabel.text == self.selectedEmoji {
                emojiLabel.alpha = 1
            } else {
                emojiLabel.alpha = 0.25
            }
        }
    }
    
    func emojiTapped(sender: UITapGestureRecognizer){
        let emoji = sender.view as! UILabel
        self.selectedEmoji = emoji.text
        self.refreshLabelStates()
        
        if self.selectedEmoji == self.initialEmoji {
            self.currentState = .noEmojiSelected
        } else {
            self.currentState = .saveEmoji
        }
    }
}

extension ChangeEmojiVC {
    
    enum ScreenState {
        case noEmojiSelected, saveEmoji, savingInProgress
    }
    
}

