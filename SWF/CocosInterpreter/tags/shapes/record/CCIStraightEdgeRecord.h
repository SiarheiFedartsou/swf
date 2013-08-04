//
//  CCIStraightEdgeRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-11.
//
//

#ifndef __CocosInterpreterTest__CCIStraightEdgeRecord__
#define __CocosInterpreterTest__CCIStraightEdgeRecord__

#include "CCIShapeRecord.h"

class  CCIStraightEdgeRecord:public CCIShapeRecord{
public:
    CCIStraightEdgeRecord(CCIBufferReader* reader,UI8 numFillBits,UI8 numLineBits);
public:
    UI8 StraightFlag;
    UI8 NumBits;
    UI8 GeneralLineFlag;
    int DeltaX;
    int DeltaY;
    int VertLineFlag;
};



#endif /* defined(__CocosInterpreterTest__CCIStraightEdgeRecord__) */
