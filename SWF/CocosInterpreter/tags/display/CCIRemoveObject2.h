//
//  CCIRemoveObject2.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#ifndef __CocosInterpreterTest__CCIRemoveObject2__
#define __CocosInterpreterTest__CCIRemoveObject2__

#include "CCIRemoveObject.h"


class CCIRemoveObject2 : public CCIRemoveObject{
public:
    virtual bool initWithReader(CCIBufferReader *reader,int tagType,int tagLength);

};



#endif /* defined(__CocosInterpreterTest__CCIRemoveObject2__) */
