//
//  TagParser.cpp
//  SWFRender
//
//  Created by Sergey Fedortsov on 31.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#include "TagParser.h"
#include "Tag.h"


namespace swf {
    void TagParser::parse(BitStream& bitStream)
    {
        
        while (true) {
            
            TagHeader tagHeader;
            
            uint16_t tagCodeAndLength = bitStream.ReadUI16();
            
            
            tagHeader.code = tagCodeAndLength >> 6;
            
            tagHeader.length = tagCodeAndLength & 0x3f;
            if (tagHeader.length == 0x3f) {
                tagHeader.length = bitStream.ReadUI32();
            }

            BitStream tagBitStream(bitStream, tagHeader.length);
            handleTag(tagHeader, tagBitStream);
            
            
            bitStream.Skip(tagHeader.length);
            
            
            
            if (tagHeader.code == Tag_End)
                break;
        }
    }

}

