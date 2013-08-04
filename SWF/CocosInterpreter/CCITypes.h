//
//  CCITypes.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef CocosInterpreter_CCITypes_h
#define CocosInterpreter_CCITypes_h
#include <stdint.h>
#include <vector>


typedef uint8_t UI8;
typedef uint16_t UI16;
typedef uint32_t UI32;

typedef float FIXED;
typedef float FIXED8;

typedef float FLOAT16;
typedef float FLOAT;
typedef double DOUBLE;

typedef std::vector<UI8> ByteVector;

typedef struct {
    UI8 r;
    UI8 g;
    UI8 b;
    UI8 a;
} RGBA;

#endif
