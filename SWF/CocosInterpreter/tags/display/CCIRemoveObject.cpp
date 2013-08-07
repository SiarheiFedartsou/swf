//
//  CCIRemoveObject.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIRemoveObject.h"


CCIRemoveObject::CCIRemoveObject(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength)
{
    this->characterId = reader->readUI16();
    this->depth         = reader->readUI16();
}
UI16 CCIRemoveObject::getDepth(){
    return this->depth;
}
