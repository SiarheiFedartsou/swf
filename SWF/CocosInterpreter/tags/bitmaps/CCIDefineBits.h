//
//  CCIDefineBits.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineBits__
#define __CocosInterpreterTest__CCIDefineBits__

#include "CCIImageTag.h"



class CCIDefineBits : public CCIImageTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
protected:
    virtual void loadImageData(UI8* imageData);
    virtual void decodeInfo(UI8* imageData);
    virtual int findJpegStart(UI8* imageData);
    int imageSize = 0;
    
    int swfVersion;
};



#endif /* defined(__CocosInterpreterTest__CCIDefineBits__) */
