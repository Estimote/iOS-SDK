//
//  ViewController.swift
//  MonitoringExample-Swift
//
//  Created by Marcin Klimek on 09/01/15.
//  Copyright (c) 2015 Estimote. All rights reserved.
//

import UIKit

class ESTTableViewCell: UITableViewCell
{
    
    override init(style: UITableViewCellStyle, reuseIdentifier: String?)
    {
        
        super.init(style: UITableViewCellStyle.Subtitle, reuseIdentifier: reuseIdentifier)
    }
    
    required init(coder aDecoder: NSCoder)
    {
        fatalError("init(coder:) has not been implemented")
    }
}


class ViewController: UIViewController,
    UITableViewDelegate,
    UITableViewDataSource,
    ESTNearableManagerDelegate
{
    var nearables:Array<ESTNearable>!
    var nearableManager:ESTNearableManager!
    var tableView:UITableView!
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        self.title = "Pick Nearable to monitor for:";
        
        tableView = UITableView(frame: self.view.frame)
        tableView.delegate = self
        tableView.dataSource = self
        self.view.addSubview(tableView)
        
        tableView.registerClass(ESTTableViewCell.classForCoder(), forCellReuseIdentifier: "CellIdentifier")
        
        nearables = []
        nearableManager = ESTNearableManager()
        nearableManager.delegate = self
        nearableManager .startRangingForType(ESTNearableType.All)
    }
    
    func numberOfSectionsInTableView(tableView: UITableView) -> Int
    {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return nearables.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCellWithIdentifier("CellIdentifier", forIndexPath: indexPath) as ESTTableViewCell
        
        let nearable = nearables[indexPath.row] as ESTNearable
        var details:NSString = NSString(format:"Type: %@ RSSI: %zd", ESTNearableDefinitions.nameForType(nearable.type), nearable.rssi);
        cell.textLabel?.text = NSString(format:"Identifier: %@", nearable.identifier);
        cell.detailTextLabel?.text = details;
        
        var imageView = UIImageView(frame: CGRectMake(self.view.frame.size.width - 60, 30, 30, 30))
        imageView.contentMode = UIViewContentMode.ScaleAspectFill
        imageView.image = self.imageForNearableType(nearable.type)
        cell.contentView.addSubview(imageView)
        
        return cell
    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat
    {
        return 80
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath)
    {
        self.performSegueWithIdentifier("details", sender: indexPath)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?)
    {
        if(segue.identifier == "details")
        {
            var monitVC:MonitoringDetailsViewController = segue.destinationViewController as MonitoringDetailsViewController
            monitVC.nearable = self.nearables[(sender as NSIndexPath).row]
        }
    }
    
    // MARK: - ESTNearableManager delegate
    
    func nearableManager(manager: ESTNearableManager!, didRangeNearables nearables: [AnyObject]!, withType type: ESTNearableType)
    {
        self.nearables = nearables as Array<ESTNearable>
        self.tableView.reloadData()
    }
    
    func imageForNearableType(type: ESTNearableType) -> UIImage?
    {
        switch (type)
        {
        case ESTNearableType.Bag:
            return  UIImage(named: "sticker_bag")
        case ESTNearableType.Bike:
            return UIImage(named: "sticker_bike")
        case ESTNearableType.Car:
            return UIImage(named: "sticker_car")
        case ESTNearableType.Fridge:
            return UIImage(named: "sticker_fridge")
        case ESTNearableType.Bed:
            return UIImage(named: "sticker_bed")
        case ESTNearableType.Chair:
            return UIImage(named: "sticker_chair")
        case ESTNearableType.Shoe:
            return UIImage(named: "sticker_shoe")
        case ESTNearableType.Door:
            return UIImage(named: "sticker_door")
        case ESTNearableType.Dog:
            return UIImage(named: "sticker_dog")
        default:
            return UIImage(named: "sticker_grey")
        }
    }
}

