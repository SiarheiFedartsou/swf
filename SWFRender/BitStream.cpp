//
//  BitStream.cpp
//  SWFRender
//
//  Created by Sergey Fedortsov on 27.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

#include "BitStream.h"

#include <stdlib.h>
#include <assert.h>

#include "Tag.h"

namespace swf {
    #define NBM( x ) (int32_t)( ( 1LL << x ) - 1 )
    int maskForNumBits[33] = {        NBM( 0x00 ), NBM( 0x01 ), NBM( 0x02 ), NBM( 0x03 ),
        NBM( 0x04 ), NBM( 0x05 ), NBM( 0x06 ), NBM( 0x07 ),
        NBM( 0x08 ), NBM( 0x09 ), NBM( 0x0A ), NBM( 0x0B ),
        NBM( 0x0C ), NBM( 0x0D ), NBM( 0x0E ), NBM( 0x0F ),
        NBM( 0x10 ), NBM( 0x11 ), NBM( 0x12 ), NBM( 0x13 ),
        NBM( 0x14 ), NBM( 0x15 ), NBM( 0x16 ), NBM( 0x17 ),
        NBM( 0x18 ), NBM( 0x19 ), NBM( 0x1A ), NBM( 0x1B ),
        NBM( 0x1C ), NBM( 0x1D ), NBM( 0x1E ), NBM( 0x1F ), -1 };
    
    #define NBS( x ) (int32_t)( (-1) << ( x - 1 ) )
    int signForNumBits[33] = {        NBS( 0x01 ), NBS( 0x01 ), NBS( 0x02 ), NBS( 0x03 ),
        NBS( 0x04 ), NBS( 0x05 ), NBS( 0x06 ), NBS( 0x07 ),
        NBS( 0x08 ), NBS( 0x09 ), NBS( 0x0A ), NBS( 0x0B ),
        NBS( 0x0C ), NBS( 0x0D ), NBS( 0x0E ), NBS( 0x0F ),
        NBS( 0x10 ), NBS( 0x11 ), NBS( 0x12 ), NBS( 0x13 ),
        NBS( 0x14 ), NBS( 0x15 ), NBS( 0x16 ), NBS( 0x17 ),
        NBS( 0x18 ), NBS( 0x19 ), NBS( 0x1A ), NBS( 0x1B ),
        NBS( 0x1C ), NBS( 0x1D ), NBS( 0x1E ), NBS( 0x1F ), NBS( 0x20 ) };
    
    static inline float fixed16(unsigned int fixed)
    {
        return fixed * (1.0f / 65536.0f);
    }
    
    static inline float fixed8(unsigned int fixed)
    {
        return fixed * (1.0f / 256.0f);
    }
    
    BitStream::BitStream(const std::string& filePath)
    :   currentBit_(0),
        currentBytePtr_(0),
        currentByte_(0),
        shouldReleaseBytes_(true)
    {
        FILE* f = fopen(filePath.c_str(), "rb");
        
        fseek(f, 0, SEEK_END);
        bufferSize_ = ftell(f);
        fseek(f, 0, SEEK_SET);
        
        bytes_ = new uint8_t[bufferSize_];
        fread(bytes_, bufferSize_, 1, f);
        
        fclose(f);
        
        currentBytePtr_ = bytes_;
    }
    
    
    BitStream::BitStream(const BitStream& bitStream, size_t size, bool copy)
    : shouldReleaseBytes_(copy)
    {
        assert((bitStream.bufferSize_ - (currentBytePtr_ - bytes_)) > 0);
        
        if (copy) {
            bufferSize_ = size;
            
            bytes_ = new uint8_t[bufferSize_];
            
            std::copy(bitStream.currentBytePtr_, bitStream.currentBytePtr_ + bufferSize_, bytes_);
            
            currentBytePtr_ = bytes_;
        } else {
            bufferSize_ = size;
            
            bytes_ = bitStream.currentBytePtr_;
            currentBytePtr_ = bytes_;
        }
    }
    
    
    void BitStream::Skip(size_t howMuch)
    {
     //   Align();
        Reset();
        currentBytePtr_ += howMuch;
        //currentByte_ += howMuch;
    }
    
    uint32_t BitStream::ReadBits(uint64_t& regCurrentBit, uint64_t& regCurrentByte, unsigned int numBits)
    {
        assert(numBits <= 32);
        
        uint64_t numExtraBytes = ( numBits - regCurrentBit + 7 ) >> 3;
        regCurrentBit = regCurrentBit + ( numExtraBytes << 3 ) - numBits;
        for ( int i = 0; i < numExtraBytes; i++ ) {
            regCurrentByte = ( regCurrentByte << 8 ) | currentBytePtr_[i];
        }
        currentBytePtr_ += numExtraBytes;

        return (unsigned int) ( ( regCurrentByte >> regCurrentBit ) & maskForNumBits[numBits] );
        
    }
    
    int32_t BitStream::ReadSignedBits(uint64_t& regCurrentBit, uint64_t& regCurrentByte, unsigned int numBits)
    {
        int32_t i = (int32_t)ReadBits(regCurrentBit, regCurrentByte, numBits);

        int s = signForNumBits[numBits];
        return ( ( i + s ) ^ s );
        
    }
    
    void BitStream::Reset()
    {
        currentBit_ = 0;
        currentByte_ = 0;
    }
    
    uint8_t BitStream::ReadUI8()
    {
        Reset();
        return *currentBytePtr_++;
    }
    
    uint16_t BitStream::ReadUI16()
    {
        Reset();
        currentBytePtr_ += 2;
        return currentBytePtr_[-2] | (currentBytePtr_[-1] << 8);
    }
    
    uint32_t BitStream::ReadUI32()
    {
        Reset();
        currentBytePtr_ += 4;
        return currentBytePtr_[-4] | (currentBytePtr_[-3] << 8) | (currentBytePtr_[-2] << 16) | (currentBytePtr_[-1] << 24);
    }
    
    
    float BitStream::ReadFixed8()
    {
        return fixed8(ReadUI16());
    }
    
    float BitStream::ReadFixed16()
    {
        return fixed16(ReadUI32());
    }
    
    
    void BitStream::ReadRect(Rect& rect)
    {
        uint64_t regCurrentBit = 0;
        uint64_t regCurrentByte = 0;
        
        uint32_t bits = ReadBits(currentBit_, currentByte_, 5);
        rect.XMin = ReadSignedBits(currentBit_, currentByte_, bits);
        rect.XMax = ReadSignedBits(currentBit_, currentByte_, bits);
        rect.YMin = ReadSignedBits(currentBit_, currentByte_, bits);
        rect.YMax = ReadSignedBits(currentBit_, currentByte_, bits);
        
        
        currentBit_ = regCurrentBit;
        currentByte_ = regCurrentByte;
        
    }
    
    BitStream::~BitStream()
    {
        if (shouldReleaseBytes_)
            delete[] bytes_;
    }
    
    
}
