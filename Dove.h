//
//  Dove.h
//  flocking
//
//  Created by James Bentley on 10/1/14.
//
//

#ifndef __flocking__Dove__
#define __flocking__Dove__

#include "ofMain.h"
#include "Boid.h"

class Dove : public Boid
{
public:
    Dove(float x, float y, DNA dna);
    
    void run(vector<Dove> doves);
    void flock(vector<Dove> doves);
    
    ofVec2f separate(vector<Dove> doves);
    ofVec2f align(vector<Dove> doves);
    ofVec2f cohesion(vector<Dove> doves);
    Dove reproduce();
    void eat(vector<Food>&);
};

#endif /* defined(__flocking__Dove__) */
