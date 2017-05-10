#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

	maxiSample leftSample;
	maxiSample rightSample;
	double m_current_sample;
	unsigned int m_sample_rate;
	unsigned int m_buffer_size;

	ofxPanel m_gui;
	ofParameter<bool> m_param_enable_loop;
	ofParameter<float> m_param_loop_start;
	ofParameter<float> m_param_loop_end;

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

		void audioOut(float * output, int bufferSize, int nChannels);
		
};
