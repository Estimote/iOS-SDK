//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase

struct CustomerDatabaseReference {
  var reference: DatabaseReference

  init(_ identifier: String) {
    // create a Firebase reference to stores location and it's current customers
    let dbRef    = Database.database().reference()
    let storeRef = dbRef.child("locations").child(identifier).child("current_customers") // change this later to "customers"

    // makes sure all data is synchronised, useful for offline functionality
    storeRef.keepSynced(true)

    self.reference = storeRef
  }
}
