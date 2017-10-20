//
// Please report any problems with this app template to contact@estimote.com
//

/// Master view controller.
class StoreViewController: UIViewController {
    
    struct PredefinedParameters {
        static let  monitoringManagerDesiredTriggerDistance = 1.5
    }
    
    // holds store data like it's customers
    var store            : Store!
    // monitors for the device associate with the store
    var monitoringManager : ESTMonitoringV2Manager!
    // device identifier/store identifier fetched from firebase
    var storeIdentifierPerDeviceIdentifier = [String: String]()
    // no customers overlay
    var noCustomersView  = UIView.init()
    // holds reference to the selected customer
    var selectedCustomer : Customer! {
        willSet {
            let notificationCenter = NotificationCenter.default
            notificationCenter.post(name: Notification.Name(rawValue: "customer selected"), object: newValue)
            
            // customer is nill only when no customers are in store
            if newValue == nil {
                // display no customers in store overlay
                self.displayNoCustomersOverlay()
            } else {
                self.hideNoCustomersOverlayIfVisible()
            }
        }
    }
    
    override func viewDidLoad() {
        // set up
        self.setUpMonitoring()
        self.setUpStoreManager()
        self.initNoCustomersOverlay()
    }
    
    func initNoCustomersOverlay() {
        self.noCustomersView = Bundle.main.loadNibNamed("NoCustomersView", owner: self, options: nil)![0] as! UIView
        self.noCustomersView.frame = self.view.bounds
    }
    
    func displayNoCustomersOverlay() {
        UIView.animate(withDuration: 0.2, animations: {
            self.noCustomersView.alpha = 0.98
            self.view.addSubview(self.noCustomersView)
        })
    }
    
    func hideNoCustomersOverlayIfVisible() {
        if self.view.subviews.contains(self.noCustomersView) {
            UIView.animate(withDuration: 0.2, animations: {
                self.noCustomersView.alpha = 0
                self.noCustomersView.removeFromSuperview()
            })
        }
    }
    
    /**
     Set up store manager by ranging for fetched devices -> determine store identifier
     */
    func setUpStoreManager() {
        // set up empty store manager
        self.store = Store(identifier: "unknown") // we don't know the identifier yet
        
        // fetch device identifiers that will illuminate our path to Mordor
        self.store.fetchDevices { devices in
            
            // create identifiers array
            var monitoredIdentifiers = Array<String>()
            
            // collect regions
            for identifier in (devices.allKeys as! Array<String>) {
                
                // extract device identifier
                guard let deviceIdentifier = ((devices[identifier] as AnyObject).object(forKey: "device_identifier"))! as? String else {
                    fatalError("Invalid device identifier format")
                }
                
                // extract location identifier
                guard let locationIdentifier = ((devices[identifier] as AnyObject).object(forKey: "location_identifier"))! as? String else {
                    fatalError("Unable to retrieve location identifier and cast it as a String")
                }
                
                self.storeIdentifierPerDeviceIdentifier[deviceIdentifier] = locationIdentifier
                monitoredIdentifiers.append(deviceIdentifier)
            }
            
            // monitor for available identifiers
            self.monitoringManager.startMonitoring(forIdentifiers: monitoredIdentifiers)
        }
    }
}

// MARK: ****************************** Beacon methods ******************************
extension StoreViewController: ESTMonitoringV2ManagerDelegate {
    
    func setUpMonitoring() {
        // set monitoring manager delegate
        self.monitoringManager = ESTMonitoringV2Manager(desiredMeanTriggerDistance: PredefinedParameters.monitoringManagerDesiredTriggerDistance, delegate: self)
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didFailWithError error: Error) {
        print("Monitoring manager failed with error: \(error.localizedDescription)")
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didEnterDesiredRangeOfBeaconWithIdentifier identifier: String) {
        self.handleInsideZone(forIdentifier: identifier)
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didDetermineInitialState state: ESTMonitoringState, forBeaconWithIdentifier identifier: String) {
        if state == .insideZone {
            self.handleInsideZone(forIdentifier: identifier)
        }
    }
    
    func handleInsideZone(forIdentifier identifier: String) {
        guard let storeIdentifier = self.storeIdentifierPerDeviceIdentifier[identifier] else { return }
        
        // reinitialise store manager
        self.store = Store(identifier: storeIdentifier)
        
        // triggered on database changes
        self.store.setUpDatabase {
            
            // send notification with new customers
            let notificationCenter = NotificationCenter.default
            notificationCenter.post(name: Notification.Name(rawValue: "UpdateCustomers"), object: self.store.customerDatabase.customers)
        }
    }
}

// MARK: ****************************** Segues ******************************
extension StoreViewController {
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        
        guard let segueIdentifier = segue.identifier else { return }
        
        if (segueIdentifier == "pointsSegue" )  { }
        
        if (segueIdentifier == "offersSegue")   { }
        
        if (segueIdentifier == "customerSegue") {
            guard let customerViewController = segue.destination as? CustomerViewController else { return }
            customerViewController.delegate  = self
        }
    }
}

// MARK: Selected customer delegate
extension StoreViewController: SelectedCustomerDelegate {
    func selectedCustomer(_ customer: Customer?) {
        self.selectedCustomer = customer
    }
}
