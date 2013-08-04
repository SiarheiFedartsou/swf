//
//  CCIDefineShape.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineShape__
#define __CocosInterpreterTest__CCIDefineShape__

#include "CCIMovieTag.h"
#include "CCIGeometry.h"
#include "CCIShapeWithStyle.h"

class CCIDefineShape : public CCIMovieTag{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    CCIShapeWithStyle * getShapes();
    int    getShapeId();
    CCIRect * getBounds();
    
    virtual ~CCIDefineShape();
protected:
    UI16        shapeId;
    CCIRect*    shapeBounds;
    
    CCIShapeWithStyle * Shapes;
    
    
};


#endif /* defined(__CocosInterpreterTest__CCIDefineShape__) */
