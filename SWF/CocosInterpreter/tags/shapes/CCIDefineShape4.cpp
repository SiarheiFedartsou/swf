//
//  CCIDefineShape4.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-9.
//
//

#include "CCIDefineShape4.h"


CCIDefineShape4::CCIDefineShape4(CCIBufferReader *reader,int tagType,int tagLength)
: CCICharacter(reader, tagType, tagLength)
{
    this->shapeBounds = new CCIRect(reader);
    this->edgeBounds = new CCIRect(reader);
    
    reader->readUI8();
    
    this->Shapes = new CCIShapeWithStyle(reader);
    
}

/*
void CCIDefineShape4::draw()
{
    VGPath _path2 = vgCreatePath(VG_PATH_FORMAT_STANDARD, VG_PATH_DATATYPE_F,1,0,0,0, VG_PATH_CAPABILITY_ALL);
    vgClearPath(_path2, VG_PATH_CAPABILITY_ALL);
   // vguEllipse( _path2, 250.0f, 50.0f, 100.0f, 100.0f );
    //vguLine( _path, 0.0f, 0.0f, 90.0f, 90.0f );
    vguRoundRect( _path2, 50.0f, 50.0f, 100.0f, 100.0f, 60, 60 );
    
    VGfloat x[9];
    
    vgGetMatrix(x);
   
    VGint backingWidth = vgGeti( VG_SURFACE_WIDTH_MNK );
    VGint backingHeight = vgGeti( VG_SURFACE_HEIGHT_MNK );;
    
	
	vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
	vgLoadIdentity();
	vgTranslate( 0, backingHeight/2 );
    vgDrawPath( _path2, VG_FILL_PATH );
    

    vgLoadMatrix(x);
}*/