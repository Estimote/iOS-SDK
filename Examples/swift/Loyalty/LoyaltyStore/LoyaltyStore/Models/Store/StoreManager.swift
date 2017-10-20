//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase

class Store: Manageable {
  
  /// Store is identifiable
  var identifier      : String
  
  /// Store holds a reference to it's customer database
  var storeReference  : CustomerDatabaseReference
  
  /// Store has a customer database
  var customerDatabase: CustomerDatabase

  /**
   Initialise store with its customer database
   
   - parameter identifier: Store identifier
   
   - returns: Store
   */
  required init(identifier: String) {
    self.identifier       = identifier
    self.storeReference   = CustomerDatabaseReference(identifier)
    self.customerDatabase = CustomerDatabase()
  }
}
