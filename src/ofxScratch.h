/*
 *  ofxScratch.h
 *  
 *
 *  Created by mactkg on 10/2/11.
 *  Copyright 2011 Tokyo Tech High School of Science and Technoligy. All rights reserved.
 *
 */

#ifndef _OFXSCRATCH_H
#define _OFXSCRATCH_H

#include "ofxNetwork.h"

class ofxScratch {
public:
	void setup();
	void update();
	void sensorUpdate(string sensor, string value);
	void sendBroadcast(string value);
	bool broadcastScratch(string message);

	ofxTCPClient tcpClient;
	string msgTx, msgRx;

	float counter;
	int connectTime;
	int deltaTime;

	bool weConnected;
};
#endif
