//
//  DNA.h
//  flocking
//
//  Created by James Bentley on 9/30/14.
//
//

#ifndef flocking_DNA_h
#define flocking_DNA_h

#include "ofMain.h"

class DNA
{
public:
    vector<float> genes;
    
    int genomeLength;
    
    void mutate(float);
    
    DNA();
};

#endif
