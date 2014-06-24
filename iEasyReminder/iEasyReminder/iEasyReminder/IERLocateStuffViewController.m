//
//  IERLocateStuffViewController.m
//  iEasyReminder
//
//  Created by Ding, Orlando on 6/19/14.
//  Copyright (c) 2014 Ding Orlando. All rights reserved.
//

#import "IERLocateStuffViewController.h"
#import "MapViewController.h"
#import "LocatedViewController.h"

@interface IERLocateStuffViewController ()

//see : UIScrollView Control and page control
@property (nonatomic, strong) IBOutlet UIScrollView* scrollView;
@property (nonatomic, strong) IBOutlet UIPageControl* pageControl;

@property (nonatomic, strong) NSMutableArray *viewControllers;

@end

@implementation IERLocateStuffViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Do any additional setup after loading the view.
    self.title = self.strStuffKey;
    /** invalid code
    if (!self.isInCurrentCity) {
        self.navigationItem.backBarButtonItem.tintColor = [UIColor redColor];
    }
    else{
        self.navigationItem.backBarButtonItem.tintColor = [UIColor purpleColor];
    }
    */
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemSearch target:self action:@selector(performIdentifyStuffLocation:)];
    
    // view controllers are created pre-created
    NSMutableArray *controllers = [[NSMutableArray alloc] init];
    [controllers addObject:[MapViewController new]];
    [controllers addObject:[LocatedViewController new]];
    self.viewControllers = controllers;
    
    // pages are created on demand
    // load the visible page
    // load the page on either side to avoid flashes when the user starts scrolling
    //
    [self loadScrollViewWithPage:0];
    [self loadScrollViewWithPage:1];
}

- (void)viewWillAppear:(BOOL)animated{
    if (self.isInCurrentCity) {
        //see color for incity case
        self.navigationController.navigationBar.tintColor = [UIColor colorWithRed:1.000 green:0.204 blue:0.919 alpha:1.000];
    }
    else{
        //see disable rightbuttonItem
        self.navigationItem.rightBarButtonItem.enabled = NO;
    }
}

- (void)viewWillDisappear:(BOOL)animated{
    if (self.isInCurrentCity) {
        //see recovery for incity case
        self.navigationController.navigationBar.tintColor = [UIColor whiteColor];
    }
    else{
        //see enable rightbuttonItem
        self.navigationItem.rightBarButtonItem.enabled = YES;
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)performIdentifyStuffLocation: (id)paramSender{
    
}

- (void)loadScrollViewWithPage:(NSUInteger)page
{
    if (page >= self.viewControllers.count)
        return;
    
    // replace the placeholder if necessary
    UIViewController *controller = [self.viewControllers objectAtIndex:page];
    [self.viewControllers replaceObjectAtIndex:page withObject:controller];
    
    // add the controller's view to the scroll view
    if (controller.view.superview == nil)
    {
        CGRect frame = self.scrollView.frame;
        frame.origin.x = CGRectGetWidth(frame) * page;
        frame.origin.y = 0;
        controller.view.frame = frame;
        
        [self addChildViewController:controller];
        [self.scrollView addSubview:controller.view];
        [controller didMoveToParentViewController:self];
    }
}


#pragma mark - UIInterfaceOrientationMaskLandscape

-(NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortraitUpsideDown;
}

-(BOOL)shouldAutorotate
{
    return NO;
}

@end
