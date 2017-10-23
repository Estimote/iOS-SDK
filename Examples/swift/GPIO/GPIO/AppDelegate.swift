//
// Please report any problems with this app to contact@estimote.com
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, ESTBeaconManagerDelegate {

    var window: UIWindow?
    
    let beaconManager = ESTBeaconManager()

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        /** TODO: Replace with your App ID and App Token.
         You can get them by adding a new app at https://cloud.estimote.com/#/apps
         */
        ESTConfig.setupAppID("<#App ID#>", andAppToken: "<#App Token#>")
        
        self.beaconManager.delegate = self
        self.beaconManager.requestAlwaysAuthorization()

        UIApplication.shared.statusBarStyle = UIStatusBarStyle.lightContent
        return true
    }

}
