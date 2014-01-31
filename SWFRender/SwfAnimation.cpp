//
//  SwfAnimation.cpp
//  SWFRender
//
//  Created by Sergey Fedortsov on 29.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#include "SwfAnimation.h"
#include "Tag.h"
namespace swf {
    
    SwfAnimation::SwfAnimation(const std::string& filePath)
    :
    bitStream_(filePath),
    Sprite(bitStream_, this)
    {
        readHeader();
     
        Sprite::load();
       // spriteStack_.push(this);
        
        
    }
    
    
    
    void SwfAnimation::readHeader()
    {
        bitStream_.Skip(3);
        swfVersion_ = bitStream_.ReadUI8();
        bitStream_.Skip(4);
        bitStream_.ReadRect(frameSize_);
        frameRate_ = bitStream_.ReadFixed8();
        frameCount_ = bitStream_.ReadUI16();
    }
    
}
