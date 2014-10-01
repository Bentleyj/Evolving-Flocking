//
//  Hawk.h
//  flocking
//
//  Created by James Bentley on 10/1/14.
//
//

#ifndef __flocking__Hawk__
#define __flocking__Hawk__

#include "ofMain.h"
#include "Boid.h"
#include "Dove.h"

class Hawk : public Boid
{
public:
    Hawk(float x, float y, DNA dna);
    
    void run(vector<Hawk> hawks);
    void flock(vector<Hawk> hawks);
    
    ofVec2f separate(vector<Hawk> hawks);
    ofVec2f align(vector<Hawk> hawks);
    ofVec2f cohesion(vector<Hawk> hawks);
    
    Hawk reproduce();
    void eat(vector<Dove>&);
};

#endif /* defined(__flocking__Hawk__) */
