//
// Please report any problems with this app template to contact@estimote.com
//

protocol Storable {
  
  // Store has customers
  var customers: [Customer] { get set }
  
  // Customers have identifiers - used for easier enter/exit diffing
  var customerIdentifiers: Set<String> { get set }

  init()

  // 
  mutating func initNewCustomer(_ customer: Customer)
}
