//
//  CCIGeometry.cpp
//  SWF
//
//  Created by Siarhei Fedartsou on 02.08.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#include "CCIGeometry.h"


CCIRect::CCIRect(CCIBufferReader * reader){
    reader->clearBits();
    UI32 nbits = reader->readUBits(5);
    this->Nbits = nbits;
    this->Xmin = reader->readSBits(nbits) / 20.0;
    this->Xmax = reader->readSBits(nbits) / 20.0;
    this->Ymin = reader->readSBits(nbits) / 20.0;
    this->Ymax = reader->readSBits(nbits) / 20.0;
    
    this->width = this->Xmax - this->Xmin;
    this->height = this->Ymax - this->Ymin;
    
    reader->clearBits();
}

int CCIRect::getHeight(){
    return height;
}

int CCIRect::getWidth(){
    return width;
}

CCISize CCIRect::getSize(){
    return CCISize(width, height);
}

CCIPoint CCIRect::getAnchorPoint(){
    return CCIPoint(-this->Xmin/(float)width, this->Ymax/(float)height);
}

CCIPoint CCIRect::convertToCCSpace(int x,int y){
    int ccx = x - this->Xmin;
    int ccy = y - this->Ymax;
    return CCIPoint(ccx, -ccy);
}
