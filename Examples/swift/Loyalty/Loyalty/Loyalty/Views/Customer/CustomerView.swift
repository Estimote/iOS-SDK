//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class CustomerView: UIView {
  
  @IBOutlet weak var pointsLabel: UILabel!
  
  @objc func observePoints() {
    // init notification center
    let notificationCenter   = NotificationCenter.default
    let updatePointsSelector = #selector(updatePoints)
    
    // add observer
    notificationCenter.addObserver(self, selector: updatePointsSelector, name: NSNotification.Name(rawValue: "update_points"), object: nil)
  }
  
  @objc dynamic fileprivate func updatePoints(_ notification: Notification) {
    guard let points = notification.object as? Int else {
      fatalError("Unable to retrieve points from notification object and cast as Int")
    }
    
    self.pointsLabel.text = "\(points)"
  }
}
