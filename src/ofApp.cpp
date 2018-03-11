#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    
//#ifdef TARGET_OPENGLES
//    shader.load("shadersES2/shader");
//#else
//    if(ofIsGLProgrammableRenderer()){
		shader.load("shadersGL3/shader"); //こいつを使っている
//    }else{
//        shader.load("shadersGL2/shader");
//    }
//#endif

    img.load("komorebi3.png");
    plane.set(ofGetWidth(), ofGetHeight(), 10, 10);
    plane.mapTexCoords(0, 0, ofGetWidth(), ofGetHeight());

    gui.setup();
    gui.add(contR.setup("contR", 1, 0.5, 500));
    gui.add(contG.setup("contG", 1, 0.5, 500));
    gui.add(contB.setup("contB", 1, 0.5, 500));
    gui.add(brightness.setup("brightness", 1, 0.001, 10));
}


//--------------------------------------------------------------
void ofApp::update() {
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    // テクスチャのピクセル情報にアクセスできるようにバインド
    img.getTexture().bind();
    
    // シェーダ実行
    shader.begin();
    //shader.setUniform1f("mouseX", mousePosition);
    shader.setUniform1f("contR", contR);
    shader.setUniform1f("contG", contG);
    shader.setUniform1f("contB", contB);
    shader.setUniform1f("brightness", brightness);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    plane.draw();

    ofPopMatrix();
    
    shader.end();

    img.getTexture().unbind();
    
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
