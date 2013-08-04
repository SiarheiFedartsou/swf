//
//  CCIGradRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIGradRecord__
#define __CocosInterpreterTest__CCIGradRecord__


#include "CCIBufferReader.h"
#include "CCIRGBA.h"


class CCIGradRecord {
public:
    CCIGradRecord(CCIBufferReader * reader);
public:
    UI8 Ratio;
    RGBA Color;
};


#endif /* defined(__CocosInterpreterTest__CCIGradRecord__) */
