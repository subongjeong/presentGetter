#pragma once

#include "ofMain.h"
#define SET_Y 230
#define SET_H 400

struct Present{
    ofImage image;
    float   x;
    float   y;
    float   w;
    float   h;
    float   ratio; 
};

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void rollandStop();
    void centerCheck();
    
    ofSoundPlayer   bgm;
    ofSoundPlayer   tada;
    
    ofImage         back;
    ofImage         flash;
    vector<Present> present;
    vector<Present> presentRoll;
    ofDirectory     dirPresent;
    
    int             tmpCnt;
    int             firstPos;
    int             secondPos;
    float             speed;
    
    bool            bFullscreen;
    bool            bStart;
    bool            bPause;
};
