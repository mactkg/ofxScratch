//
//  ofxScratch2.cpp
//
//
//  Created by Kenta Hara on 5/17/14.
//
//

#include "ofxScratch2.h"

namespace ofxScratch2 {
    ofEvent<BlockEvent> BlockEvent::events;
    
    void Offline::setup(string const serverroot, int const port) {
        server = ofxHTTPServer::getServer();
        server->setServerRoot(serverroot);
        server->setCallbackExtensions("");
        server->setListener(*this);
        server->start(port);
    }
    
    void Offline::updateValue(string const path, string const value) {
        pool[path] = value;
    }
    
    void Offline::getRequest(ofxHTTPServerResponse &response) {
        if (response.url == "/poll") {
            response.response = poll();
        } else {
            vector<string> result = ofSplitString(response.url, "/");
            vector<string> paramaters = result = vector<string>(result.begin()+1, result.end());
            
            static BlockEvent newEvent;
            newEvent.name = result[0];
            newEvent.paramaters = &paramaters;
            
            ofNotifyEvent(BlockEvent::events, newEvent);
        }
    }
    
    void Offline::fileNotFound(ofxHTTPServerResponse &response) {
        vector<string> result = ofSplitString(response.url, "/");
        vector<string> paramaters = result = vector<string>(result.begin()+1, result.end());
        
        static BlockEvent newEvent;
        newEvent.name = result[0];
        newEvent.paramaters = &paramaters;
        
        ofNotifyEvent(BlockEvent::events, newEvent);
    }
    
    ofBuffer Offline::poll() {
        ofBuffer buf("");
        for (auto it = pool.begin(); it != pool.end(); it++) {
            buf.append(it->first + " " + it->second + "\n");
        }
        return buf;
    }
}
