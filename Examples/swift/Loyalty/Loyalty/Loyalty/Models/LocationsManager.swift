//
// Please report any problems with this app template to contact@estimote.com
//
import Foundation
import FirebaseDatabase

protocol  LocationsManagerDelegate {
    func didEnterLocation(_ location:Location)
    func didExitLocation(_ location:Location)
}

class LocationsManager: NSObject, ESTMonitoringV2ManagerDelegate {
    
    @objc var monitoringManager         : ESTMonitoringV2Manager!
    var delegate                  : LocationsManagerDelegate?
    @objc var locationIdentifierProvider: LocationIdentifierProvider!
    
    override init() {
        super.init()
        
        let id    = ESTConfig.appID()
        let token = ESTConfig.appToken()
        
        self.monitoringManager = ESTMonitoringV2Manager(desiredMeanTriggerDistance: 1.0, delegate: self)
        self.locationIdentifierProvider = LocationIdentifierProvider.init(appId: id!, appToken: token!)
    }
    
    @objc func startMonitoring() {
        
        // init devices ref
    let dbRef = Database.database().reference()
    let devicesRef = dbRef.child("devices")
    
    // fetch devices
    devicesRef.observeSingleEvent(of: .value, with: { snapshot in
        
        var identifiers = [String]()
        for device in snapshot.children {
            
            guard let device_info = (device as! DataSnapshot).value as? NSDictionary, let identifier = device_info.object(forKey: "device_identifier") as? String  else {
                continue
            }
            identifiers.append(identifier)
        }
        self.monitoringManager.startMonitoring(forIdentifiers: identifiers)
    })
    }
    
    @objc func stopMonitoring() {
        self.monitoringManager.stopMonitoring()
    }
    
    // MARK: Handle Enter & Exit
    @objc func handleInsideRegion(_ identifier:String) {
        guard let locationIdentifier = self.locationIdentifierProvider.locationIdentifierPerDeviceIdentifier[identifier] else { return }
        
        let location = Location(identifier: locationIdentifier)
        _ = location.initCustomers().then{_ in
            self.delegate?.didEnterLocation(location)
        }
    }
    
    @objc func handleOutsideRegion(_ identifier:String) {
        guard let locationIdentifier = self.locationIdentifierProvider.locationIdentifierPerDeviceIdentifier[identifier] else { return }
        let location = Location(identifier: locationIdentifier)
        
        self.delegate?.didExitLocation(location)
    }
    
    // MARK: ESTBeaconManagerDelegate
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didFailWithError error: Error) {
        print(error.localizedDescription)
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didEnterDesiredRangeOfBeaconWithIdentifier identifier: String) {
        handleInsideRegion(identifier)
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didExitDesiredRangeOfBeaconWithIdentifier identifier: String) {
        handleOutsideRegion(identifier)
    }
    
    func monitoringManager(_ manager: ESTMonitoringV2Manager, didDetermineInitialState state: ESTMonitoringState, forBeaconWithIdentifier identifier: String) {
        switch state {
        case .insideZone : handleInsideRegion(identifier)
        default : return
        }
    }
}
