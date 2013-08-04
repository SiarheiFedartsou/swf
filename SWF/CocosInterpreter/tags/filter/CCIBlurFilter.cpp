//
//  CCIBlurFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#include "CCIBlurFilter.h"

bool CCIBlurFilter::initWithFilterId(UI8 filterId, CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);
    
    this->BlurX = reader->readFIXED();
    this->BlurY = reader->readFIXED();
    
    reader->clearBits();
    this->Passes = reader->readUBits(5);
    this->Reserved = reader->readUBits(3);
    reader->clearBits();
    
    return true;
}
