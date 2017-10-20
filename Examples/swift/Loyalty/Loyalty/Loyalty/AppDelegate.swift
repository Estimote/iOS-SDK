//
// Please report any problems with this app template to contact@estimote.com
//
import Firebase

let NoLocationServicesNotificationKey = "NoLocationServicesNotificationKey"

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        /** TODO: Make sure your beacons have Estimote Monitoring feature set enabled:
         https://community.estimote.com/hc/en-us/articles/226144728
         */
        
        // configure Estimote
        ESTConfig.setupAppID("<#App ID#>", andAppToken: "<#App Token#>")
        
        // configure Firebase
        FirebaseApp.configure()
        
        return true
    }
    
    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
        
        // if app terminates - remove user from range
        if let vc = (window?.rootViewController as? CustomerViewController) {
            vc.customerLeft()
        }
    }
    
    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }
    
    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }
    
    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
        
        let checker = PermissionsChecker()
        if !checker.LocationEnabled() {
            NotificationCenter.default.post(name: Notification.Name(rawValue: NoLocationServicesNotificationKey), object: nil)
        }
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }
    
}
