//
//  IERContextSectionHeader.h
//  iEasyReminder
//
//  Created by Ding Orlando on 6/2/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IERContextSectionHeader : UIView

@property (nonatomic, weak) IBOutlet UIButton *mainButton;
@property (nonatomic, copy) void (^buttonTappedHandler)();

- (void) updateColorforCurrentLocation;

@end
