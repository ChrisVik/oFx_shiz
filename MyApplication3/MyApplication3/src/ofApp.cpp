#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(60);
	ofSetWindowTitle("Eat_A_Bag_O_Drangus");

	m_sample_rate = 44100;
	m_buffer_size = 512;

	leftSample.load("D:\\Skope - Sakura.wav", 0);
	rightSample.load("D:\\Skope - Sakura.wav", 1);

	maxiSettings::setup(m_sample_rate, 2, m_buffer_size);

	ofSoundStreamSetup(maxiSettings::channels, 0, this, m_sample_rate, m_buffer_size, 4);

	m_gui.setup("Audio Controlsssss");
	m_gui.setPosition(10, 10);
	m_gui.add(m_param_enable_loop.set("loop sample", false));
	m_gui.setPosition(10, 30);
	m_gui.add(m_param_loop_start.set("start:", 0.0f));
	m_gui.add(m_param_loop_end.set("end:", 1.0f));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	m_gui.draw();
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

void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
	double dataLeft;
	double dataRight;

	for (unsigned int i = 0; i < bufferSize; ++i)
	{
		if (m_param_enable_loop)
		{
			dataLeft = leftSample.playLoop(m_param_loop_start, m_param_loop_end);
			dataRight = rightSample.playLoop(m_param_loop_start, m_param_loop_end);
		}
		else
		{
			dataLeft = leftSample.playOnce();
			dataRight = rightSample.playOnce();

		}

		output[i * nChannels] = dataLeft;
		output[i * nChannels + 1] = dataRight;
	
	}
}