//
// Please report any problems with this app template to contact@estimote.com
//

@IBDesignable class OfferCell: UICollectionViewCell {
  
  @IBOutlet weak var imageView: UIImageView!
  @IBOutlet weak var nameLabel: UILabel!
  @IBOutlet weak var costLabel: UILabel!
  
  override func setNeedsLayout() {
    
    // stylise cell on awake from nib
    
    self.layer.cornerRadius = 3
    
    self.layer.shadowColor   = UIColor.gray.cgColor
    self.layer.shadowOffset  = CGSize(width: 0, height: 0)
    self.layer.shadowRadius  = 3.0
    self.layer.shadowOpacity = 0.2
    self.layer.masksToBounds = false
    
    let shadowPath = UIBezierPath(roundedRect: self.bounds, cornerRadius: self.layer.cornerRadius).cgPath
    
    self.layer.shadowPath = shadowPath
  }
}
