//
//  CCIShapeWithStyle.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIShapeWithStyle__
#define __CocosInterpreterTest__CCIShapeWithStyle__


#include "CCIBufferReader.h"
#include "CCIFillStyleArray.h"
#include "CCILineStyleArray.h"
#include "CCIShapeRecord.h"

class CCIShapeWithStyle {
public:
    CCIShapeWithStyle(CCIBufferReader * reader);
    virtual ~CCIShapeWithStyle();
public:
    CCIFillStyleArray * FillStyles;
    CCILineStyleArray * LineStyles;
    
    UI8 NumFillBits;
    UI8 NumLineBits;
    
    //shapeRecords
    std::vector<CCIShapeRecord *> ShapeRecords;
};




#endif /* defined(__CocosInterpreterTest__CCIShapeWithStyle__) */
