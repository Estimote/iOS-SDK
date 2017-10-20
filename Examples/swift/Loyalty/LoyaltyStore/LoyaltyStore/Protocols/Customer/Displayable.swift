//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit.UIImage
import FirebaseStorage
import FirebaseDatabase

typealias AvatarCallback = ((UIImage) -> ())
typealias NameCallback   = ((String)  -> ())

protocol Displayable: Identifiable {

  // A customer has an avatar
  var avatar : UIImage? { set get }

  // A customer has a name
  var name   : String?  { set get }

  /**
   Initialise a customer with an identifier

   - parameter identifier: Unique customer identifier

   - returns: Customer struct with `avatar` and `displayName`
   */
  init(identifier: String)
}

extension Displayable {

  // MARK: ***************************** Display name utility methods *****************************

  func retrieveDisplayName(_ callback: @escaping NameCallback) {
    do {
      // try initialising display name cache
      let cache = try Cache<NSString>(name: "Name")

      // see if display name is already cached
      if (cache[self.identifier!] != nil) {
        guard let cachedName = cache[self.identifier!] as String? else {
          fatalError("Unable to resolve name from cache and cast it as String")
        }
        // call back with safely retrieved display name
        callback(cachedName)
      } else {
        // fetch name from Firebase
        self.fetchName({ name in
          // all customer related information should be cached by their unique identifiers
          cache[self.identifier!] = name as NSString?

          // call back with newly fetched display name
          callback(name)
        })
      }
    } catch _ {
      fatalError("Unable to initialise DisplayName cache")
    }
  }

  func fetchName(_ callback: @escaping NameCallback) {

    // create a Firebase reference to customer display name
    let dbRef = Database.database().reference()
    let displayNameRef = dbRef.child("customers").child(self.identifier!).child("name")

    // fetch display name from Firebase
    displayNameRef.observeSingleEvent(of: .value, with: { snapshot in
      guard let _name = snapshot.value as? String else {
        fatalError("Unable to resolve snapshot value for display name and cast as String")
      }

      // call back with safely resolved display name
      callback(_name)
    })
  }

  // MARK:  ***************************** Avatar utility methods  *****************************

  func retrieveAvatar(_ callback: @escaping AvatarCallback) {
    do {
      // initialise AvatarCache
      let cache = try Cache<UIImage>(name: "Avatar")

      // see if avatar is already cached, else fetch from Firebase
      if (cache[self.identifier!] != nil) {
        guard let _avatar = cache[self.identifier!] else {
          fatalError("Unable to resolve avatar from cache")
        }

        // call back with safely resolved avatar image
        callback(_avatar)
      } else {
        self.fetchAvatar({ avatar in
          // all customer related information should be cached by their unique identifiers
          cache[self.identifier!] = avatar

          // call back with newly fetched avatar image
          callback(avatar)
        })
      }
    } catch _ {
      fatalError("Unable to initialize Avatar cache")
    }
  }

  func fetchAvatar(_ callback: @escaping AvatarCallback) {

    // create a Firebase storage reference to customer avatar
    let storageRef = Storage.storage().reference()
    let avatarRef  = storageRef.child("avatar/\(self.identifier!).png")

    _ = avatarRef.getData(maxSize: (1 * 2024 * 2024), completion: { data, error in

      // safely retrieve avatar image data
      guard let avatarData = data else {
        fatalError(error!.localizedDescription)
      }

      // create avatar image from recieved tata
      let _avatar = UIImage.init(data: avatarData)!

      callback(_avatar)
    })
  }
}
