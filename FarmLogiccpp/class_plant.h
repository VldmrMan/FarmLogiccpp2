#pragma once

#include <string>


class plant
{
public:
	int plant_id = 0;
	bool active = 0;

	int ActiveSeedId = 0;
	int time_of_growth = 0;
	int time_left = 0;

	void plant_tick()
	{	
		if (active)
		{		
			if (time_of_growth > 0)
				if (time_left < time_of_growth)
					time_left++;
		}
	}	

	string get_progress()
	{
		string inf = "";
		inf = " [" + to_string(time_of_growth) + " / " + to_string(time_left) + "] ";
		if (time_of_growth != 0)
		{

			double percent = (time_of_growth / 100.0);
			percent = (time_left) / percent;


			inf = inf + to_string(percent) + "%";
		}
		return inf;
	}
};

