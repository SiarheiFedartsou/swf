//
//  CCAppDelegate.h
//  SWF
//
//  Created by Siarhei Fedartsou on 31.07.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "cocos2d.h"

@interface CCAppDelegate : UIResponder <UIApplicationDelegate>
{
    BOOL			useRetinaDisplay_;
	CCDirectorIOS	*director_;							// weak ref
}
@property (strong, nonatomic) UIWindow *window;

@end
