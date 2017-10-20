//
// Please report any problems with this app template to contact@estimote.com
//

class HorizontalPushSegue: UIStoryboardSegue {
  
  override func perform() {
    let src = self.source
    let dst = self.destination
    
    src.view.superview?.insertSubview(dst.view, aboveSubview: src.view)
    dst.view.transform = CGAffineTransform(translationX: src.view.frame.size.width, y: 0)
    
    UIView.animate(withDuration: 0.25, delay: 0.0, options: UIViewAnimationOptions(),
      animations: {
        // animate source to "push" to left
        src.view.transform = CGAffineTransform(translationX: -dst.view.frame.size.width, y: 0)
        // animate destination to "push" from right
        dst.view.transform = CGAffineTransform(translationX: 0, y: 0)
      }, completion: { finished in
        // and present
        src.present(dst, animated: false, completion: nil)
      })
  }
}
