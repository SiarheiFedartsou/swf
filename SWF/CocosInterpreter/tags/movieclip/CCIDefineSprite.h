//
//  CCIDefineSprite.h
//  SwfTest
//
//  Created by Wu Tong on 13-4-25.
//
//

#ifndef __SwfTest__CCIDefineSprite__
#define __SwfTest__CCIDefineSprite__
#include "CCIMovieTag.h"

class CCIDefineSprite : public CCIMovieTag {
public:
    CCIDefineSprite(CCIBufferReader *reader,int tagType,int tagLength);
    virtual ~CCIDefineSprite();
    
    std::vector<CCIMovieTag *> getControlTags();
    UI16 getSpriteId();
private:
    UI16 spriteId;
    UI16 frameCount;
    
    std::vector<CCIMovieTag *> controlTags;
};


#endif /* defined(__SwfTest__CCIDefineSprite__) */
