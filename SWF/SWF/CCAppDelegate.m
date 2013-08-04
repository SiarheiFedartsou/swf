//
//  CCAppDelegate.m
//  SWF
//
//  Created by Siarhei Fedartsou on 31.07.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#import "CCAppDelegate.h"

#import "CCTest.h"

@implementation CCAppDelegate

- (void)dealloc
{
    [_window release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    
    director_ = (CCDirectorIOS*)[CCDirector sharedDirector];
	[director_ setDisplayStats:YES];
	[director_ setAnimationInterval:1.0/60];
	
	// GL View
	CCGLView *__glView = [CCGLView viewWithFrame:[_window bounds]
									 pixelFormat:kEAGLColorFormatRGB565
									 depthFormat:0 /* GL_DEPTH_COMPONENT24_OES */
							  preserveBackbuffer:NO
									  sharegroup:nil
								   multiSampling:YES
								 numberOfSamples:4
						  ];
	
	[director_ setView:__glView];
	[director_ setDelegate:self];
	director_.wantsFullScreenLayout = YES;
    
	// Retina Display ?
	[director_ enableRetinaDisplay:useRetinaDisplay_];
    
    [self.window setRootViewController:director_];
    
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    [director_ runWithScene:[CCTest node]];
	
    
    return YES;
}

// getting a call, pause the game
-(void) applicationWillResignActive:(UIApplication *)application
{
    [director_ pause];
}

// call got rejected
-(void) applicationDidBecomeActive:(UIApplication *)application
{
	[[CCDirector sharedDirector] setNextDeltaTimeZero:YES];
	
    [director_ resume];
}

-(void) applicationDidEnterBackground:(UIApplication*)application
{
    [director_ stopAnimation];
}

-(void) applicationWillEnterForeground:(UIApplication*)application
{
    [director_ startAnimation];
}

// application will be killed
- (void)applicationWillTerminate:(UIApplication *)application
{
	CC_DIRECTOR_END();
}

// purge memory
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
	[director_ purgeCachedData];
}

// next delta time will be zero
-(void) applicationSignificantTimeChange:(UIApplication *)application
{
	[director_ setNextDeltaTimeZero:YES];
}
@end
