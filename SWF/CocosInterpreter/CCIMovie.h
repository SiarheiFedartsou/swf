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

#include "CCIDrawable.h"
//#include "CCDictionary.h"
#include "CCIDisplayList.h"

#include <map>



class CCIMovie : public CCIDrawable/* : public CCObject*/{
public:
    CCIMovie(std::string filename);
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
public:
    virtual void draw();
    bool nextFrame();
    
private:
    CCIDisplayList displayList_;
    
    
    std::map<unsigned int, CCIDrawable*> dictionary_;
};




#endif /* defined(__CocosInterpreterTest__CCIMovie__) */
