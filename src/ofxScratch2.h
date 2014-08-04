//
//  ofxScratch2.h
//
//
//  Created by Kenta Hara on 5/17/14.
//
//

#ifndef __ofxScratch2__
#define __ofxScratch2__

#include "ofxHTTPServer.h"
#include "ofMain.h"

namespace ofxScratch2 {
    class BlockEvent : public ofEventArgs {
    public:
        string name;
        vector<string>* paramaters;
        
        BlockEvent() {
            paramaters = NULL;
        }
        
        static ofEvent<BlockEvent> events;
    };
    
    class Offline : public ofxHTTPServerListener {
    public:
        Offline(){};
        ~Offline(){};
        
        void setup(string const serverroot, int const port = 8080);
        void updateValue(string const path, int value);
        
        void getRequest(ofxHTTPServerResponse &response);
        void fileNotFound(ofxHTTPServerResponse &response);
        void postRequest(ofxHTTPServerResponse &response){};
        
    private:
        ofBuffer poll();
        ofxHTTPServer *server;
        map<string, string> pool;
    };
}

#endif /* defined(__ofxScratch2__) */
