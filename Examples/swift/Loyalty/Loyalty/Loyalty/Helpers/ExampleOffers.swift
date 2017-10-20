//
// Please report any problems with this app template to contact@estimote.com
//

func exampleOffers() -> [Any] {
  
  let espresso     = Offer(name: "Extra Espresso", description: "Lorem ipsum good coffee template mate", cost: 25, image: UIImage.init(named: "extra_espresso")!)
  let chocolate    = Offer(name: "Chocolate",      description: "Lorem ipsum good coffee template mate", cost: 25, image: UIImage.init(named: "chocolate")!)
  let latte        = Offer(name: "Caffee Latte",   description: "Lorem ipsum good coffee template mate", cost: 25, image: UIImage.init(named: "latte")!)
  let white_coffee = Offer(name: "White Coffee",   description: "Lorem ipsum good coffee template mate", cost: 50, image: UIImage.init(named: "white_coffee")!)
  let cappuccino   = Offer(name: "Cappuccino",     description: "Lorem ipsum good coffee template mate", cost: 50, image: UIImage.init(named: "cappuccino")!)
  let cookies      = Offer(name: "Cookies",        description: "Lorem ipsum good coffee template mate", cost: 60, image: UIImage.init(named: "cookies")!)
  
  return [espresso, chocolate, latte, white_coffee, cappuccino, cookies]
}
