//
//  CCIRGB.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIRGB__
#define __CocosInterpreterTest__CCIRGB__

#include "CCIBufferReader.h"

#include "CCITypes.h"


class CCIRGB {
public:
    CCIRGB(CCIBufferReader * reader);
    RGBA getColor();
public:
    UI8 Red;
    UI8 Green;
    UI8 Blue;
    UI8 Alpha;
};



#endif /* defined(__CocosInterpreterTest__CCIRGB__) */
