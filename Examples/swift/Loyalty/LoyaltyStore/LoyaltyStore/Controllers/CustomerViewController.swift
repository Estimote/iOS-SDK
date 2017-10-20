//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class CustomerViewController: UITableViewController {

  var customers: [Customer]? {
    willSet {
      if newValue!.isEmpty {
        self.delegate?.selectedCustomer(nil)
      }
    }
  }
  
  weak var delegate: SelectedCustomerDelegate? = nil
  @objc var lastSelectedIndex: Int = 0
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    self.addCustomersObserver()
  }
  
  /**
   Observe for and react to database changes
   */
  @objc func addCustomersObserver() {
    // init notification center
    let notificationCenter = NotificationCenter.default
    
    let customerObserver         = "UpdateCustomers"
    let customerObserverSelector = #selector(updateCustomers)

    let tableViewObserver         = "ReloadTableView"
    let tableViewObserverSelector = #selector(reloadTableView)
    
    // register observer for reloading the table view and updating customers
    notificationCenter.addObserver(self, selector: tableViewObserverSelector, name: NSNotification.Name(rawValue: tableViewObserver), object: nil)
    notificationCenter.addObserver(self, selector: customerObserverSelector,  name: NSNotification.Name(rawValue: customerObserver),  object: nil)
  }
  
  @objc dynamic fileprivate func updateCustomers(_ notification: Notification) {
    // check if notification customer object
    guard let newCustomers = notification.object as? [Customer] else {
      fatalError("Unable to update customers because of no customer object in notification")
    }
    
    // set new customers
    self.customers = newCustomers
    
    // reload table view
    self.tableView.reloadData()
  }
  
  // used for skeleton loading the table view, see Customer model
  @objc dynamic fileprivate func reloadTableView(_ notification: Notification) {
    // reload table view
    self.tableView.reloadData()
  }
}

// MARK: Table view data source delegate methods
extension CustomerViewController {

  override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    guard self.customers != nil else {
      return 0
    }
    
    return self.customers!.count
  }
  
  override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    // dequeueueueueueueueueue
    guard let cell = tableView.dequeueReusableCell(withIdentifier: "customerCell", for: indexPath) as? CustomerCell else {
      fatalError("Unable to deque cell as CustomerCell")
    }
    
    // configure cell
    guard let customer = self.customers?[indexPath.item] else {
      return cell
    }
    
    // sellect the last cell and set selected customer
    if (indexPath.item == 0 && self.lastSelectedIndex == 0 || self.lastSelectedIndex == indexPath.item) {
      // select the last cell
      cell.isSelected = true
      self.tableView.selectRow(at: indexPath, animated: false, scrollPosition: .none)
      
      // set sellected customer
      let customer = self.customers![indexPath.item]
      self.delegate?.selectedCustomer(customer)
    }
    
    cell.avatarImageView.image = (customer.avatar != nil) ? customer.avatar       : nil
    cell.nameLabel.text        = (customer.name   != nil) ? customer.name         : ""
    cell.pointsLabel.text      = (customer.points != nil) ? "\(customer.points!)" : ""
    
    return cell
  }
}

extension CustomerViewController {
  override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
    // retrieve customer index
    let index    = indexPath.item
    let customer = self.customers![index]
    
    // pass customer index to to store view controller
    self.delegate!.selectedCustomer(customer)
    
    // set last selected index
    self.lastSelectedIndex = index
  }
}

// MARK: Store delegate protocol for passing data up stream
protocol SelectedCustomerDelegate: class {
  func selectedCustomer(_ customer: Customer?)
}
