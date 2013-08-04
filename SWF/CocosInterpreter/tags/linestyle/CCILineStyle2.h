//
//  CCILineStyle2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCILineStyle2__
#define __CocosInterpreterTest__CCILineStyle2__

#include "CCIBufferReader.h"
#include "CCITypes.h"
#include "CCIFillStyle.h"
#include "CCILineStyle.h"

class CCILineStyle2 :public CCILineStyle{
public:
    CCILineStyle2(CCIBufferReader * reader);
    virtual ~CCILineStyle2();
public:
    UI16    Width;
    UI8     StartCapStyle;
    UI8     JoinStyle;
    UI8     HasFillFlag;
    UI8     NoHScaleFlag;
    UI8     NoVScaleFlag;
    UI8     PixelHintingFlag;
    UI8     Reserved;
    UI8     NoClose;
    UI8     EndCapStyle;
    UI16    MiterLimitFactor;
    
    
    RGBA Color;
    CCIFillStyle * FillType;
};


#endif /* defined(__CocosInterpreterTest__CCILineStyle2__) */
