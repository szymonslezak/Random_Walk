#pragma once
#include <vector>
#include <iostream>
#include "renderer.h"
#include"ofMain.h"
class spacer
{
	std::vector<std::vector<int>> positions;
	std::vector<std::vector<int>> blocades;
	std::shared_ptr<renderer> _render;
	std::ofstream file;
	std::ofstream file_4;
	const int dim;
	std::vector<int> helper = { 50,50,0 };
	void reset()
	{
		blocades.clear();
		std::vector<int> build = { 0,0,0 };
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				for (int z = 0; z <1; z++)
				{
					if (abs(ofRandomf()) > 0.5f)
					{
						build[0] = i;
						build[1] = j;
						build[2] = z;
						blocades.push_back(build);
					}
				}
			}
		}
		for (int z = 0; z < 1; z++)
		{
			for (int i = 0; i < 100; i++)
			{
				build = { i,0,z };
				blocades.push_back(build);
				build = { i,100,z };
				blocades.push_back(build);
				build = { 0,i,z };
				blocades.push_back(build);
				build = {100,i,z };
				blocades.push_back(build);

			}
		}
		positions.clear();
		positions.push_back(helper);
	}
	bool colision(std::vector<int> block);
public:
	spacer(int d = 1) :dim(d)
	{
		file = std::ofstream("spacer_2d0.5");
		//file_4 = std::ofstream("zad4_3d");
		std::vector<int> build = { 0,0,0 };
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				for (int z = 0; z < 1; z++)
				{
					if (abs(ofRandomf()) > 0.5f)
					{
						build[0] = i;
						build[1] = j;
						build[2] = z;
						blocades.push_back(build);
					}
				}
			}
		}
		for (int z = 0; z < 1; z++)
		{
			for (int i = 0; i < 100; i++)
			{
				build = { i,0,z };
				blocades.push_back(build);
				build = { i,100,z };
				blocades.push_back(build);
				build = { 0,i,z };
				blocades.push_back(build);
				build = { 100,i,z };
				blocades.push_back(build);

			}
		}

		positions.push_back(helper);
	}
	void write()
	{
		if (file.is_open())
		{
			file << positions[positions.size()-1][0] << " "<<positions[positions.size()-1][1];
			file << " \n";
		//	reset();
		}
	}
	void reset(int n)
	{
		file = std::ofstream("spacer_2d0.5"+std::to_string(n));
		reset();
	}
	bool write_4()
	{
		if (positions[positions.size() - 1] == helper)
		{
			if (file_4.is_open())
			{
				file_4 << "1 \n";
				reset();
				return true;
			}
		}
		if (positions.size() >= 999)
		{
			file_4 << "0 \n";
			reset();
			return true;
		}
		return false;

	}
	void run();
	ofBoxPrimitive render() { return _render->render3d(positions); }
	void render_block() { _render->render_blocks(blocades); }
	void set_renderer(std::shared_ptr<renderer> rend) { _render = rend; }
};

