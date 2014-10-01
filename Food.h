//
//  Food.h
//  flocking
//
//  Created by James Bentley on 9/30/14.
//
//

#ifndef __flocking__Food__
#define __flocking__Food__

#include "ofMain.h"

class Food
{
public:
    ofVec3f location;
    ofColor color;
    
    void display();
    Food(float x, float y);
};


#endif /* defined(__flocking__Food__) */
