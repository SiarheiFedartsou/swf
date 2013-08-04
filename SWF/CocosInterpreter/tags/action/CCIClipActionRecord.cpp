//
//  CCIClipActionRecord.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIClipActionRecord.h"



CCIClipActionRecord::CCIClipActionRecord(CCIBufferReader *reader){
    this->EventFlags = new CCIClipEventFlags(reader);
    this->ActionRecordSize = reader->readUI32();
    
    if (this->EventFlags->ClipEventPress) {
        this->KeyCode = reader->readUI8();
    }
}

CCIClipActionRecord::~CCIClipActionRecord(){
    delete this->EventFlags;
}
