//
//  CCIMovie.cpp
//  CocosInterpreterTest
//
//  Created by Wu Tong on 13-4-8.
//
//

#include "CCIMovie.h"
#//include "CCFileUtils.h"
#include "CCIBufferReader.h"
#include "CCIFrameLabel.h"

#include <stdlib.h>
#include <stdio.h>



//static CCDictionary * movies = NULL;
CCIMovie::CCIMovie(std::string filename)
{
    
  //  if (!movies) {
       // movies = new CCDictionary();
  //  }
//    CCIMovie * movie = /*(CCIMovie *)movies->objectForKey(filename)*/NULL;
    //if (movie) {
    //    return movie;
    //}
    
    const char* fullPath = filename.c_str();
    //const char * fullPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(filename.c_str());
    int fileSize = 0;
    
    unsigned char * swfdata = NULL;
    
    FILE* f = fopen(fullPath, "rb");
    if (f) {
        fseek(f, 0, SEEK_END);
        fileSize = ftell(f);
        fseek(f, 0, SEEK_SET);
        
        swfdata = new unsigned char[fileSize];
        
        fread(swfdata, 1, fileSize, f);
    }
    
    
  //  unsigned char * swfdata = CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", (unsigned long *)(&fileSize));
    
    if (fileSize < 0)
    {
        delete[] swfdata;
    }
    
    
    CCIBufferReader bufferReader;
    bufferReader.setData(swfdata, fileSize);
    delete[] swfdata;

   // movie->frameLabels = CCDictionary::create();
   // movie->frameLabels->retain();
    header = CCIMovieHeader::create(&bufferReader);
    
    bufferReader.version = header->getVersion();
    
    if (header->getVersion()>=8) {
        fileAttributes = (CCIFileAttributes *)CCIMovieTag::next(&bufferReader);
    }
    CCIMovieTag * tag = CCIMovieTag::next(&bufferReader);
    int tagIndex = 0;
    while (tag) {
        tags.push_back(tag);
        tag = CCIMovieTag::next(&bufferReader);
        tagIndex++;
        
        if (tag&&tag->getTagType()==TagTypeFrameLabel) {
            CCIFrameLabel * frameLbl = (CCIFrameLabel *)tag;
          //  movie->frameLabels->setObject(CCString::createWithFormat("%d",tagIndex), frameLbl->getName());
        }
        
    }
    bufferReader.clear();
    
  //  movies->setObject(movie,filename);
   // movie->release();
   // return movie;
}

std::vector<CCIMovieTag *> CCIMovie::getTags(){
    return this->tags;
}

CCIMovieHeader * CCIMovie::getHeader(){
    return this->header;
}

bool CCIMovie::nextFrame()
{
    for (auto itr = this->tags.begin(); itr != this->tags.end(); ++itr) {
        CCIMovieTag* tag = *itr;
        
        if (tag->getTagType() == TagTypeShowFrame)
            break;
        
        
        if (tag->getTagType() == TagTypePlaceObject
            ||
            tag->getTagType() == TagTypePlaceObject2
            ||
            tag->getTagType() == TagTypePlaceObject3) {
            displayList_.placeObject(NULL, (CCIPlaceObject*)tag);
        }
    }
}

void CCIMovie::draw()
{
    
}

//CCDictionary * CCIMovie::getFrameLabels(){
//    return this->frameLabels;
//}
void CCIMovie::cleanup(){
//    movies->release();
//    movies = NULL;
}
CCIMovie::~CCIMovie(){
    for (int i=0; i<tags.size(); i++) {
        CCIMovieTag * tag = tags[i];
        delete tag;
    }
    tags.clear();
    delete header;
    delete fileAttributes;
//    this->frameLabels->release();
}

