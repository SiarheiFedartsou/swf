//
//  CCICharacter.cpp
//  SWF
//
//  Created by Siarhei Fedartsou on 05.08.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#include "CCICharacter.h"

CCICharacter::CCICharacter(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength)
{
    this->shapeId = reader->readUI16();
}