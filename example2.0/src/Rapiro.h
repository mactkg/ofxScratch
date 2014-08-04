//
//  Rapiro.h
//  example2
//
//  Created by Kenta Hara on 5/29/14.
//
//

#ifndef __example2__Rapiro__
#define __example2__Rapiro__

#include "ofMain.h"

enum RapiroCommand {
    RAPIRO_CMD_STOP,
    RAPIRO_CMD_FORWARD,
    RAPIRO_CMD_BACKWARD,
    RAPIRO_CMD_TURN_RIGHT,
    RAPIRO_CMD_TURN_LEFT,
    RAPIRO_CMD_WAVE_HAND_BOTH,
    RAPIRO_CMD_WAVE_HAND_RIGHT,
    RAPIRO_CMD_GRAB_HAND_BOTH,
    RAPIRO_CMD_GRAB_HAND_LEFT,
    RAPIRO_CMD_STRETCH_OUT_HAND_RIGHT
};

class Rapiro {
    Rapiro(){};
    ~Rapiro(){};
    
    bool setup(string portName, int baud = 57600);
    
    bool setAction(RapiroCommand cmd);
    bool setEyesColor(int r, int g, int b);
    bool setEyesColor(ofColor c);
private:
    ofSerial serial;
};

#endif /* defined(__example2__Rapiro__) */
