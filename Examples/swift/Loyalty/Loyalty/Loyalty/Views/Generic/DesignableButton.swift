//
// Please report any problems with this app template to contact@estimote.com
//

@IBDesignable class DesignableButton: UIButton {

  @IBInspectable var borderColor: UIColor = UIColor.clear {
    didSet {
      layer.borderColor = borderColor.cgColor
    }
  }

  @IBInspectable var borderWidth: CGFloat = 0 {
    didSet {
      layer.borderWidth = borderWidth
    }
  }

  @IBInspectable var cornerRadius: CGFloat = 0 {
    didSet {
      layer.cornerRadius = cornerRadius
    }
  }
}
