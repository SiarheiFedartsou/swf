//
//  CCIDisplayList.h
//  SWF
//
//  Created by Siarhei Fedartsou on 05.08.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#ifndef __SWF__CCIDisplayList__
#define __SWF__CCIDisplayList__

#include <assert.h>

#include <map>

#include "CCIPlaceObject.h"
#include "CCIRemoveObject.h"
#include "CCICharacter.h"

#import <MonkVG/openvg.h>
#import <MonkVG/vgext.h>

class CCIDisplayListEntry 
{
public:
    CCIDisplayListEntry(CCIPlaceObject* placeObject) :
        depth_(placeObject->getDepth()),
        characterId_(placeObject->getCharacterId()),
        matrix_(placeObject->getMatrix())
    {};
    
    UI16 getDepth() { return depth_; }
    UI16 getCharacterId() { return characterId_; }
    CCIMatrix* getMatrix() { return matrix_; }
private:
    UI16 depth_;
    UI16 characterId_;
    CCIMatrix* matrix_;
};



class CCIDisplayList
{
public:
    void placeObject(CCIPlaceObject* placeObject)
    {
        assert(placeObject != NULL);
        
        UI16 depth = placeObject->getDepth();
        
        CCIDisplayListEntry* entry = entryForPlaceObject(placeObject);
        entries_.insert(std::make_pair(depth, entry));
        
    }
    
    void removeObject(CCIRemoveObject* removeObject)
    {
        entries_.erase(removeObject->getDepth());
    }

    void addCharacter(CCICharacter* character)
    {
        characters_.insert(std::make_pair(character->getCharacterId(), character));
    }
    
    
    void draw()
    {
        std::vector<CCIDisplayListEntry*> toDisplay;
        for (CCIDisplayListEntries::iterator itr = entries_.begin(); itr != entries_.end(); ++itr) {
            toDisplay.push_back(itr->second);
        }
        std::sort(toDisplay.begin(), toDisplay.end(), displayListEntryComparator);
    
        for (std::vector<CCIDisplayListEntry*>::iterator entryItr = toDisplay.begin(); entryItr != toDisplay.end(); ++entryItr) {
            CCIDisplayListEntry* entry = *entryItr;
            
            assert(characters_.find(entry->getCharacterId()) != characters_.end());
            
            CCIMatrix* matrix = entry->getMatrix();
            
            assert(matrix);
            
            
            vgLoadIdentity();
            vgTranslate(matrix->getTranslateX(), matrix->getTranslateY());
            vgScale(matrix->getScaleX(), matrix->getScaleY());
            vgRotate(matrix->getRotation());
            characters_[entry->getCharacterId()]->draw();
        }
    
    }
private:
    CCIDisplayListEntry* entryForPlaceObject(CCIPlaceObject* placeObject)
    {
        CCIDisplayListEntry* displayListEntry = new CCIDisplayListEntry(placeObject);
        return displayListEntry;
    }

    static bool displayListEntryComparator(CCIDisplayListEntry* a, CCIDisplayListEntry* b)
    {
        return a->getDepth() < b->getDepth();
    }
    
private:
    typedef std::map<UI16, CCIDisplayListEntry*> CCIDisplayListEntries;
    typedef std::map<UI16, CCICharacter*> CCICharacters;
    
    CCIDisplayListEntries entries_;
    CCICharacters characters_;
};

#endif /* defined(__SWF__CCIDisplayList__) */
