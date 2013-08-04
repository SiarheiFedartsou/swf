//
//  CCISetBackgroundColor.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCISetBackgroundColor.h"
#include "CCIRGB.h"

bool CCISetBackgroundColor::initWithReader(CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    CCIRGB * rgb = new CCIRGB(reader);
    this->backgroundColor = rgb->getColor();
    return true;
}

