//
//  CCIDefineShape2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIDefineShape2__
#define __CocosInterpreterTest__CCIDefineShape2__


#include "CCIDefineShape.h"

class CCIDefineShape2 : public CCIDefineShape{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
public:
    
};


#endif /* defined(__CocosInterpreterTest__CCIDefineShape2__) */
