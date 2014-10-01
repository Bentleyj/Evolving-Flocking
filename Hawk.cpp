//
//  Hawk.cpp
//  flocking
//
//  Created by James Bentley on 10/1/14.
//
//

#include "Hawk.h"

Hawk::Hawk(float x, float y, DNA dna) : Boid(x, y, dna)
{
    color = ofColor(255, 0, 0, 255);
}

void Hawk::run(vector<Hawk> hawks)
{
    flock(hawks);
    Boid::move();
    Boid::borders();
    Boid::display();
    health--;
}

void Hawk::eat(vector<Dove> &doves)
{
    for(int i = 0; i < doves.size(); i++)
    {
        float distance = location.distance(doves[i].location);
        
        if(distance < r + doves[i].r + 5)
        {
            health += 100;
            doves.erase(doves.begin() + i);
        }
    }
}

void Hawk::flock(vector<Hawk> hawks)
{
    ofVec2f sep = separate(hawks);
    ofVec2f ali = align(hawks);
    ofVec2f coh = cohesion(hawks);
    
    sep *= sepFac;
    ali *= aliFac;
    coh *= cohFac;
    
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

Hawk Hawk::reproduce()
{
    if(ofRandom(1) < 0.005)
    {
        DNA childDNA = dna;
        
        childDNA.mutate(0.01);
        
        Hawk child = Hawk(location.x, location.y, childDNA);
        
        return child;
    }
    else
    {
        ofVec3f badLocation;
        badLocation.set(ofGetWindowWidth() + 100, ofGetWindowHeight() + 100);
        return Hawk(badLocation.x, badLocation.y, dna);
    }
}

ofVec2f Hawk::separate(vector<Hawk> hawks)
{
    float desiredSeparation = 25.0f;
    ofVec2f steer = ofVec2f(0, 0);
    int count = 0;
    
    for(int i = 0; i < hawks.size(); i++)
    {
        ofVec2f diff = location - hawks[i].location;
        float d = diff.length();
        if((d > 0) && (d < desiredSeparation))
        {
            diff.normalize();
            diff /= d;
            steer += diff;
            count++;
        }
    }
    if(count > 0)
    {
        steer /= (float)count;
    }
    if (steer.length() > 0)
    {
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }
    return steer;
}

ofVec2f Hawk::align(vector<Hawk> hawks)
{
    float neighborDist = 50.0f;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    
    for(int i = 0; i < hawks.size(); i++)
    {
        ofVec2f diff = location - hawks[i].location;
        float d = diff.length();
        if((d > 0) && (d < neighborDist))
        {
            sum += hawks[i].velocity;
            count++;
        }
    }
    if(count > 0)
    {
        sum /= (float)count;
        sum.normalize();
        sum *= maxSpeed;
        ofVec2f steer = sum - velocity;
        steer.limit(maxForce);
        return steer;
    }
    else
    {
        return ofVec2f(0, 0);
    }
}

ofVec2f Hawk::cohesion(vector<Hawk> hawks)
{
    float neighborDist = 50;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    
    for(int i = 0; i < hawks.size(); i++)
    {
        ofVec2f diff = location - hawks[i].location;
        float d = diff.length();
        if((d > 0) && (d < neighborDist))
        {
            sum += hawks[i].location;
            count++;
        }
    }
    if(count > 0)
    {
        sum /= count;
        return seek(sum);
    }
    else
    {
        return ofVec2f(0, 0);
    }
}

