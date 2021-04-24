#include "spacer.h"

bool spacer::colision(std::vector<int> block)
{
	for (int i = 0; i < blocades.size(); i++)
	{
		if (block == blocades[i])
			return true;
	}
	return false;
}

void spacer::run()
{
	std::vector<int> going{ 0,0,0 };
	std::vector<int> helper;
	if (dim > 1)
	{
		for (int i = 0; i < dim; i++)
		{
			float rng = abs(ofRandomf());
			if (rng < 1.f/2.f)
			{
				going[i] = -1;
				helper.push_back(positions[positions.size() - 1][i] - 1);
			}

			else
			{
				going[i] = 1;
				helper.push_back(positions[positions.size() - 1][i] + 1);
			}
		}
		/*float rng = abs(ofRandomf());
		if (rng < 1.f / 2.f)
		{
			//rng = abs(ofRandomf());
			if (rng < 1.f / 4.f)
			{
				helper.push_back(positions[positions.size() - 1][0] - 1);
				going[0] = -1;
			}
			else
			{
				going[0] = 1;
				helper.push_back(positions[positions.size() - 1][0] + 1);
			}
			helper.push_back(positions[positions.size() - 1][1]);
		}
		else
		{
			//rng = abs(ofRandomf());
			helper.push_back(positions[positions.size() - 1][0]);
			if (rng < 3.f / 4.f)
			{
				going[1] = -1;
				helper.push_back(positions[positions.size() - 1][1] - 1);
			}
			else
			{
				going[1] = 1;
				helper.push_back(positions[positions.size() - 1][1] + 1);
			}
		}*/
		//std::cout << positions[positions.size() - 1][0] << " " << positions[positions.size() - 1][1] << std::endl;
		for (int i = 0; i < 3 - dim; i++)
		{
			helper.push_back(0);
		}
		int j = 0;
		while (colision(helper))
		{
			j++;
			for (int i = 0; i < 3; i++)
				helper[i] = helper[i] - going[i];
			if (j > 1000)
			{
				reset();
				break;
			}
		}
		positions.push_back(helper);
	}
	else
	{
		if (abs(ofRandomf()) > 0.5)
		{
			helper.push_back(positions[positions.size() - 1][0] + 1);
		}
		else
		{
			helper.push_back(positions[positions.size() - 1][0] - 1);
		}
		helper.push_back(0);
		helper.push_back(0);
		positions.push_back(helper);
	}
}
