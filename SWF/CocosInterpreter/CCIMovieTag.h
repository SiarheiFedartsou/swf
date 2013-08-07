//
//  CCIMovieTag.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreter__CCIMovieTag__
#define __CocosInterpreter__CCIMovieTag__

#include "CCIBufferReader.h"



enum TagType {
    TagTypeDefineBitsJPEG4 = 90,
    TagTypeDefineShape4 = 83,
    TagTypePlaceObject3 = 70,
    TagTypeFileAtrributes = 69,
    TagTypeFrameLabel = 43,
    TagTypeDefineSprite = 39,
    TagTypeDefineBitsLossless2 = 36,
    TagTypeDefineBitsJPEG3 = 35,
    TagTypeDefineShape3 = 32,
    TagTypeRemoveObject2 = 28,
    TagTypePlaceObject2 = 26,
    TagTypeDefineShape2 = 22,
    TagTypeDefineBitsJPEG2 = 21,
    TagTypeDefineBitsLossless = 20,
    TagTypeSetBackgroundColor = 9,
    
    TagTypeJPEGTables = 8,
    TagTypeDefineBits = 6,
    TagTypeRemoveObject = 5,
    TagTypePlaceObject = 4,
    TagTypeDefineShape = 2,
    TagTypeShowFrame = 1,
    TagTypeEnd = 0,
};


class CCIMovieTag{
protected:
    int tagType = 0;
    int tagLength;
    
public:
    virtual bool isCharacter() { return false; };
    
    int getTagType();
    static CCIMovieTag * next(CCIBufferReader *reader);
    
    
    CCIMovieTag(CCIBufferReader *reader,int tagType,int tagLength);
    virtual ~CCIMovieTag();
};



#endif /* defined(__CocosInterpreterTest__CCIMovieTag__) */
