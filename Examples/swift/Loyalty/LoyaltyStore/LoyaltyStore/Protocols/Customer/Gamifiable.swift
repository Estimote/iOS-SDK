//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase

typealias PointsCallback = ((Int) -> ())

protocol Gamifiable: Identifiable {
  // a customer has points
  var points    : Int?                 { set get }
  var pointsRef : DatabaseReference    { get }
}

extension Gamifiable {
  
  // computed property points reference
  var pointsRef: DatabaseReference {
    get {
      let dbRef = Database.database().reference()
      let pointsRef = dbRef.child("points").child(self.identifier!)
      
      return pointsRef
    }
  }
  
  // MARK:  ***************************** Points utility methods  *****************************
  func syncPoints(_ callback: @escaping PointsCallback) {
    // keep points synced
    self.pointsRef.keepSynced(true)
    
    // fetch points from Firebase
    self.pointsRef.observe(.value, with: { snapshot in
      guard let _points = snapshot.value as? Int else {
      fatalError("Unable to resolve snapshot value for display name and cast as String")
      }
      
      // call back with safely resolved points
      callback(_points)
    })
  }
  
  func addPoints(_ newPoints: Int) {
    // set new value
    self.pointsRef.setValue(self.points! + newPoints)
  }
  
  func substractPoints(_ substractedPoints: Int) {
    // set new value
    guard (self.points! - substractedPoints) >= 0 else {
      return
    }
    
    self.pointsRef.setValue(self.points! - substractedPoints)
  }
}
