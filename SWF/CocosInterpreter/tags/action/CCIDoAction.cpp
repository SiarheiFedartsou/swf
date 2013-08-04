//
//  CCIDoAction.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#include "CCIDoAction.h"


bool CCIDoAction::initWithReader(CCIBufferReader *reader, int tagType, int tagLength){
    CCIMovieTag::initWithReader(reader, tagType, tagLength);
    
    
    return true;
}
