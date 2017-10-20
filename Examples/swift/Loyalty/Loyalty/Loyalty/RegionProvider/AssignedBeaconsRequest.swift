//  Copyright © 2016 Estimote Inc. All rights reserved.

import Foundation
import CoreLocation

public enum AssignedBeaconsRequestResult {
  case success(deviceIdentifiers: [String])
  case failure(error:NSError)
}

public typealias AssignedBeaconsRequestCompletionType = (AssignedBeaconsRequestResult) -> Void

class AssignedBeaconsRequest {
  
  var appId:String
  var appToken:String
  
  init(appId:String, appToken:String) {
    
    self.appId = appId
    self.appToken = appToken
  }
  
  func send(_ completion:@escaping AssignedBeaconsRequestCompletionType) {
    let endpoint = "https://cloud.estimote.com/v2/applications/assigned_beacons?appToken=\(self.appToken)"
    
    guard let url = URL(string: endpoint) else {
      completion(AssignedBeaconsRequestResult.failure(error: NSError(domain: "com.estimote", code: 500, userInfo: [NSLocalizedDescriptionKey:"Failed to connect."])))
      return
    }
    
    let request = NSMutableURLRequest(url: url)
    request.setValue("application/json", forHTTPHeaderField: "Accept")
    request.setValue("application/json", forHTTPHeaderField: "Content-Type")
    request.httpMethod = "GET"
    
    let authString = "\(appId):\(appToken)"
    
    guard  let authData = authString.data(using: String.Encoding.utf8) else {
      completion(AssignedBeaconsRequestResult.failure(error: NSError(domain: "com.estimote", code: 500, userInfo: [NSLocalizedDescriptionKey:"Failed to authorize."])))
      return
    }
    
    let authValue = "Basic " + (authData as NSData).base64Encoding(withLineLength: 0)
    
    request.setValue(authValue, forHTTPHeaderField: "Authorization")
    
    let task = URLSession.shared.dataTask(with: request as URLRequest, completionHandler: { data, response, error in
      
      if let error = error {
        completion(AssignedBeaconsRequestResult.failure(error: error as NSError))
      } else if let response = response as? HTTPURLResponse {
        if response.statusCode == 200 {
          if let data = data {
            if let identifiers = AssignedBeaconsRequest.parseData(data) {
              completion(AssignedBeaconsRequestResult.success(deviceIdentifiers: identifiers))
            } else {
              completion(AssignedBeaconsRequestResult.failure(error: NSError(domain: "com.estimote", code: 500, userInfo: [NSLocalizedDescriptionKey:"Failed to parse response."])))
            }
          } else {
            completion(AssignedBeaconsRequestResult.failure(error: NSError(domain: "com.estimote", code: response.statusCode, userInfo: [NSLocalizedDescriptionKey:"No data was received."])))
          }
        } else {
          completion(AssignedBeaconsRequestResult.failure(error: NSError(domain: "com.estimote", code: response.statusCode, userInfo: [NSLocalizedDescriptionKey:"Received code other than 200."])))
        }
      } else {
        completion(AssignedBeaconsRequestResult.failure(error: NSError(domain: "com.estimote", code: 500, userInfo: [NSLocalizedDescriptionKey:"Request ended without response."])))
      }
    }) 
    task.resume()
  }
  
  class func parseData(_ data:Data) -> [String]? {
    
    do {
      let devices = try JSONSerialization.jsonObject(with: data, options:[]) as! Array<Dictionary<String,String>>
      
      print(devices)
      
      var identifers = [String]()
      
      for device in devices {
        identifers.append(device["device_identifier"]!)
      }
      
      return identifers
      
    } catch let error {
      print(error)
    }
    
    return nil
  }
}
