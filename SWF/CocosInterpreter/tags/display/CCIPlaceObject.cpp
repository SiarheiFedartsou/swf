//
//  CCIPlaceObject.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIPlaceObject.h"

CCIPlaceObject::CCIPlaceObject(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength)
{
    this->characterId =  reader->readUI16();
    this->depth = reader->readUI16();
    
    this->matrix = new CCIMatrix(reader);
    
    if (!reader->isTagFinished()) {
        this->colorTransform = new CCICxform(reader);
    }else{
        this->colorTransform = NULL;
    }
}

UI16 CCIPlaceObject::getCharacterId(){
    return this->characterId;
}
UI16 CCIPlaceObject::getDepth(){
    return this->depth;
}
CCIMatrix * CCIPlaceObject::getMatrix(){
    return this->matrix;
}
CCICxform * CCIPlaceObject::getColorTransform(){
    return this->colorTransform;
}
CCIPlaceObject::~CCIPlaceObject(){
    delete this->matrix;
    if (this->colorTransform) {
        delete this->colorTransform;
    }
}
