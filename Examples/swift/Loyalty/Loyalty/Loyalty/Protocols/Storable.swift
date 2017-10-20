//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseDatabase
import FirebaseStorage

protocol Storable: Identifiable { }

extension Storable {
  
  /**
   Save basic information, creates required foundational structure
   
   - parameter customerInfo: Dictionary with customer name and identifier
   */
  func saveInfo(_ customerInfo: Dictionary<String, String>) {
    // init Firebase reference to customer
    let dbRef       = Database.database().reference()
    let customerRef = dbRef.child("customers").child(self.identifier!)
    
    // cache name
    self.cacheName(customerInfo["name"]!)
    
    // set customer info
    customerRef.setValue(customerInfo)
  }
  
  /**
   Cache customer name
   
   - parameter name: name of the customer
   */
  func cacheName(_ name: String) {
    do {
      // try initing cache
      let cache = try Cache<NSString>(name: "Name")
      
      cache[self.identifier!] = name as NSString
    } catch _ {
       fatalError("Unable to initialise Name cache")
    }
  }
  
  /**
   Cache and stores avatar image to Firebase
   
   - parameter avatar: avatar image
   */
  func saveAvatar(_ avatar: UIImage) {
    // cache avatar
    self.cacheAvatar(avatar)
    // store avatar
    self.storeAvatar(avatar)
  }
  
  /**
   Cache avatar image
   
   - parameter avatar: avatar image
   */
  func cacheAvatar(_ avatar: UIImage) {
    do {
      // try initing avatar cache
      let cache = try Cache<UIImage>(name: "Avatar")
      
      // cache avatar
      cache[self.identifier!] = avatar
    } catch _ {
      fatalError("Unable to initialise Avatar cache")
    }
  }
  
  /**
   Store avatar image in Firebase
   
   - parameter avatar: avatar image
   */
  func storeAvatar(_ avatar: UIImage) {
    // init avatar storage ref
    let storageRef        = Storage.storage().reference()
    let avatarStoragePath = "avatar/\(self.identifier!).png"
    let avatarStorageRef  = storageRef.child(avatarStoragePath)
    
    // convert avatar in to data
    guard let avatarData = UIImagePNGRepresentation(avatar) else {
      fatalError("Unable to convert avatar image to png data representation")
    }
    
    // save avatar to Firebase storage
    _ = avatarStorageRef.putData(avatarData)
  }
}
