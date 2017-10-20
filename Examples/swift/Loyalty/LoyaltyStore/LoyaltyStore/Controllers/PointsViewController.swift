//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class PointsViewController: UIViewController {
  
  var customer: Customer!
  var delegate: SelectedCustomerDelegate!
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    self.addSelectedCustomerObserver()
  }
  
  @objc func addSelectedCustomerObserver() {
    let notificationCenter = NotificationCenter.default
    notificationCenter.addObserver(self, selector: #selector(setNewlySelectedCustomer), name: NSNotification.Name(rawValue: "customer selected"), object: nil)
  }
  
  @objc func setNewlySelectedCustomer(_ notification: Notification) {
    guard let newCustomer = notification.object as? Customer else {
      if notification.object == nil {
        self.customer = nil
      }
      
      return
    }
    
    self.customer = newCustomer
  }
    
    func addPointsForCustomer(points: Int) {
        
        if (self.customer) != nil {
            AlertHelper.displayValidationAlert("Add \(emojiPoints[5]!)⭐️ to '\(self.customer.name!)'?", subtitle: nil, viewController: self) { _ in
                self.customer.addPoints(points)
            }
        } else {
            let noCustomerPopup = UIAlertController(title: "Detected customers", message: "Unfortunately, there are no customers nearby 😥", preferredStyle: UIAlertControllerStyle.alert)
            let understandAction = UIAlertAction(title: "Sure", style: UIAlertActionStyle.default, handler: nil)
            noCustomerPopup.addAction(understandAction)
            self.present(noCustomerPopup, animated: true, completion: nil)
        }
    }
  
  @IBAction func addFivePoints(_ sender: AnyObject) {
        addPointsForCustomer(points: 5)
    }
  
  @IBAction func addTenPoints(_ sender: AnyObject) {
    addPointsForCustomer(points: 10)
  }
  
  @IBAction func addTwentyPoints(_ sender: AnyObject) {
        addPointsForCustomer(points: 20)
  }
  
  
  @IBAction func addFiftyPoints(_ sender: AnyObject) {
        addPointsForCustomer(points: 50)
  }
}

