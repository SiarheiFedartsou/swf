//
//  CCIMovie.h
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#ifndef __CocosInterpreterParser__CCIMovie__
#define __CocosInterpreterParser__CCIMovie__


#include "CCIMovieTag.h"
#include <iostream>
#include <vector>

#include "CCIMovieHeader.h"
#include "CCIFileAttributes.h"
//#include "CCDictionary.h"




class CCIMovie/* : public CCObject*/{
public:
    static CCIMovie *decodeFromFile(std::string filename);
    std::vector<CCIMovieTag *> getTags();
    CCIMovieHeader * getHeader();
 //   CCDictionary * getFrameLabels();
    static void cleanup();
    
    virtual ~CCIMovie();
public:
    CCIMovieHeader * header;
    CCIFileAttributes * fileAttributes;
    std::vector<CCIMovieTag *> tags;
    
 //   CCDictionary * frameLabels;
    
};




#endif /* defined(__CocosInterpreterTest__CCIMovie__) */
