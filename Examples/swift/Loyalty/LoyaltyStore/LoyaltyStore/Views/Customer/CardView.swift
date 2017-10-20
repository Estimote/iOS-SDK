//
// Please report any problems with this app template to contact@estimote.com
//

class CardView: UIView {
  
  override var layer: CALayer {
    get {
      let _layer = super.layer
      
      _layer.masksToBounds = true
      _layer.cornerRadius  = 5
      
      _layer.shadowColor   = UIColor.black.cgColor
      _layer.shadowOffset  = CGSize(width: 0, height: 0)
      _layer.shadowRadius  = 3.0
      _layer.shadowOpacity = 0.2
      
      let shadowPath = UIBezierPath(roundedRect: self.bounds, cornerRadius: _layer.cornerRadius).cgPath
      
      _layer.shadowPath = shadowPath
      
      return _layer
    }
  }
  
  @objc func shadowVisible() {
    layer.masksToBounds = false
  }
  
  @objc func shadowHidden() {
    layer.masksToBounds = true
  }
}
