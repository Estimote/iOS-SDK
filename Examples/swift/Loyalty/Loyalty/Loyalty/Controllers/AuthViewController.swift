//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit
import Firebase
import ImagePicker

enum AuthViewControllerMode {
  case logIn
  case signUp
}

let cellIdentifier = "AuthCell"

class AuthViewController: UIViewController {
  
  @IBOutlet weak var tableView: UITableView!
  @IBOutlet weak var tableViewHeightConstraint: NSLayoutConstraint!
  @IBOutlet weak var tableViewVerticalCenterConstraint: NSLayoutConstraint!
  @IBOutlet weak var authButton: UIButton!
  @IBOutlet weak var cameraButton: UIButton!
  @IBOutlet weak var additionalInfoLabel: UILabel!
  
  @objc var avatar: UIImage!
  var customer: Customer!
  @objc var launchScreen: UIView!
  
  var mode:AuthViewControllerMode = .signUp
  
  @objc var nameCellRow = 0
  @objc var emailCellRow:Int {
    switch mode {
      case .logIn:
        return 0
      case .signUp:
        return 1
    }
  }
  @objc var passwordCellRow:Int {
    switch mode {
      case .logIn:
        return 1
      case .signUp:
        return 2
    }
    
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    NotificationCenter.default.addObserver(self, selector: #selector(AuthViewController.reactToKeyboardPresence(_:)), name: NSNotification.Name.UIKeyboardWillChangeFrame, object: nil)
    
    switch mode {
      case .logIn:
        self.title = "Log in"
        tableViewHeightConstraint.constant = 120
        authButton.setTitle("Log In", for: UIControlState())
        cameraButton.isHidden = true
        additionalInfoLabel.isHidden = true
      case .signUp:
        self.title = "Register"
        tableViewHeightConstraint.constant = 180
        authButton.setTitle("Sign Up", for: UIControlState())
        cameraButton.isHidden = false
        additionalInfoLabel.isHidden = false
    }
    
    view.setNeedsLayout()
  }
  
  override func viewDidLayoutSubviews() {
    super.viewDidLayoutSubviews()
    
    cameraButton.layer.cornerRadius = cameraButton.bounds.size.height/2
  }
  
  deinit {
    NotificationCenter.default.removeObserver(self)
  }
  
  override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
    
    if segue.identifier == "showCustomer" {
      
      let customerVC = segue.destination as! CustomerViewController
      
      // pass customer
      customerVC.customer = self.customer
    }
  }
  
  @IBAction func tapGestureRecognizerAction(_ sender: AnyObject) {
    self.view.endEditing(true)
  }
  
  // MARK: Authorisation
  @IBAction func authButtonAction(_ sender: AnyObject) {
    
    // get necessary info for log in / sign up
    let nameTextField = tableView.cellForRow(at: IndexPath(row: nameCellRow, section: 0))?.viewWithTag(1) as! UITextField
    let emailTextField = tableView.cellForRow(at: IndexPath(row: emailCellRow, section: 0))?.viewWithTag(1) as! UITextField
    let passwordTextField = tableView.cellForRow(at: IndexPath(row: passwordCellRow, section: 0))?.viewWithTag(1) as! UITextField
    
    guard let name = nameTextField.text, let email = emailTextField.text, let password = passwordTextField.text else {
      ErrorHandler.displayError("You need to fill all values ⌨", subtitle: nil, viewController: self)
      return
    }
    
    customer = Customer()
    
    switch mode {
    case .signUp:
      // force create avatar
      if (self.avatar == nil && mode == .signUp) {
        ErrorHandler.displayError("You forgot to create an avatar 😅", subtitle: nil, viewController: self)
        return
      }
      
      // don't allow less than 4 character name
      if (name.characters.count < 4 && mode == .signUp) {
        ErrorHandler.displayError("Your name needs to have at least 4️⃣ characters 🤖", subtitle: nil, viewController: self)
        return
      }
      
      // don't allow less than 6 character password
      if (password.characters.count < 6 && mode == .signUp) {
        ErrorHandler.displayError("Your password needs to have at least 6️⃣ characters 🤖", subtitle: nil, viewController: self)
        return
      }
      
      _ = customer.singUp(email, password: password, avatar: self.avatar, name: name).then { customer -> Void in
        self.customer = customer
        self.performSegue(withIdentifier: "showCustomer", sender: self)
      }
    case .logIn :
      _ = customer.logIn(email, password: password).then { customer -> Void in
        self.customer = customer
        self.performSegue(withIdentifier: "showCustomer", sender: self)
      }
    }
  }
  
  @IBAction func presentImagePicker(_ sender: AnyObject) {
    // instantiate image picker
    let imagePickerController = ImagePickerController()
    
    // set image limit and delegate
    imagePickerController.imageLimit = 1
    imagePickerController.delegate   = self
    
    // persent image picker animated
    self.present(imagePickerController, animated: true, completion: nil)
  }
  
  // MARK: Keyboard notifications
  @objc func reactToKeyboardPresence(_ notification:Notification) {
    
    let keyboardRect = (notification.userInfo![UIKeyboardFrameEndUserInfoKey]! as! CGRect)
    
    let originalTableViewBottomYCoordinate = view.frame.height/2 + tableView.frame.height/2 + 80
    
    if keyboardRect.origin.y <= originalTableViewBottomYCoordinate {
      tableViewVerticalCenterConstraint.constant = -(originalTableViewBottomYCoordinate - keyboardRect.origin.y)
    } else {
      tableViewVerticalCenterConstraint.constant = 0
    }
    
    UIView.animate(withDuration: 5, animations: {
      self.view.layoutIfNeeded()
    })
  }
}

// MARK: Image picker
extension AuthViewController: ImagePickerDelegate {
  func wrapperDidPress     (_ imagePicker: ImagePickerController, images: [UIImage]) { }
  func cancelButtonDidPress(_ imagePicker: ImagePickerController) { }
  func doneButtonDidPress  (_ imagePicker: ImagePickerController, images: [UIImage]) {
    
    // dismiss image picker
    imagePicker.dismiss(animated: true, completion: nil)
    
    // get the avatar image
    guard let img = images.first else {
      ErrorHandler.displayError("You need to create the avatar again, sorry 😓", subtitle: nil, viewController: self)
      return
    }
    
    // cropp & retain avatar image
    self.avatar = AvatarCropp.cropp(img)
    
    self.cameraButton.setBackgroundImage(self.avatar, for: UIControlState())
  }
}

// MARK: Table View
extension AuthViewController: UITableViewDelegate, UITableViewDataSource {
  
  func numberOfSections(in tableView: UITableView) -> Int {
    return 1
  }
  
  func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    switch mode {
      case .logIn:
        return 2
      case .signUp:
        return 3
    }
  }
  
  func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
    return 60
  }
  
  func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    
    let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier)!
    
    let textField = cell.viewWithTag(1) as! UITextField
    textField.delegate = self
    
    if mode == .signUp {
      switch indexPath.row {
        case nameCellRow:
          textField.placeholder     = "Your name"
        case emailCellRow:
          textField.placeholder     = "Email address"
          textField.keyboardType    = .emailAddress
        case passwordCellRow:
          textField.placeholder     = "Password"
          textField.isSecureTextEntry = true
        default:
          textField.placeholder     = ""
      }
    } else if mode == .logIn {
      switch indexPath.row {
        case emailCellRow:
          textField.placeholder     = "Email address"
          textField.keyboardType    = .emailAddress
        case passwordCellRow:
          textField.placeholder     = "Password"
          textField.isSecureTextEntry = true
        default:
          textField.placeholder     = ""
      }
    }
    
    return cell
  }
}

extension AuthViewController: UITextFieldDelegate {
  
  func textFieldShouldReturn(_ textField: UITextField) -> Bool {
    
    textField.resignFirstResponder()
    return true
  }
}
