//
//  Dove.cpp
//  flocking
//
//  Created by James Bentley on 10/1/14.
//
//

#include "Dove.h"

Dove::Dove(float x, float y, DNA dna) : Boid(x, y, dna)
{
    color = ofColor(255, 255, 255, 255);
}

void Dove::run(vector<Dove> doves)
{
    flock(doves);
    Boid::move();
    Boid::borders();
    Boid::display();
    health--;
}

void Dove::eat(vector<Food> &foods)
{
    for(int i = 0; i < foods.size(); i++)
    {
        float distance = location.distance(foods[i].location);
        
        if(distance < r + 5)
        {
            health += 100;
            foods.erase(foods.begin() + i);
        }
    }
}

void Dove::flock(vector<Dove> doves)
{
    ofVec2f sep = separate(doves);
    ofVec2f ali = align(doves);
    ofVec2f coh = cohesion(doves);
    
    sep *= sepFac;
    ali *= aliFac;
    coh *= cohFac;
    
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

Dove Dove::reproduce()
{
    if(ofRandom(1) < 0.005)
    {
        DNA childDNA = dna;
        
        childDNA.mutate(0.01);
        
        Dove child = Dove(location.x, location.y, childDNA);
        
        return child;
    }
    else
    {
        ofVec3f badLocation;
        badLocation.set(ofGetWindowWidth() + 100, ofGetWindowHeight() + 100);
        return Dove(badLocation.x, badLocation.y, dna);
    }
}

ofVec2f Dove::separate(vector<Dove> doves)
{
    float desiredSeparation = 25.0f;
    ofVec2f steer = ofVec2f(0, 0);
    int count = 0;
    
    for(int i = 0; i < doves.size(); i++)
    {
        ofVec2f diff = location - doves[i].location;
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

ofVec2f Dove::align(vector<Dove> doves)
{
    float neighborDist = 50.0f;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    
    for(int i = 0; i < doves.size(); i++)
    {
        ofVec2f diff = location - doves[i].location;
        float d = diff.length();
        if((d > 0) && (d < neighborDist))
        {
            sum += doves[i].velocity;
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

ofVec2f Dove::cohesion(vector<Dove> doves)
{
    float neighborDist = 50;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    
    for(int i = 0; i < doves.size(); i++)
    {
        ofVec2f diff = location - doves[i].location;
        float d = diff.length();
        if((d > 0) && (d < neighborDist))
        {
            sum += doves[i].location;
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


