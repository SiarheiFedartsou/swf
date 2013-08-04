//
//  CCIFrameLabel.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIFrameLabel.h"

bool CCIFrameLabel::initWithReader(CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    this->name = reader->readString();
    
    return true;
}
std::string CCIFrameLabel::getName(){
    return this->name;
}
