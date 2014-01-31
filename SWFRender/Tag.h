//
//  Tag.h
//  SWFRender
//
//  Created by Sergey Fedortsov on 27.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#ifndef __SWFRender__Tag__
#define __SWFRender__Tag__

#include <iostream>

#include "BitStream.h"

namespace swf {
    class Tag {
    public:
        Tag(BitStream& bitStream)
        {
            
            uint16_t tagCodeAndLength = bitStream.ReadUI16();
           
            
            tagCode_ = tagCodeAndLength >> 6;
            
            length_ = tagCodeAndLength & 0x3f;
            if (length_ == 0x3f) {
                length_ = bitStream.ReadUI32();
            }
            
        }
        
        uint16_t tagCode()
        {
            return tagCode_;
        }
        
        uint32_t length()
        {
            return length_;
        }
        
    private:
        uint16_t tagCode_;
        uint32_t length_;
        
    };
}

#endif /* defined(__SWFRender__Tag__) */
