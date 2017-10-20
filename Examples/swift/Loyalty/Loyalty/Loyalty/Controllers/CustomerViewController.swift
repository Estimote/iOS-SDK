//
// Please report any problems with this app template to contact@estimote.com
//
import FirebaseDatabase
import FirebaseAuth
import PromiseKit

class CustomerViewController: UIViewController {
    
    // MARK: outlets
    @IBOutlet weak var pointsView      : PointsView!
    @IBOutlet weak var offersTableView : UITableView!
    
    // MARK: customer store management variables
    @objc var locationsManager:LocationsManager!
    var location: Location?
    var customer: Customer!
    
    @objc var offers: [Any]!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.offers = exampleOffers()
        
        // set and observe points
        self.pointsView.pointsLabel.text = "\((self.customer.points != nil) ? self.customer.points! : 0)"
        self.pointsView.observePoints()
        
        // register cell in table view
        self.registerCell()
        
        // start LocationsManager
        self.locationsManager = LocationsManager()
        self.locationsManager.delegate = self
        self.locationsManager.startMonitoring()
        
        // remove back button
        navigationItem.hidesBackButton = true
        
        // check location permissions 1st time around
        let checker = PermissionsChecker()
        if !checker.LocationEnabled() {
            self.showLocationPermissions()
        }
        
        // listen for notifications
        NotificationCenter.default.addObserver(self, selector: #selector(CustomerViewController.showLocationPermissions), name: NSNotification.Name(rawValue: NoLocationServicesNotificationKey), object: nil)
    }
    
    @objc func showLocationPermissions() {
        self.performSegue(withIdentifier: "showLocationPermissions", sender: self)
    }
    
    // MARK: actions
    @IBAction func logOutTapped(_ sender: UIBarButtonItem) {
        
        do {
            try Auth.auth().signOut()
        } catch {
            fatalError("Failed to sign out.")
        }
        
        self.locationsManager.stopMonitoring()
        self.customerLeft()
        navigationController?.popToRootViewController(animated: true)
    }
}

// MARK: Table View config
extension CustomerViewController: UITableViewDelegate, UITableViewDataSource {
    // MARK: Cell config and registration
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "OfferCell") as! OfferCell
        
        let offer = self.offers[indexPath.row] as! Offer
        
        // configure cell
        cell.offerNameLabel.text           = offer.name
        cell.offerDescriptionTextView.text = offer.description
        cell.offerStarsCountLabel.text     = "\(offer.cost)"
        cell.offerExtraInfoLabel.textColor = Stylesheet.orderForFreeColor
        cell.offerImageView.image          = offer.image
        
        return cell
    }
    
    @objc func registerCell() {
        let cellIdentifier = "OfferCell"
        
        self.offersTableView.register(UINib(nibName: cellIdentifier, bundle:nil), forCellReuseIdentifier: cellIdentifier)
        self.offersTableView.separatorStyle = .none
    }
    
    // MARK: Table view config
    func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch (section) {
        case 0:
            return 0
        case 1:
            return offers.count
        default:
            return 0
        }
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 120
    }
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        if section == 1 {
            return 45
        }
        return 0
    }
    
    // MARK: Table view header config
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        if section == 1 {
            // init header
            let header = Bundle.main.loadNibNamed("HeaderView", owner: nil, options: nil)![0] as! HeaderView
            return header
        }
        return nil
    }
}

extension CustomerViewController: LocationsManagerDelegate {
    
    func didEnterLocation(_ location: Location) {
        if self.location != nil {
            if self.location?.identifier != location.identifier {
                self.customerLeft()
            }
        }
        
        guard location.identifier != self.location?.identifier else {
            print("Entered same location again \(String(describing: self.location?.identifier))")
            return
        }
        
        self.location = location
        self.customerEntered()
    }
    
    func didExitLocation(_ location: Location) {
        guard self.location != nil else {
            print("Exited location \(location.identifier) without entering.")
            return
        }
        guard self.location?.identifier == location.identifier else {
            print("Exited location \(location.identifier) while being in different location \(String(describing: self.location?.identifier)).")
            return
        }
        
        self.customerLeft()
    }
    
    @objc func customerEntered() {
        if !((self.location?.customers.contains(self.customer.identifier!))!) {
            // append customer to location
            self.location?.customers.append(self.customer.identifier!)
            // update location
            self.location?.updateCustomers()
        }
    }
    
    @objc func customerLeft() {
        // filter customers
        let filteredCustomers = self.location?.customers.filter() {
            return $0 != self.customer.identifier!
        }
        self.location?.customers = filteredCustomers!
        
        // update location
        self.location?.updateCustomers()
        self.location = nil
    }
}
