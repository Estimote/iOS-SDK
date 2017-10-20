//
// Please report any problems with this app template to contact@estimote.com
//

struct ErrorHandler {
  
  static func displayError(_ title: String?, subtitle: String?, viewController: UIViewController) {
    
    let alertController = UIAlertController(title: title, message: subtitle, preferredStyle: .alert)
    
    let okAction = UIAlertAction(title: "Ok 🐣", style: .default, handler: nil)
    alertController.addAction(okAction)
    
    viewController.present(alertController, animated: true, completion: nil)
  }
}
