#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int radius = 300; radius > 0; radius -= 10) {

		ofSetColor(ofMap(radius, 0, 300, 0, 255));

		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 1) {

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			auto noise_param = ofMap(ofNoise(glm::vec3(location * 0.0085, ofGetFrameNum() * 0.02)), 0, 1, -30, 30);
			auto noise_radius = radius + noise_param * ofMap(radius, 0, 300, 1.5, 0);

			ofVertex(glm::vec2(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD)));
		}
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}