//
//  CCICharacter.h
//  SWF
//
//  Created by Siarhei Fedartsou on 05.08.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#ifndef __SWF__CCICharacter__
#define __SWF__CCICharacter__

#include "CCIMovieTag.h"

class CCICharacter : public CCIMovieTag
{
public:
    CCICharacter(CCIBufferReader *reader,int tagType,int tagLength);
protected:
    UI16        shapeId;
   
};

#endif /* defined(__SWF__CCICharacter__) */
