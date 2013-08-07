//
//  CCIMovieTag.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIMovieTag.h"
#include "CCIFileAttributes.h"
#include "CCISetBackgroundColor.h"
#include "CCIFrameLabel.h"


//#include "CCIDefineBitsLossless.h"
//#include "CCIDefineBitsLossless2.h"
//#include "CCIDefineBits.h"
//#include "CCIDefineBitsJPEG2.h"
//#include "CCIDefineBitsJPEG3.h"
//#include "CCIDefineBitsJPEG4.h"
//
//#include "CCIJPEGTables.h"

#include "CCIPlaceObject.h"
#include "CCIPlaceObject2.h"
#include "CCIPlaceObject3.h"
#include "CCIRemoveObject.h"
#include "CCIRemoveObject2.h"
#include "CCIShowFrame.h"


#include "CCIDefineShape.h"
#include "CCIDefineShape2.h"
#include "CCIDefineShape3.h"
#include "CCIDefineShape4.h"

#include "CCIDefineSprite.h"

#include "CCIEnd.h"

//#include "CCPlatformMacros.h"
//#include "CCCommon.h"

CCIMovieTag::CCIMovieTag(CCIBufferReader *reader, int tagType, int tagLength)
{
    this->tagType = tagType;
    this->tagLength = tagLength;
    
}

CCIMovieTag * CCIMovieTag::next(CCIBufferReader *reader)
{
    UI16 tagCodeAndLength = reader->readUI16();
    if (reader->mReachEnd) {
        return NULL;
    }
    int tagType = tagCodeAndLength>>6;
    int tagLength = (tagType<<6)^tagCodeAndLength;
    if (tagLength==63) {
        tagLength = reader->readUI32();
    }
    CCIMovieTag * tag = NULL;
    std::string logString;
    
    reader->begin(tagLength);
    reader->tagType = tagType;
    
    
    switch (tagType) {
        case TagTypeFileAtrributes:
            tag = new CCIFileAttributes(reader, tagType, tagLength);
            logString = "CCIFileAttributes";
            break;
        case TagTypeSetBackgroundColor:
            tag = new CCISetBackgroundColor(reader, tagType, tagLength);
            logString = "CCISetBackgroundColor";
            break;
        case TagTypeEnd:
            tag = new CCIEnd(reader, tagType, tagLength);
            logString = "CCIEnd";
            break;
        case TagTypeFrameLabel:
            tag = new CCIFrameLabel(reader, tagType, tagLength);
            logString = "CCIFrameLabel";
            break;
//        case TagTypeDefineBitsLossless:
//            tag = new CCIDefineBitsLossless();
//            logString = "CCIDefineBitsLossless";
//            break;
//        case TagTypeDefineBitsLossless2:
//            tag = new CCIDefineBitsLossless2();
//            logString = "CCIDefineBitsLossless2";
//            break;
//        case TagTypeDefineBits:
//            tag = new CCIDefineBits();
//            logString = "CCIDefineBits";
//            break;
//        case TagTypeDefineBitsJPEG2:
//            tag = new CCIDefineBitsJPEG2();
//            logString = "CCIDefineBitsJPEG2";
//            break;
//        case TagTypeDefineBitsJPEG3:
//            tag = new CCIDefineBitsJPEG3();
//            logString = "CCIDefineBitsJPEG3";
//            break;
//        case TagTypeDefineBitsJPEG4:
//            tag = new CCIDefineBitsJPEG4();
//            logString = "CCIDefineBitsJPEG4";
//            break;
//        case TagTypeJPEGTables:
//            tag = new CCIJPEGTables();
//            logString = "CCIJPEGTables";
//            break;
//         
        case TagTypePlaceObject:
            tag = new CCIPlaceObject(reader, tagType, tagLength);
            logString = "CCIPlaceObject";
            break;
        case TagTypePlaceObject2:
            tag = new CCIPlaceObject2(reader, tagType, tagLength);
            logString = "CCIPlaceObject2";
            break;
        case TagTypePlaceObject3:
            tag = new CCIPlaceObject3(reader, tagType, tagLength);
            logString = "CCIPlaceObject3";
            break;
        case TagTypeRemoveObject:
            tag = new CCIRemoveObject(reader, tagType, tagLength);
            logString = "CCIRemoveObject";
            break;
        case TagTypeRemoveObject2:
            tag = new CCIRemoveObject2(reader, tagType, tagLength);
            logString = "CCIRemoveObject2";
            break;
        case TagTypeShowFrame:
            tag = new CCIShowFrame(reader, tagType, tagLength);
            logString = "CCIShowFrame";
            break;
            
        case TagTypeDefineShape:
            tag = new CCIDefineShape(reader, tagType, tagLength);
            logString = "CCIDefineShape";
            break;
        case TagTypeDefineShape2:
            tag = new CCIDefineShape2(reader, tagType, tagLength);
            logString = "CCIDefineShape2";
            break;
        case TagTypeDefineShape3:
            tag = new CCIDefineShape3(reader, tagType, tagLength);
            logString = "CCIDefineShape3";
            break;
        case TagTypeDefineShape4:
            tag = new CCIDefineShape4(reader, tagType, tagLength);
            logString = "CCIDefineShape4";
            break;
        case TagTypeDefineSprite:
            tag = new CCIDefineSprite(reader, tagType, tagLength);
            logString = "CCIDefineSprite";
            break;
        default:
            tag = new CCIMovieTag(reader, tagType, tagLength);
            logString = "unknow tag ****************";
            std::cout << "unknow tag " << tagType << std::endl;
            
           // CCLog("unknow tag %d",tagType);
            //skip if do not understand
            
            break;
    }
    
    std::cout << logString << std::endl;
    
    if (tag/*&&tag->initWithReader(reader, tagType, tagLength)*/) {
        reader->flush();
        return tag;
    }
    
    reader->flush();
    return NULL;
}
int CCIMovieTag::getTagType(){
    return this->tagType;
}
CCIMovieTag::~CCIMovieTag(){
}
