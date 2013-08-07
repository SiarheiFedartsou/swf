//
//  CCIPlaceObject2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIPlaceObject2__
#define __CocosInterpreterTest__CCIPlaceObject2__



#include "CCIPlaceObject.h"
#include "CCIClipActions.h"


enum PlaceObjectType {
    PlaceObjectTypeModify = 0,
    PlaceObjectTypeNew = 1,
    PlaceObjectTypeReplace = 2,
};
class CCIPlaceObject2 : public CCIMovieTag{
public:
    CCIPlaceObject2(CCIBufferReader *reader,int tagType,int tagLength);
    PlaceObjectType placeType;
    virtual ~CCIPlaceObject2();
protected:
    bool placeFlagHasClipActions;
    bool placeFlagHasClipDepth;
    bool placeFlagHasName;
    bool placeFlagHasRatio;
    bool placeFlagHasColorTransform;
    bool placeFlagHasMatrix;
    bool placeFlagHasCharacter;
    bool placeFlagMove;
    
    UI16    ratio;
    std::string name;
    UI16    clipDepth;
    
    CCIClipActions * clipActions;
protected:
    UI16            characterId;
    UI16            depth;
    CCIMatrix  *    matrix;
    CCICxform  *    colorTransform;
};



#endif /* defined(__CocosInterpreterTest__CCIPlaceObject2__) */
