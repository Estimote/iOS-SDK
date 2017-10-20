//
// Please report any problems with this app template to contact@estimote.com
//

struct AlertHelper {
  static func displayValidationAlert(_ title: String?, subtitle: String?, viewController: UIViewController, handlerAction: ((UIAlertAction) -> ())?) {
    let alertController = UIAlertController.init(title: title, message: subtitle, preferredStyle: .alert)
    
    let alertActionNO  = UIAlertAction.init(title: "❌", style: .default, handler: nil)
    let alertActionYES = UIAlertAction.init(title: "✅", style: .default, handler: handlerAction)
    
    alertController.addAction(alertActionNO)
    alertController.addAction(alertActionYES)
    
    viewController.present(alertController, animated: true, completion: nil)
  }
}
