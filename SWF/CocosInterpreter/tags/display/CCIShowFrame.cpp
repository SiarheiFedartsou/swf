//
//  CCIShowFrame.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIShowFrame.h"


CCIShowFrame::CCIShowFrame(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength)
{
}

