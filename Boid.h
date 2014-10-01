//
//  Boid.h
//  flocking
//
//  Created by James Bentley on 9/29/14.
//
//

#ifndef flocking_Boid_h
#define flocking_Boid_h

#include "ofMain.h"
#include "Food.h"
#include "DNA.h"

class Boid
{
public:
    Boid(float x, float y, DNA);
    
    void applyForce(ofVec2f force);
    bool isDead();
    
    void display();
    void borders();
    void move();
    
    void attract(ofVec2f target);
    ofVec2f seek(ofVec2f target);
    
    ofVec2f getLocation();
    ofVec2f getVelocity();
    ofVec2f getAcceleration();
    float getR();
    float getMaxForce();
    float getMaxSpeed();
    float getSepFac();
    float getAliFac();
    float getCohFac();
    ofColor getColor();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    
    DNA dna;
    int health;
    float r;
    float maxForce;
    float maxSpeed;
    float sepFac;
    float aliFac;
    float cohFac;
    ofColor color;
};

#endif
