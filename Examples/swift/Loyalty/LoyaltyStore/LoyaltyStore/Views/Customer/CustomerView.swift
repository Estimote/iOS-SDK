//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit.UIView

/// CustomerView - used in CustomerViewController
class CustomerView: UIView {
  
  @IBOutlet weak var avatarImageView : UIImageView!
  @IBOutlet weak var nameLabel       : UILabel!
  @IBOutlet weak var pointsLabel     : UILabel!
  
  var customer: Customer!
  
  /**
   Initialise customer view and it's outlets with customer
   
   - parameter customer: Customer object
   
   - returns: Initialesed UIView instance
   */
  func initWithCustomer(_ customer: Customer) {
    self.customer = customer
  
    // init outlets with customer
    self.avatarImageView.image = self.customer.avatar
    self.nameLabel.text        = self.customer.name
    self.pointsLabel.text      = self.customer.points?.description
    
    // observe for changes in points
    self.addPointsObserver()
  }
  
  @objc func addPointsObserver() {
    // init notification center
    let notificationCenter = NotificationCenter.default
    let method             = #selector(updatePoints)
    let methodName         = "UpdatePoints"
    
    // add observer
    notificationCenter.addObserver(self, selector: method, name: NSNotification.Name(rawValue: methodName), object: nil)
  }
  
  @objc dynamic fileprivate func updatePoints(_ notification: Notification) {
    self.pointsLabel.text = "\(notification.object!)"
  }
}
