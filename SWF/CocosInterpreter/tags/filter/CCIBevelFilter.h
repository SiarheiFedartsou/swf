//
//  CCIBevelFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#ifndef __SwfTest__CCIBevelFilter__
#define __SwfTest__CCIBevelFilter__

#include "CCIFilter.h"
#include "CCIRGBA.h"


class CCIBevelFilter : public CCIFilter{
public:
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
    virtual ~CCIBevelFilter();
public:
    CCIRGBA * ShadowColor;
    CCIRGBA * HighlightColor;
    
    FIXED BlurX;
    FIXED BlurY;
    FIXED Angle;
    FIXED Distance;
    FIXED8 Strength;
    
    UI8 InnerShadow;
    UI8 Knockout;
    UI8 CompositeSource;
    UI8 OnTop;
    UI8 Passes;
    
};


#endif /* defined(__SwfTest__CCIBevelFilter__) */
