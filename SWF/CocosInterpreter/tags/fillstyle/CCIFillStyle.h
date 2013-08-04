//
//  CCIFillStyle.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIFillStyle__
#define __CocosInterpreterTest__CCIFillStyle__
#include "CCIBufferReader.h"
#include "CCITypes.h"
#include "CCIMatrix.h"
#include "CCIFocalGradient.h"


class CCIFillStyle{
public:
    CCIFillStyle(CCIBufferReader * reader);
    virtual ~CCIFillStyle();
public:
    UI8 FillStyleType;
    RGBA Color;
    CCIMatrix * GradientMatrix = NULL;
    
    
    UI16 BitmapId;
    CCIMatrix * BitmapMatrix = NULL;
    
    CCIGradient * Gradient = NULL;
};

#endif /* defined(__CocosInterpreterTest__CCIFillStyle__) */
