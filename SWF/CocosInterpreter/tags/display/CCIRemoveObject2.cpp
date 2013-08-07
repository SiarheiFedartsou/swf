//
//  CCIRemoveObject2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIRemoveObject2.h"


CCIRemoveObject2::CCIRemoveObject2(CCIBufferReader *reader,int tagType,int tagLength)
: CCIRemoveObject(reader, tagType, tagLength)
{
    this->depth         = reader->readUI16();
}

