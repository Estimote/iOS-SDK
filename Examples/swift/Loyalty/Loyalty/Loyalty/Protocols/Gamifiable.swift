//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase
import PromiseKit

protocol Gamifiable: Identifiable {
  // Customer has points
  var points: Int? { set get }
}

extension Gamifiable {
  /**
   Set initial points in Firebase, creates required foundational structure
   */
  func setInitialPoints() {
    // init points ref
    let dbRef     = Database.database().reference()
    let pointsRef = dbRef.child("points").child(self.identifier!)
    
    // set points
    pointsRef.setValue(0) { error, reference in
        _ = self.syncPoints()
    }
  }
  
  /**
   Synchronise points by observing on any value change
  
   - returns: Points promise integer
   */
  func syncPoints() -> Promise<Int> {
    return Promise { fulfill, reject in
      // create a Firebase reference to customer points
      let dbRef     = Database.database().reference()
      let pointsRef = dbRef.child("points").child(self.identifier!)
      
      // keep points synced
      pointsRef.keepSynced(true)
      
      // fetch points from Firebase
      _ = pointsRef.observe(.value, with: { snapshot in

        // resolve points value as Int
        guard let _points = snapshot.value as? Int else {
          // init error
          let errorMsg = "Unable to resolve snapshot value for points and cast as Int"
          let error = NSError.init(domain: errorMsg, code: 4, userInfo: nil)
          
          // reject
          reject(error)
          return
        }
        
        if (self.points != nil) {
          // if points non nil, post notification with new points
          
          // init notification center
          let notificationCenter = NotificationCenter.default
          let notificationName   = "update_points"
          
          // points change -> post notification passing new points -> update points view
          notificationCenter.post(name: NSNotification.Name(rawValue: notificationName), object: _points)
          
          // fulfill
          fulfill(_points)
        }
        
        // fulfill
        fulfill(_points)
      })
    }
  }
}
