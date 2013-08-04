//
//  CCIRemoveObject.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIRemoveObject__
#define __CocosInterpreterTest__CCIRemoveObject__

#include "CCIMovieTag.h"


class CCIRemoveObject : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    UI16    getDepth();
protected:
    UI16    characterId;
    UI16    depth;
};



#endif /* defined(__CocosInterpreterTest__CCIRemoveObject__) */
