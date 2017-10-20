//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class DirectorViewController: UIViewController {
  
  var customer:Customer!
  
  override func viewWillAppear(_ animated: Bool) {
    super.viewWillAppear(animated)
    
    self.customer = Customer.init()
    
    // check if authorised
    if self.customer.isAuthorised {
      UserDefaults.standard.set(true, forKey: firstStartKey)
      
      // show CustomerView
      _ = self.customer.create().then { customer -> Void in
        self.customer = customer
        self.performSegue(withIdentifier: "showCustomer", sender: self)
      }
    } else {
      // otherwise authorise
      self.performSegue(withIdentifier: "showAuthorization", sender: self)
    }
  }
  
  override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
    if segue.identifier == "showCustomer" {
      let customerVC = segue.destination as! CustomerViewController
      customerVC.customer = self.customer
    }
  }
}
