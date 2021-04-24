#pragma once

#include "ofMain.h"
#include "../spacer.h"
#include "../renderer.h"
#include "ofCamera.h"

class ofApp : public ofBaseApp{
	ofCamera cam;
	spacer gra = spacer(2);
	int _c = 1;
	int i = 0;
	int count = 0;
	std::vector<ofLight> lights;
	float Angle = 0.0f;
	float AngleZ = 0.0f;
	int s = 30;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
