//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class OfferCell: UITableViewCell {
  
  @IBOutlet weak var backgroundRectangleView  : UIView!
  @IBOutlet weak var offerImageView           : UIImageView!
  @IBOutlet weak var offerNameLabel           : UILabel!
  @IBOutlet weak var offerDescriptionTextView : UITextView!
  @IBOutlet weak var offerStarsCountLabel     : UILabel!
  @IBOutlet weak var offerExtraInfoLabel      : UILabel!
  
  override func awakeFromNib() {
    super.awakeFromNib()
    
    // stylize cell
    self.stylizeCell()
  }
  
  @objc func stylizeCell() {
    let clearColor = UIColor.clear
    
    // set default selection style to None
    selectionStyle = .none
    
    // set background colors
    contentView.backgroundColor     = clearColor
    backgroundView?.backgroundColor = clearColor
    backgroundColor                 = clearColor
    
    // set corner radius, shadow, background color
    self.backgroundRectangleView.layer.cornerRadius  = 4.0
    self.backgroundRectangleView.layer.shadowRadius  = 2.0
    self.backgroundRectangleView.layer.shadowOpacity = 0.7
    self.backgroundRectangleView.layer.shadowOffset  = CGSize(width: 0.0, height: 0.0)
    self.backgroundRectangleView.layer.shadowColor   = UIColor.gray.withAlphaComponent(0.5).cgColor
    self.backgroundRectangleView.backgroundColor     = UIColor.white
  }
  
  override func layoutIfNeeded() {
    super.layoutIfNeeded()
    
    offerImageView.layer.cornerRadius = offerImageView.frame.size.width/2
  }
  
  override func setSelected(_ selected: Bool, animated: Bool) {
    super.setSelected(selected, animated: animated)
    // Configure the view for the selected state
  }
}
