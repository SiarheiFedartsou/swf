//
//  CCIShowFrame.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIShowFrame.h"


bool CCIShowFrame::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    return true;
}

