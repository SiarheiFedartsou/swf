//
//  CCIShowFrame.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIShowFrame__
#define __CocosInterpreterTest__CCIShowFrame__


#include "CCIMovieTag.h"


class CCIShowFrame : public CCIMovieTag{
public:
    CCIShowFrame(CCIBufferReader *reader,int tagType,int tagLength);

};



#endif /* defined(__CocosInterpreterTest__CCIShowFrame__) */
