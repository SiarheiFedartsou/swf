//
//  CCIFrameLabel.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIFrameLabel.h"

CCIFrameLabel::CCIFrameLabel(CCIBufferReader *reader, int tagType, int tagLength) :
    CCIMovieTag(reader, tagType, tagLength)
{
    this->name = reader->readString();
}

std::string CCIFrameLabel::getName(){
    return this->name;
}
