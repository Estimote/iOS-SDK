//
// Please report any problems with this app template to contact@estimote.com
//

import FirebaseStorage
import FirebaseDatabase
import PromiseKit

protocol Displayable: Identifiable {
  
  // Customer has an avatar
  var avatar : UIImage? { set get }
  
  // Customer has a name
  var name   : String?  { set get }
}

extension Displayable {
  
  // MARK: ***************************** Name utility methods *****************************
  
  func retrieveName() -> Promise<String> {
    return Promise { fulfill, reject in
      do {
        // try initialising name cache
        let cache = try Cache<NSString>(name: "Name")
        
        // see if name is already cached
        if (cache[self.identifier!] != nil) {
          guard let _cachedName = cache[self.identifier!] as String? else {
            // init error
            let errorMsg = "Unable to resolve name from cache and cast it as String"
            let error = NSError.init(domain: errorMsg, code: 1, userInfo: nil)
            
            // reject
            reject(error)
            return
          }
          
          // fulfill
          fulfill(_cachedName)
        } else {
          // fetch name from Firebase
          _ = self.fetchName().then { _name -> Void in
            // cache
            cache[self.identifier!] = _name as NSString
            
            // fulfill
            fulfill(_name)
          }
        }
      } catch _ {
        fatalError("Unable to initialise Name cache")
      }
    }
  }
  
  func fetchName() -> Promise<String> {
    return Promise { fulfill, reject in
      // initialise a Firebase reference to customer name
      let dbRef   = Database.database().reference()
      let nameRef = dbRef.child("customers").child(self.identifier!).child("name")
      
      // fetch name from Firebase
      nameRef.observeSingleEvent(of: .value, with: { snapshot in
        // resolve snapshot value to name String
        guard let _name = snapshot.value as? String else {
          // init error
          let errorMsg = "Unable to resolve snapshot value for name and cast as String"
          let error    = NSError(domain: errorMsg, code: 2, userInfo: nil)
          
          // reject
          reject(error)
          return
        }
        
        // fulfill
        fulfill(_name)
      })
    }
  }
  
  // MARK:  ***************************** Avatar utility methods  *****************************
  
  func retrieveAvatar() -> Promise<UIImage> {
    return Promise { fulfill, reject in
      do {
        // initialise Avatar cache
        let cache = try Cache<UIImage>(name: "Avatar")
        
        // see if avatar is already cached, else fetch from Firebase
        if (cache[self.identifier!] != nil) {
          // resolve avatar from cache
          guard let _avatar = cache[self.identifier!] else {
            // init error
            let errorMsg = "Unable to resolve avatar from cache"
            let error    = NSError(domain: errorMsg, code: 2, userInfo: nil)
            
            // reject
            reject(error)
            return
          }
          
          // fulfill
          fulfill(_avatar)
        } else {
          _ = self.fetchAvatar().then { _avatar -> Void in
            // cache
            cache[self.identifier!] = _avatar
            
            // fulfill
            fulfill(_avatar)
          }
        }
      } catch _ {
        fatalError("Unable to initialize Avatar cache")
      }
    }
  }
  
  func fetchAvatar() -> Promise<UIImage> {
    return Promise { fulfill, reject in
      // create a Firebase storage reference to customer avatar
      let storageRef = Storage.storage().reference()
      let avatarRef  = storageRef.child("avatar/\(self.identifier!).png")
      
      _ = avatarRef.getData(maxSize: (2 * 1024 * 1024), completion: { data, error in
        // if error -> call back nil
        guard (error == nil) else {
          // reject
          reject(error!)
          return
        }
        
        // safely resolve avatar image data
        guard let avatarData = data else {
          fatalError("Unable to resolve avatar image data")
        }
        
        // create avatar image from avatar data
        let _avatar = UIImage.init(data: avatarData)!
        
        // fulfill
        fulfill(_avatar)
      })
    }
  }
}
