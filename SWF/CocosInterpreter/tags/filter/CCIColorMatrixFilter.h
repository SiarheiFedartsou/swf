//
//  CCIColorMatrixFilter.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIColorMatrixFilter__
#define __SwfTest__CCIColorMatrixFilter__

#include "CCIFilter.h"

class CCIColorMatrixFilter : public CCIFilter{
public:
    virtual bool initWithFilterId(UI8 filterId,CCIBufferReader * reader);
public:
    FLOAT Matrix[20];
};

#endif /* defined(__SwfTest__CCIColorMatrixFilter__) */
