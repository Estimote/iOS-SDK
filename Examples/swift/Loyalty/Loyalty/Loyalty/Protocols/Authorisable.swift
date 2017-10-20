//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseAuth
import PromiseKit

protocol Authorisable: Identifiable {
  // Customer is (!)authorised
  var isAuthorised: Bool { get }
}

extension Authorisable where Self: Customer {
  
  var isAuthorised: Bool {
    get {
      return (self.identifier != nil)
    }
  }
  
  // sign up
  func singUp(_ email: String, password: String, avatar: UIImage, name: String) -> Promise<Customer> {
    return Promise { fulfill, reject in
      // init auth
      let auth = Auth.auth()
      
      // create user with email, password
      auth.createUser(withEmail: email, password: password, completion: { (user, error) in
        // if error
        guard (error == nil) else {
          // reject
          reject(error!)
          return
        }
        
        // init Customer
        let customer = Customer()
        
        // avatar
        customer.avatar = avatar
        customer.saveAvatar(avatar)
        
        // name
        customer.name = name
        
        // init customer info (id, name name)
        let customerInfo = Dictionary.init(dictionaryLiteral: ("identifier",  customer.identifier!), ("name", name))
        // save customer info to database
        customer.saveInfo(customerInfo)
        
        // set initial points
        customer.setInitialPoints()
        
        // fulfill
        fulfill(customer)
      })
    }
  }
  
  // login the awesome returning user
  func logIn(_ email: String, password: String) -> Promise<Customer> {
    return Promise { fulfill, reject in
      let auth = Auth.auth()
      
      auth.signIn(withEmail: email, password: password, completion: { (user, error) in
        
        guard (error == nil) else {
          // reject
          reject(error!)
          return
        }
        
        // init and create customer
        let customer = Customer()
        _ = customer.create().then { customer -> Void in
          // fulfill
          fulfill(customer)
        }
      })
    }
  }
}
