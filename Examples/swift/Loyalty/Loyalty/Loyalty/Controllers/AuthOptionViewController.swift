//
// Please report any problems with this app template to contact@estimote.com
//

let firstStartKey = "firstStartKey"

class AuthOptionViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    navigationItem.hidesBackButton = true
    
    if !UserDefaults.standard.bool(forKey: firstStartKey) {
      performSegue(withIdentifier: "showOnboarding", sender: self)
      UserDefaults.standard.set(true, forKey: firstStartKey)
    }
  }
  
  override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
    
    if segue.identifier == "SignUp" {
      let authViewController = segue.destination as! AuthViewController
      authViewController.mode = .signUp
    } else if segue.identifier == "LogIn" {
      let authViewController = segue.destination as! AuthViewController
      authViewController.mode = .logIn
    }
  }
}
