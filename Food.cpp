//
//  Food.cpp
//  flocking
//
//  Created by James Bentley on 9/30/14.
//
//

#include "Food.h"

Food::Food(float x, float y)
{
    location.set(x, y);
    color = ofColor::gray;
}

void Food::display()
{
    ofSetColor(color);
    ofFill();
    ofCircle(location.x, location.y, 5);
}