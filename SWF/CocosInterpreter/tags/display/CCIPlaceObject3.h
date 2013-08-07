//
//  CCIPlaceObject3.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIPlaceObject3__
#define __CocosInterpreterTest__CCIPlaceObject3__
#include "CCIPlaceObject2.h"

#include "CCIFilterList.h"
#include "CCIRGBA.h"


class CCIPlaceObject3 : public CCIPlaceObject2{
public:
    
    CCIPlaceObject3(CCIBufferReader *reader,int tagType,int tagLength);
    virtual ~CCIPlaceObject3();
    
    
    CCIFilterList * getFilterList();
private:
    UI8 reserved;
    UI8 placeFlagOpaqueBackground;
    UI8 placeFlagHasVisible;
    UI8 placeFlagHasImage;
    UI8 placeFlagHasClassName;
    UI8 placeFlagHasCacheAsBitmap;
    UI8 placeFlagHasBlendMode;
    UI8 placeFlagHasFilterList;
    
    std::string className;
    
    UI8 blendMode;
    UI8 bitmapCache;
    UI8 visible;
    CCIRGBA * backgroundColor;
    
    
    CCIFilterList * surfaceFilterList;
    
    
};



#endif /* defined(__CocosInterpreterTest__CCIPlaceObject3__) */
