//
//  Histogram.cpp
//  flockingEnvironment
//
//  Created by James Bentley on 10/1/14.
//
//

#include "Histogram.h"

Histogram::Histogram(string newTitle, ofColor newColor)
{
    binNum = 10;
    binWidth = 25;
    maxHeight = 100;
    data = vector<float>();
    bins = vector<int>(10);
    location = ofVec2f();
    title = newTitle;
    color = newColor;
}

void Histogram::addPoint(float point)
{
    data.push_back(point);
}

void Histogram::display()
{
    sort(data.begin(), data.end());
    float min = data[0];
    float max = data[data.size() - 1];
    float div = (max > min) ? (max - min)/binNum : div = 0.0001;
    
    for(int i = 0; i < bins.size(); i++)
    {
        bins[i] = 0;
        for(int j = 0; j < data.size(); j++)
        {
            if((data[j] > min + i * div) && (data[j] < min + (i + 1) * div))
            {
                bins[i]++;
            }
        }
    }
    
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofSetColor(color);
    ofLine(0, 0, binNum * binWidth, 0);
    ofLine(0, -maxHeight, 0, 0);
    ofSetRectMode(OF_RECTMODE_CORNER);
    for(int i = 0; i < bins.size(); i++)
    {
        float height = ofMap(bins[i], 0, data.size(), 0, maxHeight);
        ofRect(i * binWidth, -height, binWidth, height);
        ofDrawBitmapString(ofToString(min + div * i, 1), i * binWidth, -(height + 5));
    }
    ofDrawBitmapString(title, 0, -maxHeight);
    ofPopMatrix();
}

void Histogram::clear()
{
    data.clear();
}

void Histogram::setLocation(float x, float y)
{
    location.x = x;
    location.y = y;
}