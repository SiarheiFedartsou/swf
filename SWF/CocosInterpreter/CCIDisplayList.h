//
//  CCIDisplayList.h
//  SWF
//
//  Created by Siarhei Fedartsou on 05.08.13.
//  Copyright (c) 2013 Siarhei Fedartsou. All rights reserved.
//

#ifndef __SWF__CCIDisplayList__
#define __SWF__CCIDisplayList__

#include "CCIDrawable.h"
#include "CCIPlaceObject.h"
#include "CCIRemoveObject.h"

class CCIDisplayList
{
public:
    void placeObject(CCIDrawable* drawable, CCIPlaceObject* placeObject)
    {
        list_.push_back(drawable);
    }
    
    void removeObject(CCIRemoveObject* removeObject)
    {
        
    }
private:
    std::vector<CCIDrawable*> list_;
};

#endif /* defined(__SWF__CCIDisplayList__) */
