//
//  CCISetBackgroundColor.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterTest__CCISetBackgroundColor__
#define __CocosInterpreterTest__CCISetBackgroundColor__

#include "CCITypes.h"
#include "CCIMovieTag.h"
#include "CCITypes.h"


class CCISetBackgroundColor : public CCIMovieTag{
public:
    CCISetBackgroundColor(CCIBufferReader *reader,int tagType,int tagLength);

private:
    RGBA backgroundColor;
    
};



#endif /* defined(__CocosInterpreterTest__CCISetBackgroundColor__) */
