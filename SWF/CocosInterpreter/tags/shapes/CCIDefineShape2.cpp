//
//  CCIDefineShape2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineShape2.h"


bool CCIDefineShape2::initWithReader(CCIBufferReader *reader,int tagType,int tagLength){
    CCIDefineShape::initWithReader(reader, tagType, tagLength);
    
    return true;
}
