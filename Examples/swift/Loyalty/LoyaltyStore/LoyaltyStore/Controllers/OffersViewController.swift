//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

class OffersViewController: UIViewController {
  
  @IBOutlet var collectionView: UICollectionView!
  
  var customer: Customer!
  @objc var offers = [Any]()
  
  fileprivate let itemsPerRow: CGFloat = 3

  override func viewDidLoad() {
    super.viewDidLoad()
    
    // register header
    self.registerHeader()
    
    self.offers = exampleOffers()
    
    // register cell in table view
    self.addCustomerObserver()
  }
  
  // observe for selected customer
  @objc func addCustomerObserver() {
    let notificationCenter = NotificationCenter.default
    notificationCenter.addObserver(self, selector: #selector(setNewlySelectedCustomer), name: NSNotification.Name(rawValue: "customer selected"), object: nil)
  }
  
  @objc func setNewlySelectedCustomer(_ notification: Notification) {
    guard let newCustomer = notification.object as? Customer else {
      if notification.object == nil {
        self.customer = nil
      }
      
      return
    }
    
    self.customer = newCustomer
  }
}
  
// MARK: Table View
extension OffersViewController: UICollectionViewDataSource, UICollectionViewDelegate {
  
  // MARK: Cell config
  func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
    
    let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "offerCell", for: indexPath) as! OfferCell
    
    let offer = self.offers[indexPath.item] as! Offer
    
    cell.imageView.image = offer.image
    cell.nameLabel.text  = offer.name
    cell.costLabel.text  = "\(offer.cost)"
    
    return cell
  }
  
  func numberOfSections(in collectionView: UICollectionView) -> Int {
    return 1
  }
  
  func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
    return self.offers.count
  }
  
  // MARK: Header
  func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
    let header = collectionView.dequeueReusableSupplementaryView(ofKind: kind, withReuseIdentifier: "header", for: indexPath) as! HeaderView
    
    return header
  }
  
  @objc func registerHeader() {
    let headerNib = UINib.init(nibName: "HeaderView", bundle: Bundle.main)
    self.collectionView.register(headerNib, forSupplementaryViewOfKind: UICollectionElementKindSectionHeader, withReuseIdentifier: "header")
  }
  
  // Substract points
  func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
    let offer = offers[indexPath.item] as! Offer
    
    AlertHelper.displayValidationAlert("Redeem \(offer.name) for \(emojiPoints[offer.cost]!)⭐️?", subtitle: nil, viewController: self) { _ in
        if (self.customer) != nil {
            self.customer.substractPoints(offer.cost)
        } else {
            let notEnoughPointsPopup = UIAlertController(title: "Detected customers", message: "Redeeming products is only available once there is a customer nearby 💁‍♂️", preferredStyle: UIAlertControllerStyle.alert)
            let understandAction = UIAlertAction(title: "Sure", style: UIAlertActionStyle.default, handler: nil)
            notEnoughPointsPopup.addAction(understandAction)
            self.present(notEnoughPointsPopup, animated: true, completion: nil)
        }
    }
  }
}
