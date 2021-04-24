#pragma once
#include <vector>
#include "ofMain.h"
class renderer
{
	float dx;
	float dy;
	float dz;
public:
	renderer(float d_x,float d_y,float d_z)
	{
		dx = d_x;
		dy = d_y;
		dz = d_z;
	}
	ofBoxPrimitive render3d(std::vector<std::vector<int>>& e);
	void render_blocks(std::vector<std::vector<int>>& e);
};

