#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    scratch.setup("", 8888);
    scratch.updateValue("position/ofWindowWidth", ofGetWidth());
    scratch.updateValue("position/ofWindowHeight", ofGetHeight());
    
    ofAddListener(ofxScratch2::BlockEvent::events, this, &ofApp::blockEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
    scratch.updateValue("position/mouseX", ofGetMouseX());
    scratch.updateValue("elapsedTime", ofGetElapsedTimeMillis());
    scratch.updateValue("position/mouseY", ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(bg);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

//--------------------------------------------------------------
void ofApp::blockEvent(ofxScratch2::BlockEvent &e){
    if (e.name == "bang") {
        bg = ofColor(ofRandom(180, 255), ofRandom(180, 255), ofRandom(180, 255));
    }
}