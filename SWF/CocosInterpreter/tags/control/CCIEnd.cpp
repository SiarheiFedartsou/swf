//
//  CCIEnd.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIEnd.h"

CCIEnd::CCIEnd(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength) {}
