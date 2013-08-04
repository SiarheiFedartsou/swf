//
//  CCILineStyleArray.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#ifndef __CocosInterpreterTest__CCILineStyleArray__
#define __CocosInterpreterTest__CCILineStyleArray__


#include "CCIBufferReader.h"
#include "CCILineStyle.h"


class CCILineStyleArray {
public:
    CCILineStyleArray(CCIBufferReader * reader);
    virtual ~CCILineStyleArray();
 
public:
    int styleCount;
    UI8     LineStyleCount;
    UI16    LineStyleCountExtended;
    std::vector<CCILineStyle *> LineStyles;
};



#endif /* defined(__CocosInterpreterTest__CCILineStyleArray__) */
