//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class ShadowlessNavigationBar: UINavigationBar {
  
  override func awakeFromNib() {
    shadowImage = UIImage()
    setBackgroundImage(UIImage(), for: .default)
  }
}
