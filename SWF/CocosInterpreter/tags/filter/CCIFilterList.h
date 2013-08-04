//
//  CCIFilterList.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIFilterList__
#define __SwfTest__CCIFilterList__

#include "CCIFilter.h"


class CCIFilterList {
public:
    CCIFilterList(CCIBufferReader * reader);
    virtual ~CCIFilterList();
    
public:
    UI8 NumberOfFilters;
    std::vector<CCIFilter *> Filter;
    
};



#endif /* defined(__SwfTest__CCIFilterList__) */
