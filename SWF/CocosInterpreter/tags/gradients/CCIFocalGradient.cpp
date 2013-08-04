//
//  CCIFocalGradient.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-10.
//
//

#include "CCIFocalGradient.h"


CCIFocalGradient::CCIFocalGradient(CCIBufferReader * reader):CCIGradient(reader){
    this->FocalPoint = reader->readFIXED8();
}
