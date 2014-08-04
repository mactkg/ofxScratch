//
//  Rapiro.cpp
//  example2
//
//  Created by Kenta Hara on 5/29/14.
//
//

#include "Rapiro.h"

bool Rapiro::setup(string portName, int baud) {
    return serial.setup(portName, baud);
}

bool Rapiro::setAction(RapiroCommand cmd) {
    string buf = "#M" + ofToString((int)cmd);
    serial.writeBytes((unsigned char*)buf.c_str(), buf.length()+1);
}

bool Rapiro::setEyesColor(ofColor c) {
    setEyesColor((int)c.r, (int)c.g, (int)c.b);
}

bool Rapiro::setEyesColor(int r, int g, int b) {
    string buf = "#PR"+ofToString(r)+"G"+ofToString(g)+"B"+ofToString(b)+"T001";
    serial.writeBytes((unsigned char*)buf.c_str(), buf.length()+1);
}