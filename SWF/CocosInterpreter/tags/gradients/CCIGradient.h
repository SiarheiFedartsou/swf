//
//  CCIGradient.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIGradient__
#define __CocosInterpreterTest__CCIGradient__
#include "CCIBufferReader.h"
#include "CCIGradRecord.h"


class CCIGradient {
public:
    CCIGradient(CCIBufferReader * reader);
    virtual ~CCIGradient();
public:
    UI8     SpreadMode;
    UI8     InterpolationMode;
    UI8     NumGradients;
    std::vector<CCIGradRecord *>    GradientRecords;
};


#endif /* defined(__CocosInterpreterTest__CCIGradient__) */
