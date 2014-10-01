#pragma once

#include "ofMain.h"
#include "World.h"
#include "Histogram.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    World world = World();
    
    bool dataOn;
    
    Histogram sizeDove = Histogram("Size", ofColor(255));
    Histogram sepDove = Histogram("Separation Factor", ofColor(255));
    Histogram aliDove = Histogram("Alignment Factor", ofColor(255));
    Histogram cohDove = Histogram("Cohesion Factor", ofColor(255));
    
    Histogram sizeHawk = Histogram("Size", ofColor(255, 0, 0));
    Histogram sepHawk = Histogram("Separation Factor", ofColor(255, 0, 0));
    Histogram aliHawk = Histogram("Alignment Factor", ofColor(255, 0, 0));
    Histogram cohHawk = Histogram("Cohesion Factor", ofColor(255, 0, 0));
};
