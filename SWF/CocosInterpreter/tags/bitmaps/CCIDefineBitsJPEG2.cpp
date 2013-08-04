//
//  CCIDefineBitsJPEG2.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineBitsJPEG2.h"

bool CCIDefineBitsJPEG2::initWithReader(CCIBufferReader *reader, int tagType, int tagLength){
    
    CCIDefineBits::initWithReader(reader, tagType, tagLength);

    return true;
}
void CCIDefineBitsJPEG2::loadImageData(UI8 * imageData){
    CCIDefineBits::loadImageData(imageData);
}
