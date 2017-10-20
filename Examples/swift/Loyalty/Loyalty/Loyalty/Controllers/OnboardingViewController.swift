//
// Please report any problems with this app template to contact@estimote.com
//

enum OnboardingScreens: Int {
  case collectPoints
  case beacons
  case earnPoints
}

class OnboardingViewController: UIViewController {
  
  @IBOutlet var scrollView          : UIScrollView!
  @IBOutlet weak var pageController : UIPageControl!

  @objc var scrollViewConfigured = false
  
  override func viewDidLoad() {
    super.viewDidLoad()
  }
  
  override func viewDidLayoutSubviews() {
    super.viewDidLayoutSubviews()
    
    if (!scrollViewConfigured) {
      let screenRange = 0..<3 // <3 <3 <3
      // generate onboarding views
      for screenIndex in screenRange {
        // init
        let onboardinView = self.initOnboardingScreen(screenIndex)
        // add
        self.scrollView.addSubview(onboardinView)
      }
      
      // final config
      self.scrollView.contentSize = CGSize(width: self.scrollView.frame.width * 3, height: self.scrollView.frame.height)
      self.scrollView.delegate    = self
      self.scrollViewConfigured   = true
    }
  }
  
  @objc func initOnboardingScreen(_ screenIndex: Int) -> OnboardingView {
    // get height & width
    let width  = self.scrollView.frame.width
    let height = self.scrollView.frame.height
    
    // instantiate onboarding view
    let onboardingScreen = Bundle.main.loadNibNamed("OnboardingView", owner: nil, options: nil)![0] as! OnboardingView
    onboardingScreen.frame = CGRect(x: width * screenIndex._CGFloat, y: 0, width: width, height: height)
    
    guard let screen = OnboardingScreens.init(rawValue: screenIndex) else { fatalError("Invalid onboarding screen index") }
    
    // init screen title, description & image
    switch screen {
      case .collectPoints:
        onboardingScreen.slideTitle.text       = "Collect points and get rewards!"
        onboardingScreen.slideDescription.text = "Get rewarded for visiting your favourite shops and businesses."
        onboardingScreen.slideImage.image      = UIImage.init(named: "page1")
        return onboardingScreen
      case .beacons:
        onboardingScreen.slideTitle.text       = "We use Beacons"
        onboardingScreen.slideDescription.text = "Extremely easy! We connect with Bluetooth Beacons and the cashier charges your account!"
        onboardingScreen.slideImage.image      = UIImage.init(named: "Onboarding2")
        return onboardingScreen
      case .earnPoints:
        onboardingScreen.slideTitle.text       = "Earn points"
        onboardingScreen.slideDescription.text = "Make shopping as usual in your favourite shop and redeem for free prizes!"
        onboardingScreen.slideImage.image      = UIImage.init(named: "page1")
        return onboardingScreen
    }
  }
    
    @IBAction func getStartedAction(_ sender: AnyObject) {
        dismiss(animated: true, completion: nil)
    }
}

// dots on page controller
extension OnboardingViewController: UIScrollViewDelegate {
  func scrollViewDidEndDecelerating(_ scrollView: UIScrollView) {
    if scrollView == self.scrollView {
      pageController.currentPage = Int(floorf(Float(scrollView.contentOffset.x)/Float(scrollView.frame.size.width)))
    }
  }
}
