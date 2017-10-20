//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseAuth
import PromiseKit

class Customer: Identifiable, Authorisable, Displayable, Storable, Gamifiable {
  
  var identifier : String?
  var avatar     : UIImage?
  var name       : String?
  var points     : Int?
  
  init() {
    self.identifier = Auth.auth().currentUser?.uid
  }
  
  func create() -> Promise<Customer> {
    return Promise { fulfill, reject in
      // retrieve avatar
      _ = self.retrieveAvatar().then { _avatar -> Promise<String> in
        self.avatar = _avatar
        // retrieve  name
        return self.retrieveName()
      }.then { _name -> Promise<Int> in
        self.name = _name
        // sync points
        return self.syncPoints()
      }.then { _points -> Void in
        self.points = _points
      }.then {
        // fulfill
        fulfill(self)
      }
    }
  }
}
