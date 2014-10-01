//
//  Boid.cpp
//  flocking
//
//  Created by James Bentley on 9/29/14.
//
//

#include "Boid.h"

Boid::Boid(float x, float y, DNA newDNA)
{
    acceleration = ofVec2f(0, 0);
    float angle = ofRandom(TWO_PI);
    velocity = ofVec2f(cos(angle), sin(angle));
    location = ofVec2f(x, y);
    dna = newDNA;
    health = 200;
    maxForce = 0.03;
    
    maxSpeed = ofMap(dna.genes[0], 0, 1, 1, 5);
    r = ofMap(dna.genes[0], 0, 1, 5, 1);
    sepFac = ofMap(dna.genes[1], 0, 1, 1, 2);
    aliFac = ofMap(dna.genes[2], 0, 1, 0, 2);
    cohFac = ofMap(dna.genes[3], 0, 1, 0, 2);
}

void Boid::applyForce(ofVec2f force)
{
    acceleration += force;
}

bool Boid::isDead()
{
    return (health == 0) ? true : false;
}

void Boid::move()
{
    velocity += acceleration;
    velocity.limit(maxSpeed);
    location += velocity;
    acceleration *= 0;
}

ofVec2f Boid::seek(ofVec2f target)
{
    ofVec2f desired = target - location;
    desired.normalize();
    desired *= maxSpeed;
    
    ofVec2f steer = desired - velocity;
    steer.limit(maxForce);
    return steer;
}

void Boid::display()
{
    // Draw a triangle rotated in the direction of velocity
    float angle = (float)atan2(-velocity.y, velocity.x);
    float theta =  -1.0*angle;
    float heading2D = ofRadToDeg(theta)+90;
    
    ofEnableAlphaBlending();
    ofSetColor(color);
    ofFill();
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateZ(heading2D);
    ofTriangle(0, -r*2, -r, r*2, r, r*2);
    ofPopMatrix();
    ofDisableAlphaBlending();
}

void Boid::borders()
{
    if(location.x < -r) location.x = ofGetWidth()+r;
    if(location.y < -r) location.y = ofGetHeight()+r;
    if(location.x > ofGetWidth()+r) location.x = -r;
    if(location.y > ofGetHeight()+r) location.y = -r;
}

void Boid::attract(ofVec2f target)
{
    float G = 9.8;
    
    ofVec2f direction = target - location;
    float distance = ofDist(location.x, location.y, target.x, target.y);
    distance = ofClamp(distance, 5.0, 25.0);
    
    direction /= distance;
    float force = G / (distance * distance);
    direction *= force;
    
    acceleration += direction;
}

ofVec2f Boid::getLocation()
{
    return location;
}

ofVec2f Boid::getVelocity()
{
    return velocity;
}
ofVec2f Boid::getAcceleration()
{
    return acceleration;
}

float Boid::getR()
{
    return r;
}

float Boid::getMaxForce()
{
    return maxForce;
}

float Boid::getMaxSpeed()
{
    return maxSpeed;
}

float Boid::getSepFac()
{
    return sepFac;
}
float Boid::getAliFac()
{
    return aliFac;
}
float Boid::getCohFac()
{
    return cohFac;
}
ofColor Boid::getColor()
{
    return color;
}









