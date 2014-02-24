#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    ofSetBackgroundAuto(true);
    ofSetVerticalSync(true);
    
    bgm.loadSound("bgm/bgm.mp3");
    bgm.setVolume(0.75f);
    bgm.setMultiPlay(false);
    bgm.setLoop(true);
    bgm.play();
    
    tada.loadSound("bgm/tada.mp3");
    tada.setVolume(0.75f);
    tada.setMultiPlay(false);
    tada.setLoop(false);
    
    back.loadImage("child.png");
    flash.loadImage("flash.png");
    dirPresent.listDir("present");
    
    if(dirPresent.size() > 0){
        for(int i=0; i<dirPresent.size(); i++){
            Present tmpimg;
            tmpimg.image.loadImage(dirPresent.getPath(i));
            
            if(i == 0){
                float w = tmpimg.image.width;
                float h = tmpimg.image.height;
                tmpimg.ratio = w/h;
                tmpimg.h = SET_H;
                tmpimg.w = SET_H*tmpimg.ratio;
                tmpimg.y = SET_Y;
                tmpimg.x = 0;
            }else{
                float w = tmpimg.image.width;
                float h = tmpimg.image.height;
                tmpimg.ratio = w/h;
                tmpimg.h = SET_H;
                tmpimg.w = SET_H*tmpimg.ratio;
                tmpimg.y = SET_Y;
                tmpimg.x = present[i-1].x + present[i-1].w;
            }
            present.push_back(tmpimg);
        }
    }
    presentRoll = present;
    bFullscreen = true;
    bPause      = false;
    
    tmpCnt = 0;
    speed = 10;
    firstPos = 0;
    secondPos = firstPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w;
}

//--------------------------------------------------------------
void testApp::update(){
    if(firstPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w <= 0){
        firstPos = secondPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w;
    }
    
    if(secondPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w <= 0){
        secondPos = firstPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w;
    }
    
    
    ofSoundUpdate();
    centerCheck();
    ofSetFullscreen(bFullscreen);
    if(bFullscreen)
        ofHideCursor();
    else
        ofShowCursor();
    
    if(bPause){
        
    }else{
        firstPos -= speed;
        secondPos -= speed;
        
        if(bStart){
            if(speed < 100)
                speed += 0.5;
            
        }else{
            if(speed > 10)
                speed -= 0.3;
            //        if(speed <= 10 && (firstPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w <= 0)){
            //            firstPos = secondPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w;
            //        }
            if(speed <= 10 && (secondPos > firstPos) && (firstPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w <= 0)){
                firstPos = secondPos + presentRoll[presentRoll.size()-1].x + presentRoll[presentRoll.size()-1].w;
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255,255,255,255);
    
    ofPushMatrix();
    ofTranslate(firstPos, 0);
    for(int i=0; i<presentRoll.size(); i++){
        presentRoll[i].image.draw(presentRoll[i].x, presentRoll[i].y, presentRoll[i].w, presentRoll[i].h);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(secondPos, 0);
    for(int i=0; i<presentRoll.size(); i++){
        presentRoll[i].image.draw(presentRoll[i].x, presentRoll[i].y, presentRoll[i].w, presentRoll[i].h);
    }
    
    ofPopMatrix();
    back.draw(0, 0);
    
    if(bPause){
        flash.draw(0,0);
    }
}

//--------------------------------------------------------------
void testApp::centerCheck(){
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'F':
        case 'f':
            bFullscreen = !bFullscreen;
            break;
            
        case 'S':
        case 's':
            bStart = !bStart;
            break;
            break;
            
        case ' ':
            bPause = !bPause;
            if(bPause){
                tada.setPositionMS(3000);
                tada.play();
            }
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
