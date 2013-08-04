//
//  CCIFillStyleArray.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCIFillStyleArray__
#define __CocosInterpreterTest__CCIFillStyleArray__


#include "CCIBufferReader.h"
#include "CCIFillStyle.h"

class CCIFillStyleArray {
public:
    CCIFillStyleArray(CCIBufferReader * reader);
    virtual ~CCIFillStyleArray();
    
public:
    int     styleCount;
    UI8     FillStyleCount;
    UI16    FillStyleCountExtended;
    std::vector<CCIFillStyle *> FillStyles;
    
};



#endif /* defined(__CocosInterpreterTest__CCIFillStyleArray__) */
