//
//  Histogram.h
//  flockingEnvironment
//
//  Created by James Bentley on 10/1/14.
//
//

#ifndef __flockingEnvironment__Histogram__
#define __flockingEnvironment__Histogram__

#include "ofMain.h"

class Histogram
{
public:
    ofVec2f location;
    int binNum;
    float binWidth;
    float maxHeight;
    vector<float> data;
    vector<int> bins;
    string title;
    ofColor color;
    
    void display();
    void setLocation(float x, float y);
    void clear();
    void addPoint(float point);
    
    Histogram(string newTitle, ofColor newColor);
};

#endif /* defined(__flockingEnvironment__Histogram__) */
