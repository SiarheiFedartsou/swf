//
//  CCIDefineShape4.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineShape4__
#define __CocosInterpreterTest__CCIDefineShape4__


#include "CCIDefineShape3.h"

#include "CCIDrawable.h"

#include "CCICharacter.h"

class CCIDefineShape4 : public CCICharacter{
public:
    CCIDefineShape4(CCIBufferReader *reader,int tagType,int tagLength);
protected:
    CCIRect*    edgeBounds;
protected:
    UI16        shapeId;
    CCIRect*    shapeBounds;
    
    CCIShapeWithStyle * Shapes;
};


#endif /* defined(__CocosInterpreterTest__CCIDefineShape4__) */
