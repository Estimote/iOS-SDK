//
// Please report any problems with this app template to contact@estimote.com
//

struct Offer {
  
  var name        : String
  var description : String
  var cost        : Int
  var image       : UIImage
  
  init(name: String, description: String, cost: Int, image: UIImage) {
    self.name        = name
    self.description = description
    self.cost        = cost
    self.image       = image
  }
}
