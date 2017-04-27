#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);//描画を積み重ね
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);//フレームの同期？U60
    ofSetCircleResolution(64);
    nBandsToGet = 1024;
    
    mySound.loadSound("tofubeats.mp3");
    
    mySound.setLoop(true);
    mySound.play();
    ofSoundUpdate();
    
    //int sphereSize =3;
    for(int i=0; i<200;i++) {
        mSphere[i].setPosition(ofRandom(-300,300),ofRandom(-300,300),ofRandom(-300,300));
       // mSphere[i].set(sphereSize,3);
    }
    
    korg.setup();
    gui.setup("KORG nanoKONTROL2");
    gui.add(knob[0].setup("knob1", 0, 0, 127));
    gui.add(knob[1].setup("knob2", 0, 0, 127));
    gui.add(knob[2].setup("knob3", 0, 0, 127));
    gui.add(knob[3].setup("knob4", 0, 0, 127));
    gui.add(knob[4].setup("knob5", 0, 0, 127));
    gui.add(knob[5].setup("knob6", 0, 0, 127));
    gui.add(knob[6].setup("knob7", 0, 0, 127));
    gui.add(knob[7].setup("knob8", 0, 0, 127));
    
    gui.add(slider[0].setup("Slider1", 0, 0, 127));
    gui.add(slider[1].setup("Slider2", 0, 0, 127));
    gui.add(slider[2].setup("Slider3", 0, 0, 127));
    gui.add(slider[3].setup("Slider4", 0, 0, 127));
    gui.add(slider[4].setup("Slider5", 0, 0, 127));
    gui.add(slider[5].setup("Slider6", 0, 0, 127));
    gui.add(slider[6].setup("Slider7", 0, 0, 127));
    gui.add(slider[7].setup("Slider8", 0, 0, 127));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBandsToGet);
    korg.update();
    
    
   for (int j = 0; j < 8; j++) {
        knob[j] = korg.knobs[j];
        slider[j] = korg.sliders[j];
        }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
   // ofSetColor(slider[0] * 2, slider[1] * 2, slider[2] * 2);
    //ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, knob[0] * 2);
    
  
    
    
    ofSetColor(0,0,0,20);//
    
    
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);//重なりあった色の暗い部分を強調する
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());//残ってrく図形
    ofEnableBlendMode(OF_BLENDMODE_ADD);//色を重ねるほど明るくなる
    
    
    ofSetColor(ofColor::fromHsb(slider[4]*2,slider[5]*2,slider[6],175*2));
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(slider[0]| 50);
    ofRotateX(slider[1]| 50);
    ofRotateY(slider[2]|ofGetFrameNum());//U60
    
    for(int i=0; i<200; i++){
        mSphere[i].draw();
       // int sphereSize =(float(nBandsToGet)/(150+knob[1]));
        int sphereSize =(3+(fft[i]*50));
        mSphere[i].set(sphereSize,3+(fft[i]*50));
            
            }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
