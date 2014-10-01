#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    dataOn = false;
    
    ofBackground(0);
    
    for(int i = 0; i < 100; i++)
    {
        world.addDove(Dove(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), DNA()));
    }
    for(int i = 0; i < 100; i++)
    {
        world.addFood(Food(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
    for(int i = 0; i < 100; i++)
    {
        world.addHawk(Hawk(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), DNA()));
    }
    
    sizeDove.setLocation(5, ofGetHeight() - 5);
    sepDove.setLocation(305, ofGetHeight() - 5);
    aliDove.setLocation(605, ofGetHeight() - 5);
    cohDove.setLocation(905, ofGetHeight() - 5);
    
    sizeHawk.setLocation(5, ofGetHeight() - 125);
    sepHawk.setLocation(305, ofGetHeight() - 125);
    aliHawk.setLocation(605, ofGetHeight() - 125);
    cohHawk.setLocation(905, ofGetHeight() - 125);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    world.run();
    
    sizeDove.clear();
    sepDove.clear();
    aliDove.clear();
    cohDove.clear();
    
    sizeHawk.clear();
    sepHawk.clear();
    aliHawk.clear();
    cohHawk.clear();
    
    for(int i = 0; i < world.doves.size(); i++)
    {
        sizeDove.addPoint(world.doves[i].r);
        sepDove.addPoint(world.doves[i].sepFac);
        aliDove.addPoint(world.doves[i].aliFac);
        cohDove.addPoint(world.doves[i].cohFac);
    }
    
    for(int i = 0; i < world.hawks.size(); i++)
    {
        sizeHawk.addPoint(world.hawks[i].r);
        sepHawk.addPoint(world.hawks[i].sepFac);
        aliHawk.addPoint(world.hawks[i].aliFac);
        cohHawk.addPoint(world.hawks[i].cohFac);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    world.display();
    
    if(dataOn)
    {
        sizeDove.display();
        sepDove.display();
        aliDove.display();
        cohDove.display();
        
        sizeHawk.display();
        sepHawk.display();
        aliHawk.display();
        cohHawk.display();
    }

    ofSetColor(255);
    ofDrawBitmapString("Doves: " + ofToString(world.doves.size()), 10, 10);
    ofDrawBitmapString("Food: " +  ofToString(world.foods.size()), 10, 25);
    ofDrawBitmapString("Hawks: " +  ofToString(world.hawks.size()), 10, 40);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 10, 55);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key)
    {
        case 'd':
            dataOn = !dataOn;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //    for(int i = 0; i < world.doves.size(); i++)
    //    {
    //        world.doves[i].attract(ofVec2f(mouseX, mouseY));
    //    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    world.addDove(Dove(mouseX, mouseY, DNA()));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
