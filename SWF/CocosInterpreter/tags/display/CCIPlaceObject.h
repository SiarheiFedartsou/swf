//
//  CCIPlaceObject.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIPlaceObject__
#define __CocosInterpreterTest__CCIPlaceObject__


#include "CCIMovieTag.h"
#include "CCIMatrix.h"
#include "CCICxform.h"



class CCIPlaceObject : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    UI16 getCharacterId();
    CCIMatrix * getMatrix();
    CCICxform * getColorTransform();
    UI16    getDepth();
    virtual ~CCIPlaceObject();
protected:
    UI16            characterId;
    UI16            depth;
    CCIMatrix  *    matrix;
    CCICxform  *    colorTransform;
};



#endif /* defined(__CocosInterpreterTest__CCIPlaceObject__) */
