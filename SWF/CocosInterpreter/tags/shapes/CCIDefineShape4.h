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

class CCIDefineShape4 :public CCIDefineShape3, public CCIDrawable{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);
    
protected:
    CCIRect*    edgeBounds;
public:
    virtual void draw() override;
};


#endif /* defined(__CocosInterpreterTest__CCIDefineShape4__) */
