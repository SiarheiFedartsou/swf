//
//  CCILineStyle.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCILineStyle__
#define __CocosInterpreterTest__CCILineStyle__

#include "CCIBufferReader.h"
#include "CCITypes.h"


class CCILineStyle {
public:
    CCILineStyle(CCIBufferReader * reader);
    CCILineStyle();
public:
    UI16    Width;
    RGBA Color;
};

#endif /* defined(__CocosInterpreterTest__CCILineStyle__) */
