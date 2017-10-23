//
// Please report any problems with this app to contact@estimote.com
//

import UIKit

/**
This class controls the flow when developer uses one of GPIO ports as output.
*/

class OutputViewController: UIViewController {
    
    // MARK: IBOutlets
    
    @IBOutlet weak var lightbulbOnImage: UIImageView!
    @IBOutlet weak var lightbulbOffImage: UIImageView!
    @IBOutlet weak var lightbulbStatusLabel: UILabel!
    @IBOutlet weak var lightbulbSwitch: UIButton!
    
    // MARK: Class properties
    
    /** TODO: Replace with identifier of your beacon.
     You can find identifiers of your beacons at https://cloud.estimote.com/#/beacons
     */
    let deviceUsedForOutputIdentifier: String = "B34C0N-1-CL0UD-1D3NT1F13R"
    
    var deviceUsedForOutput: ESTDeviceLocationBeacon?
    
    lazy var deviceManagerForOutput: ESTDeviceManager = {
        let manager = ESTDeviceManager()
        manager.delegate = self
        return manager
    }()
    
    enum LightBulbState {
        case on, off
    }
    
    var currentLightbulbState = LightBulbState.off {
        didSet {
            if currentLightbulbState == .off {
                self.lightbulbOnImage.alpha = 0
                self.lightbulbSwitch.setImage(UIImage(named: "switchOff"), for: .normal)
                self.lightbulbStatusLabel.text = "Your light is off"
            } else if currentLightbulbState == .on {
                self.lightbulbOnImage.alpha = 1
                self.lightbulbSwitch.setImage(UIImage(named: "switchOn"), for: .normal)
                self.lightbulbStatusLabel.text = "Your light is on"
            }
        }
    }
    
    // MARK: ViewController's lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let beaconFilter = ESTDeviceFilterLocationBeacon(identifier: self.deviceUsedForOutputIdentifier)
        self.deviceManagerForOutput.startDeviceDiscovery(with: beaconFilter)
        self.currentLightbulbState = .off
    }
    
    // MARK: Core logic
    
    func changeBeaconPortOneState(_ beacon: ESTDeviceLocationBeacon, portOneSetStateTo: ESTGPIOPortValue) {
        let portsData = ESTGPIOPortsData(port0Value: ESTGPIOPortValue.high, port1Value: portOneSetStateTo)
        beacon.settings?.gpio.portsData.writeValue(portsData) { (data, error) in
            switch portOneSetStateTo {
            case .high:
                portsData.setPort(ESTGPIOPort.port1, value: ESTGPIOPortValue.high)
                self.currentLightbulbState = .on
            case .low:
                portsData.setPort(ESTGPIOPort.port1, value: ESTGPIOPortValue.low)
                self.currentLightbulbState = .off
            case .unknown:
                print("GPIO State: Unknown")
            }
        }
    }
    
    func setPortOneStateBasedOnBeaconStatus(_ beacon: ESTDeviceLocationBeacon) {
        if beacon.connectionStatus == .connecting {
            let popUp = UIAlertController(title: "Searching for beacons", message: "Looks like you're not connected to the beacon yet. Give us just a second!", preferredStyle: UIAlertControllerStyle.alert)
            let popUpAction = UIAlertAction(title: "Sure", style: UIAlertActionStyle.default, handler: nil)
            popUp.addAction(popUpAction)
            self.present(popUp, animated: true, completion: nil)
        } else {
            switch self.currentLightbulbState {
            case .off:
                self.changeBeaconPortOneState(deviceUsedForOutput!, portOneSetStateTo: ESTGPIOPortValue.high)
            case .on:
                self.changeBeaconPortOneState(deviceUsedForOutput!, portOneSetStateTo: ESTGPIOPortValue.low)
            }
        }
    }
    
    @IBAction func lightbulbSwitchClicked(_ sender: Any) {
        self.setPortOneStateBasedOnBeaconStatus(self.deviceUsedForOutput!)
    }

}

// MARK: ESTDeviceManagerDelegate and ESTDeviceConnectableDelegate methods

extension OutputViewController: ESTDeviceManagerDelegate, ESTDeviceConnectableDelegate {
    
    func deviceManager(_ manager: ESTDeviceManager, didDiscover devices: [ESTDevice]) {
        guard let device = devices.first as? ESTDeviceLocationBeacon else { return }
        self.deviceManagerForOutput.stopDeviceDiscovery()
        self.deviceUsedForOutput = device
        self.deviceUsedForOutput?.delegate = self
        self.deviceUsedForOutput?.connect()
    }
    
    func estDeviceConnectionDidSucceed(_ device: ESTDeviceConnectable) {
        print("Connection Output Status: Connected")
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didFailConnectionWithError error: Error) {
        print("Connection Output Status: \(error.localizedDescription)")
    }
    
    func estDevice(_ device: ESTDeviceConnectable, didDisconnectWithError error: Error?) {
        print("Connection Output Status: Disconnected")
    }
}
