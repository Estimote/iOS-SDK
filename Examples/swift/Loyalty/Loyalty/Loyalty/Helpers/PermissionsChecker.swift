//
// Please report any problems with this app template to contact@estimote.com
//

class PermissionsChecker:NSObject {
  
  @objc func LocationEnabled() -> Bool {
    return CLLocationManager.authorizationStatus() == CLAuthorizationStatus.authorizedAlways
  }
}
