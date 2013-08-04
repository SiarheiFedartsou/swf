//
//  CCIFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIFilter__
#define __SwfTest__CCIFilter__

#include "CCIBufferReader.h"


class CCIFilter {
public:
    static CCIFilter * next(CCIBufferReader * reader);
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
    
    virtual ~CCIFilter();
public:
    UI8 FilterID;
};




#endif /* defined(__SwfTest__CCIFilter__) */
