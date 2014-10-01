//
//  World.h
//  flocking
//
//  Created by James Bentley on 9/30/14.
//
//

#ifndef __flocking__World__
#define __flocking__World__

#include "ofMain.h"
#include "Food.h"
#include "Dove.h"
#include "Hawk.h"

class World
{
public:
    vector<Dove> doves;
    vector<Hawk> hawks;
    vector<Food> foods;

    
    void run();
    void display();
    
    void addDove(Dove doves);
    void addFood(Food food);
    void addHawk(Hawk hawk);
    
    World();
};


#endif /* defined(__flocking__World__) */
