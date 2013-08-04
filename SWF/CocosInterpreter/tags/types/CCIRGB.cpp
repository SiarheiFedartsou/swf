//
//  CCIRGB.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIRGB.h"


CCIRGB::CCIRGB(CCIBufferReader *reader){
    this->Red = reader->readUI8();
    this->Green = reader->readUI8();
    this->Blue = reader->readUI8();
    this->Alpha = 0xff;
}

RGBA CCIRGB::getColor(){
    return RGBA();
  //  return ccc4(this->Red, this->Green, this->Blue, this->Alpha);
}

