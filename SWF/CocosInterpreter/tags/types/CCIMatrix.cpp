//
//  CCIMatrix.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIMatrix.h"
#include <math.h>
//#include "ccMacros.h"

CCIMatrix::CCIMatrix(CCIBufferReader *reader){
    reader->clearBits();
    this->HasScale = reader->readUBits(1);
    if (this->HasScale) {
        this->NScaleBits = reader->readUBits(5);
        this->ScaleX = reader->readFBits(this->NScaleBits);
        this->ScaleY = reader->readFBits(this->NScaleBits);
    }
    
    a = this->ScaleX/65536.0;
    d = this->ScaleY/65536.0;
    
    this->HasRotate = reader->readUBits(1);
    if (this->HasRotate) {
        this->NRotateBits = reader->readUBits(5);
        this->RotateSkew0 = reader->readFBits(this->NRotateBits);
        this->RotateSkew1 = reader->readFBits(this->NRotateBits);
    }
    
    b = this->RotateSkew1/65536.0;
    c = this->RotateSkew0/65536.0;
    
    this->NTranslateBits = reader->readUBits(5);
    this->TranslateX = reader->readSBits(this->NTranslateBits);
    this->TranslateY = reader->readSBits(this->NTranslateBits);
    
    tx = this->TranslateX;
    ty = this->TranslateY;
    
    reader->clearBits();
}
float CCIMatrix::getScaleX(){
    //return sqrt(a*a+b*b);
    return sqrt(a*a+b*b)*(sin(a)<0?-1:1);
}
float CCIMatrix::getScaleY(){
    //return sqrt(c*c+d*d);
    return sqrt(c*c+d*d)*(sin(d)<0?-1:1);
}
float CCIMatrix::getSkewX(){
    return 0.f;
//    float skewX = CC_RADIANS_TO_DEGREES(atan2(b, d));
//    return -skewX;
}
float CCIMatrix::getSkewY(){
    return 0.f;
//    float skewY = CC_RADIANS_TO_DEGREES(atan2(c, a));
//    //FIXME
//    return skewY;
}
int CCIMatrix::getTranslateX(){
    return this->TranslateX/20;
}
int CCIMatrix::getTranslateY(){
    return this->TranslateY/20;
}

float CCIMatrix::getRotation(){
    return this->getSkewX();
}

CCIPoint CCIMatrix::deltaTransformPoint(CCIPoint p){
    int dx = p.x * this->a + p.y*this->c + 0;
    int dy = p.x * this->b + p.y*this->d + 0;
	return CCIPoint(dx, dy);
}
//CCAffineTransform CCIMatrix::getTransform(){
//    return CCAffineTransformMake(a,b,c,d,tx,ty);
//}
