//
//  DNA.cpp
//  flocking
//
//  Created by James Bentley on 9/30/14.
//
//

#include "DNA.h"

DNA::DNA()
{
    genomeLength = 4;
    
    for (int i = 0; i < genomeLength; i++)
    {
        float newGene = ofRandom(1);
        genes.push_back(newGene);
    }
    
}

void DNA::mutate(float mutationRate)
{
    if(ofRandom(1) < mutationRate)
    {
        genes[0] = ofRandom(1);
    }
    if(ofRandom(1) < mutationRate)
    {
        genes[1] = ofRandom(1);
    }
    if(ofRandom(1) < mutationRate)
    {
        genes[2] = ofRandom(1);
    }
    if(ofRandom(1) < mutationRate)
    {
        genes[3] = ofRandom(1);
    }
}