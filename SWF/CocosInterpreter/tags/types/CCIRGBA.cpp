//
//  CCIRGBA.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIRGBA.h"


CCIRGBA::CCIRGBA(CCIBufferReader *reader):CCIRGB(reader){
    this->Alpha = reader->readUI8();
}

