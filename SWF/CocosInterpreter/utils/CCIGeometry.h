//
//  CCIGeometry.h
//  SWF
//
//  Created by Siarhei Fedartsou on 02.08.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#ifndef __SWF__CCIGeometry__
#define __SWF__CCIGeometry__

#include "CCIBufferReader.h"

struct CCISize {
    CCISize(float w_, float h_) : width(w_), height(h_) {}
    CCISize() : width(0), height(0) {}
    
    float width;
    float height;
};

struct CCIPoint {
    CCIPoint(float x_, float y_) : x(x_), y(y_) {}
    CCIPoint() : x(0), y(0) {}
    
    float x;
    float y;
};

class CCIRect{
public:
    CCIRect(CCIBufferReader * reader);
    
    int getWidth();
    int getHeight();
    
    CCISize getSize();
    CCIPoint getAnchorPoint();
    
    CCIPoint convertToCCSpace(int x,int y);
public:
    UI32 Nbits;
    int Xmin;
    int Xmax;
    int Ymin;
    int Ymax;
private:
    int width;
    int height;
};

#endif /* defined(__SWF__CCIGeometry__) */
