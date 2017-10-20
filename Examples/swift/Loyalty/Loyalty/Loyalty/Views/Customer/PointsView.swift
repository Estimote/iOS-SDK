//
// Please report any problems with this app template to contact@estimote.com
//

class PointsView: UIView {
  
  @IBOutlet weak var pointsLabel: UILabel!
  
  @objc func observePoints() {
    // init notification center
    let notificationCenter = NotificationCenter.default
    let method = #selector(updatePoints)
    
    // add observer
    notificationCenter.addObserver(self, selector: method, name: NSNotification.Name(rawValue: "update_points"), object: nil)
  }
  
  @objc dynamic fileprivate func updatePoints(_ notification: Notification) {
    guard let points = notification.object as? Int else { fatalError("Unable to retrieve points from notification object and cast as Int") }
    
    self.pointsLabel.text = "\(points)"
  }
}
