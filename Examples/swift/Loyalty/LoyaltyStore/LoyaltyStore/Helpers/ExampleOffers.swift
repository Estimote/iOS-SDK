//
// Please report any problems with this app template to contact@estimote.com
//
  
func exampleOffers() -> [Any] {
  
  let espresso     = Offer(name: "Extra Espresso", description: "", cost: 25, image: UIImage.init(named: "extra_espresso")!)
  let chocolate    = Offer(name: "Chocolate",      description: "", cost: 25, image: UIImage.init(named: "chocolate")!)
  let latte        = Offer(name: "Caffee Latte",   description: "", cost: 25, image: UIImage.init(named: "latte")!)
  let white_coffee = Offer(name: "White Coffee",   description: "", cost: 50, image: UIImage.init(named: "white_coffee")!)
  let cappuccino   = Offer(name: "Cappuccino",     description: "", cost: 50, image: UIImage.init(named: "cappuccino")!)
  let cookies      = Offer(name: "Cookies",        description: "", cost: 60, image: UIImage.init(named: "cookies")!)
  
  return [espresso, chocolate, latte, white_coffee, cappuccino, cookies]
}
