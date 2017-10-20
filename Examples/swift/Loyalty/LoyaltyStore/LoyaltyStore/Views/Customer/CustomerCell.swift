//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

/// Customer cell used in StoreViewController to display customers
class CustomerCell: UITableViewCell {
  
  @IBOutlet weak var cardView        : CardView!
  @IBOutlet weak var avatarImageView : AvatarImageView!
  @IBOutlet weak var nameLabel       : UILabel!
  @IBOutlet weak var pointsLabel     : UILabel!
  
  override func awakeFromNib() {
    
  }
  
  override func setSelected(_ selected: Bool, animated: Bool) {
    switch selected {
      case true  :
        cardView.backgroundColor = UIColor.white
        cardView.shadowVisible()
        nameLabel.textColor      = UIColor.black
        pointsLabel.textColor    = UIColor.black
      case false :
        cardView.backgroundColor = UIColor.init(red: 148/256, green: 106/256, blue: 207/256, alpha: 1)
        cardView.shadowHidden()
        nameLabel.textColor      = UIColor.white
        pointsLabel.textColor    = UIColor.white
    }
  }
}
