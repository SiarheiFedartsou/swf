//
//  CCISetBackgroundColor.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCISetBackgroundColor.h"
#include "CCIRGB.h"

CCISetBackgroundColor::CCISetBackgroundColor(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength)
{
    CCIRGB * rgb = new CCIRGB(reader);
    this->backgroundColor = rgb->getColor();
}

