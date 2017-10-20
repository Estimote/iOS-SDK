//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit.UIImage

enum Update: String {
  case Points  = "UpdatePoints"
  case Default = "ReloadTableView"
}

/// Store customer conforming to customer protocol which implements all the necessairy functionality
class Customer: Displayable, Identifiable, Gamifiable {
  
  /// Store customer has an identifier
  var identifier : String?
  
  /// Store customer has an avatar
  var avatar     : UIImage? {
    didSet { self.updateCustomerInView(updates: [.Default]) }
  }
  
  /// Store customer has a display name
  var name       : String? {
    didSet { self.updateCustomerInView(updates: [.Default]) }
  }
  
  /// Store customer has points
  var points     : Int? {
    didSet { self.updateCustomerInView(updates: [.Default, .Points]) }
  }

  /**
   Initialise a new customer
   
   - parameter identifier: unique identifier for the customer
   
   - returns: Customer object with identifier, avatar, display name and points
   */
  required init(identifier: String) {
    self.identifier = identifier

    /**
     *  async retrieve avatar from cache or Firebase
     *      -> reload view
     */
    self.retrieveAvatar { _avatar in
      self.avatar = _avatar
    }

    /**
     *  async retrive display name from cache or Firebase
     *      -> reload view
     */
    self.retrieveDisplayName { _name in
      self.name = _name
    }
    
    /**
     *  aync syncronise points from Firebase
     *      -> reload view
     */
    self.syncPoints { _points in
      self.points = _points
    }
  }
  
  func updateCustomerInView(updates: [Update]) {
    
    let notificationCenter = NotificationCenter.default
    
    for update in updates {
      // post notification to reload collection view
      notificationCenter.post(name: Notification.Name(rawValue: update.rawValue), object: (update == .Points) ? self.points : nil)
    }
  }
}
