//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit.UIImageView

/// AvatarImageView - used in CustomerViewController & CustomerCell
class AvatarImageView: UIImageView {
  
  override func awakeFromNib() {
    clipsToBounds = true
  }
  
  override var layer: CALayer {
    get {
      let _layer = super.layer
      _layer.cornerRadius = frame.width / 2
      _layer.borderWidth = 1
      _layer.borderColor = UIColor.clear.cgColor
      
      return _layer
    }
  }
}
