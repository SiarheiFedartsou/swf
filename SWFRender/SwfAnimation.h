//
//  SwfAnimation.h
//  SWFRender
//
//  Created by Sergey Fedortsov on 29.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#ifndef __SWFRender__SwfAnimation__
#define __SWFRender__SwfAnimation__

#include <iostream>

#include "BitStream.h"

#include "Types.h"

#include "Sprite.h"

#include <stack>

namespace swf {
    class SwfAnimation : public Sprite
    {
    public:
        SwfAnimation(const std::string& filePath);
        
        uint8_t swfVersion() { return swfVersion_; }
        
        const Rect& frameSize() { return frameSize_; }
        float frameRate() { return frameRate_; }
        uint16_t frameCount() { return frameCount_; }
        
    private:
        void readHeader();
        
        BitStream bitStream_;
        
    private:
        
        std::stack<Sprite*> spriteStack_;
        
    private:
        uint8_t swfVersion_;
        Rect frameSize_;
        
        float frameRate_;
        
        uint16_t frameCount_;
    };
}

#endif /* defined(__SWFRender__SwfAnimation__) */
