//
//  CCIEnd.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIEnd.h"


bool CCIEnd::initWithReader(CCIBufferReader *reader, int tagType, int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    return true;
}
