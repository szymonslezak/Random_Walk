#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setNearClip(0.0f);
	cam.setFarClip(-1.0f);
	cam.setFov(120);	
	//cam.setGlobalPosition({ 800,400,100 });
	s = 10; //Wielkoœæ uk³adu
	std::shared_ptr<renderer> rend = std::make_unique<renderer>(20.f,20.f, 20.f); //wielkoœæ elementów x y z
	gra.set_renderer(rend);
	//camera.rotate(90, camera.getUpDir());
	for (int i = 1; i < 4; i+= 1)
	{
		ofLight lgith;
		lgith.setPosition(i * 1000, i * 1000, i * 1000);
		lights.push_back(lgith);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	if (i < 999)
	{
		if (i % 1 == 0)
		{
			gra.run();
			//std::cout << i << std::endl;
			gra.write();
			/*if (gra.write_4())
				i = 1000;*/
		}
		i++;
	}
	else if (count < 100)
	{
		//gra.write();
		i = 0;
		count++;
		gra.reset(count);
		
	}
	else
	{
		ofExit(0);
	}
	

//c)
	



}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	
	ofEnableDepthTest();
	for (int i = 0; i < lights.size(); i++)
	{
		lights[i].enable();
	}
	ofBoxPrimitive nod = gra.render();
	gra.render_block();
	if (&nod != nullptr) //obs³uga kamery
	{
		glm::vec3 pos = nod.getPosition();
		glm::vec3 pos2 = pos;
		pos[0] -= 0;
		pos[1] +=0;
		if (count < 1)
			pos[2] = 50;
		else
		pos[2] += 300;//300;
		
		//cam.rollDeg(30);
		
		Angle += 2.f;
		AngleZ +=3.f;
		if (Angle > 360.f)
		{
			Angle = 0.0f;
		}
		if (AngleZ > 360.f)
			AngleZ = 0.0f;
		pos[0] = pos[0] + cos(Angle * PI / 180) * 20*s;
		pos[1] = pos[1] + sin(Angle * PI / 180) * 20*s;
		if(count > 1)
		pos[2] = pos[2] + cos(AngleZ * PI / 180) * sin(AngleZ * PI / 180) * 20*s*(cos(AngleZ * PI / 180) * sin(AngleZ * PI / 180) + 0.3);
		cam.setPosition(pos);



		cam.lookAt(pos2, ofVec3f(0, 0, 1));
		
		
		
	}



	//gra.render3dfresh(_c);
	//gra.render3d(_c);
	//gra.render(_c);
	//Sleep(5000);
	ofDisableDepthTest();
	if(count < 2)
	ofSaveFrame();
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
