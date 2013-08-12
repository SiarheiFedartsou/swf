//
//  CCTest.m
//  SWF
//
//  Created by Siarhei Fedartsou on 31.07.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#import "CCTest.h"
#import <MonkVG/openvg.h>
#import <MonkVG/vgext.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <OpenGLES/EAGL.h>

#include "CCIMovie.h"
#include "CCIDefineShape4.h"

@interface CCSWFDisplayList : NSObject
{
    std::vector<CCIPlaceObject*> placeObjects_;
}

@end

@interface VG : CCNode

@end

@implementation VG{
    VGPath	_path;
    VGPath	_path2;
	VGPaint _paint;
	VGPaint _linearGradientPaint;
	VGPaint _radialGradientPaint;
	VGImage _image;
	VGImage	_bitmapFont;
	//	VGImage _gradientImage;
	VGPath _linearGradientPath;
	VGPath _radialGradientPath;
	VGFont	_font;
	VGfloat _lineHeight;
    
    CCIMovie* movie;
    
}

- (id) init
{
    if (self = [super init]) {
        NSString* s= [[NSBundle mainBundle] pathForResource:@"test" ofType:@"swf"];
        
        movie = new CCIMovie([s UTF8String]);
        movie->nextFrame();
        
        vgCreateContextMNK(320, 480, VG_RENDERING_BACKEND_TYPE_OPENGLES20);
        
//        _paint = vgCreatePaint();
//		vgSetPaint(_paint, VG_FILL_PATH );
//		
//		VGfloat color[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
//		vgSetParameterfv(_paint, VG_PAINT_COLOR, 4, &color[0]);
//		
//		_path = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,1,0,0,0, VG_PATH_CAPABILITY_ALL);
//        vgClearPath(_path, VG_PATH_CAPABILITY_ALL);
//        vguRect( _path, 50.0f, 50.0f, 100.0f, 100.0f );
//        
//        _path2 = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,1,0,0,0, VG_PATH_CAPABILITY_ALL);
//        vgClearPath(_path2, VG_PATH_CAPABILITY_ALL);
//        vguEllipse( _path2, 250.0f, 50.0f, 100.0f, 100.0f );
//		//vguLine( _path, 0.0f, 0.0f, 90.0f, 90.0f );
//		//vguRoundRect( _path, 50.0f, 50.0f, 100.0f, 100.0f, 60, 60 );
//		vgSetf( VG_STROKE_LINE_WIDTH, 7.0f );
    }
    return self;
}

- (void) onEnter
{
    [super onEnter];
    
    CCIMovieHeader* header = movie->getHeader();
    
    [self schedule:@selector(updateNextFrame) interval:1.0 / header->getFrameRate()];
}

- (void) onExit
{
    [super onExit];
}

- (void) updateNextFrame
{
    
}

- (void) draw
{
   // CCIDefineShape4* shape = (CCIDefineShape4*)movie->tags[3];
  //  shape->draw();
//    VGfloat x[9];
//    
//    vgGetMatrix(x);
//    kmGLPushMatrix();
//    
//    
//    
//    VGint backingWidth = vgGeti( VG_SURFACE_WIDTH_MNK );
//    VGint backingHeight = vgGeti( VG_SURFACE_HEIGHT_MNK );;
//    
//   // glEnable(GL_LINE_STRIP);
// //   VGfloat clearColor[] = {1,1,1,1};
////	vgSetfv(VG_CLEAR_COLOR, 4, clearColor);
//	//vgClear(0,0,backingWidth,backingHeight);
//	
//	vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
//	vgLoadIdentity();
//	vgTranslate( 0, backingHeight/2 );
//	vgSetPaint( _paint, VG_FILL_PATH );
//	//vgDrawPath( _path, VG_FILL_PATH );
//    
//    vgDrawPath( _path2, VG_FILL_PATH );
//    
//    //vgLoadIdentity();
//    
//    kmGLPopMatrix();
//    
//    vgLoadMatrix(x);
    
    
}

@end


@implementation CCTest

- (void) onEnter
{
    [super onEnter];
    VG* vg = [VG node];
    [self addChild:vg];
    
    CCSprite* sprite = [CCSprite spriteWithFile:@"test.jpeg"];
    sprite.position = ccp(160, 240);
    [self addChild:sprite];
}

@end
