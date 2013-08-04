//
//  CCIActionRecord.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIActionRecord__
#define __CocosInterpreterTest__CCIActionRecord__

#include "CCIBufferReader.h"

class CCIActionRecord{
public:
    CCIActionRecord(CCIBufferReader * reader);
    
public:
    UI8                 ActionCode;
    UI16                Length;
};


#endif /* defined(__CocosInterpreterTest__CCIActionRecord__) */
