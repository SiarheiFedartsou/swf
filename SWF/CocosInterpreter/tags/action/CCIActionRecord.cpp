//
//  CCIActionRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIActionRecord.h"


CCIActionRecord::CCIActionRecord(CCIBufferReader *reader){
    this->ActionCode = reader->readUI8();
    if (this->ActionCode > 0x80) {
        this->Length = reader->readUI16();
    }
}
