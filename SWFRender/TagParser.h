//
//  TagParser.h
//  SWFRender
//
//  Created by Sergey Fedortsov on 31.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#ifndef __SWFRender__TagParser__
#define __SWFRender__TagParser__

#include "BitStream.h"



namespace swf {
    
    struct TagHeader {
        uint16_t code;
        uint32_t length;
    };
    
    class TagParser
    {
    public:
        void parse(BitStream& bitStream);
        virtual void handleTag(const TagHeader& tag, BitStream& bitStream) = 0;
    };
}


#endif /* defined(__SWFRender__TagParser__) */
