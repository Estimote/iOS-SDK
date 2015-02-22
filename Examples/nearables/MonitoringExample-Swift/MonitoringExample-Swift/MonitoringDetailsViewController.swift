//
//  MonitoringDetailsViewController.swift
//  MonitoringExample-Swift
//
//  Created by Marcin Klimek on 09/01/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

import UIKit

class MonitoringDetailsViewController: UIViewController, ESTNearableManagerDelegate
{
    var nearableManager:ESTNearableManager
    var nearable:ESTNearable

    @IBOutlet weak var enterSwitch: UISwitch!
    @IBOutlet weak var exitSwitch: UISwitch!
    
    required init(coder aDecoder: NSCoder)
    {
        self.nearable = ESTNearable()
        self.nearableManager = ESTNearableManager()
        
        super.init(coder: aDecoder)
        
        self.nearableManager.delegate = self;
    }
    
    override func viewDidLoad()
    {
        /**
        *  Setup title of the screen based on nearable type.
        */
        self.title = NSString(format: "Nearable: %@", ESTNearableDefinitions.nameForType(nearable.type))
        
        /**
        *  Create Estimote Nearable Manager and start looking for
        *  the nearable device selected on previous screen and keept
        *  as self.nearable property.
        */
        self.nearableManager.startMonitoringForIdentifier(self.nearable.identifier)
    }
    
    func nearableManager(manager: ESTNearableManager!, didEnterIdentifierRegion identifier: String!)
    {
        /**
        *  Verify if Enter switch is on, show local notification if ON.
        */
        if (self.enterSwitch.on)
        {
            var notification:UILocalNotification = UILocalNotification();
            notification.alertBody = "Enter region notification";
            
            UIApplication.sharedApplication().presentLocalNotificationNow(notification)
        }
    }
    
    func nearableManager(manager: ESTNearableManager!, didExitIdentifierRegion identifier: String!)
    {
        /**
        *  Verify if Exit switch is on, show local notification if ON.
        */
        if (self.exitSwitch.on)
        {
            var notification:UILocalNotification = UILocalNotification();
            notification.alertBody = "Exit region notification";
            
            UIApplication.sharedApplication().presentLocalNotificationNow(notification)
        }
    }

}
