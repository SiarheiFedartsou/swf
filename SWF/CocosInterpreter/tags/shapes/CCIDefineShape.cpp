//
//  CCIDefineShape.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineShape.h"

CCIDefineShape::CCIDefineShape(CCIBufferReader *reader,int tagType,int tagLength)
: CCIMovieTag(reader, tagType, tagLength)
{
    this->shapeId = reader->readUI16();
    this->shapeBounds = new CCIRect(reader);
    
    this->Shapes = new CCIShapeWithStyle(reader);
}

CCIShapeWithStyle * CCIDefineShape::getShapes(){
    return this->Shapes;
}
int CCIDefineShape::getShapeId(){
    return this->shapeId;
}
CCIRect * CCIDefineShape::getBounds(){
    return this->shapeBounds;
}
CCIDefineShape::~CCIDefineShape(){
    delete this->shapeBounds;
    delete this->Shapes;
}
