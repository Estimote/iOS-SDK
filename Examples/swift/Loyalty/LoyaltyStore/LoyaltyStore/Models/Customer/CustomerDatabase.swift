//
// Please report any problems with this app template to contact@estimote.com
//

/**
 *  Holds information about customers
 */
struct CustomerDatabase: Storable {
  /// Array of customers
  var customers: [Customer]
  
  /// Set of customer identifiers
  var customerIdentifiers: Set<String>

  /**
   Initialise customer database
   
   - returns: Empty CustomerDatabase instance
   */
  init() {
    self.customers = []
    self.customerIdentifiers = Set<String>()
  }

  /**
   Create a new customer entry in database by inserting
   a customer identifier and appending the customer object
   
   - parameter customer: Customer object
   */
  mutating func initNewCustomer(_ customer: Customer) {
    let customerIdentifier = customer.identifier
    
    customerIdentifiers.insert(customerIdentifier!)
    customers.append(customer)
  }
}
