#include "renderer.h"

ofBoxPrimitive renderer::render3d(std::vector < std::vector<int> > &e)
{
	ofSetColor(24, 50, 124);
	ofBoxPrimitive lastnode;
	for (size_t i = 0 ; i <e.size() - 1; i++)
	{
		ofDrawBox(e[i][0] * dx, e[i][1] * dy, e[i][2] * dz, dx, dy, dz);
	}
	lastnode = ofBoxPrimitive(dx+1, dy+1, dz+1);
	int i = e.size() - 1;
	lastnode.setPosition(e[i][0] * dx, e[i][1] * dy, e[i][2] * dz);
	ofSetColor(124,50,24);
	lastnode.draw();
	
	return lastnode;

}

void renderer::render_blocks(std::vector<std::vector<int>>& e)
{
	ofSetColor(10, 10, 10);
	ofBoxPrimitive lastnode;
	for (size_t i = 0; i < e.size() - 1; i++)
	{
		ofDrawBox(e[i][0] * dx, e[i][1] * dy, e[i][2] * dz, dx, dy, dz);
	}
}

