//  Copyright © 2016 Estimote Inc. All rights reserved.
import Foundation
import CoreLocation

let forbiddenBeaconError = NSError(domain: "com.estimote", code: 500, userInfo: [NSLocalizedDescriptionKey:"Trying to start monitoring for beacon that is not assigned to this template."])
let firebaseFetchError = NSError(domain: "com.estimote", code: 500, userInfo: [NSLocalizedDescriptionKey:"Failed to parse Firebase beacon data."])

open class LocationIdentifierProvider: NSObject {
    
    @objc var appId:String
    @objc var appToken:String
    @objc var locationIdentifierPerDeviceIdentifier: [String: String]
    
    @objc public init(appId:String, appToken:String) {
        
        self.appId = appId
        self.appToken = appToken
        self.locationIdentifierPerDeviceIdentifier = [String: String]()
    }
    
    @objc func fetchLocationIdentifier(from dictionary:NSDictionary, completion:@escaping (_ locationIdentifier:String?, _ error:NSError?)->Void) {
        
        let assignedBeaconsRequest = AssignedBeaconsRequest(appId: appId, appToken: appToken)
        assignedBeaconsRequest.send { result in
            
            switch result {
            case .success(let deviceIdentifiers):
                
                let deviceIdentifier = dictionary.object(forKey: "device_identifier") as! String
                
                if deviceIdentifiers.contains(deviceIdentifier) {
                    
                    guard
                        let locationIdentifier = dictionary.object(forKey: "location_identifier") as? String else {
                            completion(nil, firebaseFetchError)
                            return
                    }
                    
                    self.locationIdentifierPerDeviceIdentifier[deviceIdentifier] = locationIdentifier
                    completion(locationIdentifier, nil)
                } else {
                    completion(nil, forbiddenBeaconError)
                }
            case .failure(let error):
                completion(nil, error)
            }
        }
        
        return
    }
    
    @objc open func locationIdentifier(from deviceIdentifier: String) -> String? {
            return self.locationIdentifierPerDeviceIdentifier[deviceIdentifier]
    }
}
