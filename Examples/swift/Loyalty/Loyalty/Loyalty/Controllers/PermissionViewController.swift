//
// Please report any problems with this app template to contact@estimote.com
//
import UIKit

class PermissionViewController: UIViewController {
    
    @objc lazy var locationManager: CLLocationManager = {
        let manager = CLLocationManager()
        manager.delegate = self
        return manager
    }()
    
    @IBOutlet var button           : DesignableButton!
    @IBOutlet var descriptionLabel : UILabel!
    @IBOutlet var titleLabel       : UILabel!
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        titleLabel.text = "Location needed"
        descriptionLabel.text = "We need to locate you if you want to earn points and reedem coupons."
        button.setTitle("Allow location sharing", for: UIControlState())
    }
    
    override var preferredStatusBarStyle: UIStatusBarStyle {
        return UIStatusBarStyle.lightContent
    }
    
    @IBAction func allowButtonAction(_ sender: AnyObject) {
        
        if CLLocationManager.authorizationStatus() == CLAuthorizationStatus.notDetermined {
            locationManager.requestAlwaysAuthorization()
        } else {
            let url = URL(string:UIApplicationOpenSettingsURLString)
            UIApplication.shared.openURL(url!)
            
            dismiss(animated: false, completion: nil)
        }
    }
}

extension PermissionViewController: CLLocationManagerDelegate {
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .authorizedAlways || status == .authorizedWhenInUse {
            dismiss(animated: false, completion: nil)
        }
    }
}
