//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase

typealias DevicesCallback = ((NSDictionary) -> ())

protocol Manageable {
  var identifier      : String                    { set get }
  var customerDatabase: CustomerDatabase          { set get }
  var storeReference  : CustomerDatabaseReference { set get }

  init(identifier: String)
}

extension Manageable {
  
  // MARK: ****************************  Store location management  ****************************
  
  func fetchDevices(_ callback: @escaping DevicesCallback) {
    /// fetch beacon identifiers from firebase
    let dbRef = Database.database().reference()
    let storeLocationRef = dbRef.child("devices")
    
    storeLocationRef.observe((.value), with: { snapshot in
      
      // format
      /*
       "[device_identifier]": {
          "device_identifier"   : "some string",
          "location_identifier" : "some string"
       },...
       */
      guard let devices = snapshot.value as? NSDictionary else {
        fatalError("Unable to resolve snapshot value as NSDictionary when fetching the list of devices")
      }
      
      callback(devices)
    })
  }

  // MARK: ****************************  Customer database management  ********************************

  mutating func setUpDatabase(_ ready: @escaping () -> ()) {
    var copy = self

    // initialise a FirebaseDatabase reference of custumers that are in the store
    self.storeReference.reference.observe(.value, with: { customerSnapshot in

      // if every customer left, the snapshot will have no children
      if (!customerSnapshot.hasChildren()) {
        // wipe clean the database
        copy.customerDatabase = CustomerDatabase.init()

      }

      // transform snapshot values to customer identifiers
      var newCustomerIdentifiers: Array<String> = []
      for customer in customerSnapshot.children {
        // cast snapshot value to String
        guard let someCustomerIdentifier = (customer as? DataSnapshot)!.value as? String else {
          fatalError("Unable to cast snapshot value as String")
        }

        newCustomerIdentifiers.append(someCustomerIdentifier)
      }

      let newCustomerIdentifiersSet: Set<String> = Set(newCustomerIdentifiers)

      /* if (no customers present || first time initiating)
                => populate customer database with new customers
       */
      if (copy.customerDatabase.customers.isEmpty) {
        // init new customers (identifiers and store customer objects respectively)
        copy.customerDatabase = copy.initNewCustomers(newCustomerIdentifiersSet, database: copy.customerDatabase)

        // store ready
        ready()

      } else {

        // **************************** Find the change Δ in customers ****************************

        // do some diffing right?
        // instead of iterating over entire array, we only want to apply the changes Δ in customers
        let prevCustomerIdentifiersSet = copy.customerDatabase.customerIdentifiers

        // extclusiveOr previous customers with new customers
        //      => leaving or new customers
        let changingCustomers = newCustomerIdentifiersSet.symmetricDifference(prevCustomerIdentifiersSet)

        // substract changing customers from previous customers
        //      => leaving customers
        let leavingCustomers  = prevCustomerIdentifiersSet.subtracting(changingCustomers)

        // substract previous customers from changing customers
        //      => new customers
        let newCustomers      = changingCustomers.subtracting(prevCustomerIdentifiersSet)

        // **************************** UPDATE CUSTOMER DATABASE ****************************

        // remove leaving customers from database
        copy.customerDatabase = copy.removeLeavingCustomers(leavingCustomers, database: copy.customerDatabase)

        // init new customers (identifiers and store customer objects)
        copy.customerDatabase = copy.initNewCustomers(newCustomers, database: copy.customerDatabase)

        // store ready
        ready()
      }
    })
    self = copy
  }
  
  // MARK: **************************** Customer management methods ****************************

  func removeLeavingCustomers(_ identifiers: Set<String>, database: CustomerDatabase) -> CustomerDatabase {
    var db = database
    for identifier in identifiers {
      // remove customer identifier
      db.customerIdentifiers.remove(identifier)

      // remove customers which identifier matches the leaving customer
      let updatedCustomers = db.customers.filter({ ($0.identifier == identifier) })
      db.customers = updatedCustomers
    }

    // return modified database
    return db
  }

  func initNewCustomers(_ identifiers: Set<String>, database: CustomerDatabase) -> CustomerDatabase {
    var db = database
    for identifier in identifiers {
      let newCustomer = Customer(identifier: identifier)
      
      // init new customer to customer database
      db.initNewCustomer(newCustomer)
    }

    // return modified database
    return db
  }
}
