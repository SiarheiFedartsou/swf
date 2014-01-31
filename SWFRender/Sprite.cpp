//
//  Sprite.cpp
//  SWFRender
//
//  Created by Sergey Fedortsov on 30.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#include "Sprite.h"


namespace swf {
    void Sprite::handleTag(const TagHeader& tag, BitStream& bitStream)
    {
        std::cout << tag.code << std::endl;
    }
}