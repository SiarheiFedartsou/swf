//
//  Sprite.h
//  SWFRender
//
//  Created by Sergey Fedortsov on 30.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#ifndef __SWFRender__Sprite__
#define __SWFRender__Sprite__

#include "BitStream.h"

#include "Character.h"

#include "TagParser.h"

#include "Tag.h"

namespace swf {
    class Sprite : public Character, public TagParser
    {
    public:
        Sprite(BitStream& bitStream, Sprite* mainSprite)
        : bitStream_(bitStream)
        , mainSprite_(mainSprite)
        {
            
        };
        
        void load()
        {
            this->parse(bitStream_);
        }
        
        
        
        virtual void handleTag(const TagHeader& tag, BitStream& bitStream);
        
    private:
        BitStream& bitStream_;
        
        Sprite* mainSprite_;
    };
}

#endif /* defined(__SWFRender__Sprite__) */
