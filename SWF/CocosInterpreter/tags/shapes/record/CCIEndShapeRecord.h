//
//  CCIEndShapeRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCIEndShapeRecord__
#define __CocosInterpreterTest__CCIEndShapeRecord__

#include "CCIShapeRecord.h"

class  CCIEndShapeRecord:public CCIShapeRecord{
public:
    CCIEndShapeRecord(CCIBufferReader* reader,UI8 numFillBits,UI8 numLineBits);
public:
    UI8 EndOfShape;
};



#endif /* defined(__CocosInterpreterTest__CCIEndShapeRecord__) */
