//
//  CCIColorMatrixFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIColorMatrixFilter.h"


bool CCIColorMatrixFilter::initWithFilterId(UI8 filterId, CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);
    
    for (int i=0; i<20; i++) {
        this->Matrix[i] = reader->readFLOAT();
    }
    
    return true;
}
