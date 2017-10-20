//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase
import PromiseKit

class Location {
  var identifier: String
  var customers: Array<String>
  var locationRef: DatabaseReference
  
  init(identifier: String) {
    self.identifier = identifier
    self.customers  = [String]()
    
    let dbRef = Database.database().reference()
    self.locationRef = dbRef.child("locations").child(identifier).child("current_customers")
    
    self.keepSynced()
  }
  
  // fetch customers
  func initCustomers() -> Promise<Void> {
    return Promise { fulfill, reject in
      
      self.locationRef.observeSingleEvent(of: .value, with: { snapshot in
        // case store empty
        guard (snapshot.hasChildren()) else {
          fulfill(())
          return
        }
        
        // resolve snapshot value
        guard let customers = snapshot.value as? Array<String> else {
          let errorMsg = "Unable to resolve snapshot values as Array<String>"
          let error = NSError.init(domain: errorMsg, code: 7, userInfo: nil)
          
          reject(error)
          return
        }
        
        // set customers
        fulfill(self.customers = customers)
      })
    }
  }
  
  // enter
  func keepSynced() {
    // case customer entered
    self.locationRef.observe(.childAdded, with: { snapshot in
      // case store empty
      guard (snapshot.hasChildren()) else {
        return
      }
      
      // resolve snapshot value
      guard let customers = snapshot.value as? Array<String> else {
        fatalError("Unable to resolve snapshot values as Array<String>")
      }
      
      // set customers
      self.customers = customers
    })
    
    // case customer left
    self.locationRef.observe(.childRemoved, with: { snapshot in
      // case store empty
      guard (snapshot.hasChildren()) else {
        return
      }
      
      // resolve snapshot value
      guard let customers = snapshot.value as? Array<String> else {
        fatalError("Unable to resolve snapshot values as Array<String>")
      }
      
      // set customers
      self.customers = customers
    })
  }
  
  func updateCustomers() {
    var dict = [String:String]()
    
    for (index, uid) in self.customers.enumerated() {
      dict["\(index)"] = uid
    }
    
    if (!dict.isEmpty) {
      self.locationRef.updateChildValues(dict)
    } else {
      self.locationRef.setValue([])
    }
  }
}
