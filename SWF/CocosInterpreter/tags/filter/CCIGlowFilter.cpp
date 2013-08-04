//
//  CCIGlowFilter.cpp
//  SwfTest
//
//  Created by Wu Tong on 13-4-27.
//
//

#include "CCIGlowFilter.h"



bool CCIGlowFilter::initWithFilterId(UI8 filterId, CCIBufferReader *reader){
    CCIFilter::initWithFilterId(filterId, reader);

    this->GlowColor = new CCIRGBA(reader);

    
    
    this->BlurX = reader->readFIXED();
    this->BlurY = reader->readFIXED();
    
    this->Strength = reader->readFIXED8();
    
    reader->clearBits();
    
    this->InnerGlow = reader->readUBits(1);
    this->Knockout = reader->readUBits(1);
    this->CompositeSource = reader->readUBits(1);
    this->Passes = reader->readUBits(5);
    
    reader->clearBits();
    
    return true;
}
CCIGlowFilter::~CCIGlowFilter(){
    delete this->GlowColor;
}
