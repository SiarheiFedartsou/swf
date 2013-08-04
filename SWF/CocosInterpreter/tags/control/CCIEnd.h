//
//  CCIEnd.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIEnd__
#define __SwfTest__CCIEnd__
#include "CCIMovieTag.h"

class CCIEnd :public CCIMovieTag {
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
public:
    
};



#endif /* defined(__SwfTest__CCIEnd__) */
