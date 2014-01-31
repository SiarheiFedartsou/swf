//
//  BitStream.h
//  SWFRender
//
//  Created by Sergey Fedortsov on 27.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#ifndef __SWFRender__BitStream__
#define __SWFRender__BitStream__

#include <iostream>
#include <fstream>

#include "Types.h"

namespace swf {
    

    
    class BitStream {
    public:
        BitStream(const std::string& filePath);
        BitStream(const BitStream& bitStream, size_t size, bool copy = false);
        virtual ~BitStream();
        
        void ReadRect(Rect& rect);
        
        void Skip(size_t howMuch);
        
        uint8_t ReadUI8();
        uint16_t ReadUI16();
        uint32_t ReadUI32();
        
        float ReadFixed8();
        float ReadFixed16();
        
        
    protected:
        uint32_t ReadBits(uint64_t& regCurrentBit, uint64_t& regCurrentByte, unsigned int numBits);
        int32_t ReadSignedBits(uint64_t& regCurrentBit, uint64_t& regCurrentByte, unsigned int numBits);
        
        void Reset();
        
        uint8_t* bytes_;
        uint8_t* currentBytePtr_;
        size_t bufferSize_;
        
        uint64_t currentBit_;
        uint64_t currentByte_;
        
        
        bool shouldReleaseBytes_;
        
    };
}

#endif /* defined(__SWFRender__BitStream__) */
