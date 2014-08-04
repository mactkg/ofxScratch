#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    scratchClient.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    scratchClient.update();
    scratchClient.sensorUpdate("message", "Helloworld!");
    scratchClient.sensorUpdate("mouseX", ofToString((float)ofGetMouseX()/ofGetWidth()));
    scratchClient.sensorUpdate("mouseY", ofToString((float)ofGetMouseY()/ofGetHeight()));
    scratchClient.sendMessage("bang");
}

//--------------------------------------------------------------
void ofApp::draw(){

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
