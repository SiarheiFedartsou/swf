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
#include "CCIDrawable.h"

class CCICharacter : public CCIMovieTag, public CCIDrawable
{
public:
    CCICharacter(CCIBufferReader *reader,int tagType,int tagLength);
    
    UI16 getCharacterId() { return characterId_; }
    
    virtual void  draw() {};
    
protected:
    UI16        characterId_;
   
};

#endif /* defined(__SWF__CCICharacter__) */
