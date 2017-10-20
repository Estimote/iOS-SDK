//
// Please report any problems with this app template to contact@estimote.com
//
struct AvatarCropp {

  internal static func cropp(_ image: UIImage) -> UIImage {
    var size    : CGFloat = 0
    var yOffset : CGFloat = 0
    var xOffset : CGFloat = 0
    
    if (image.size.height > image.size.width) {
      size    = image.size.width
      yOffset = size / 2
    } else {
      size    = image.size.height
      xOffset = size / 2
    }
    
    let rekt = CGRect.init(x      : xOffset,
                           y      : yOffset,
                           width  : size,
                           height : size) // we want a rectangular avatar

    let imageRef : CGImage = image.cgImage!.cropping(to: rekt)!
    let cropped  : UIImage    = UIImage(cgImage: imageRef)

    return cropped
  }
}

// extend Int implementation to get a CGFloat
extension Int {
  var _CGFloat: CGFloat {
    get {
      return CGFloat(self)
    }
  }
}
