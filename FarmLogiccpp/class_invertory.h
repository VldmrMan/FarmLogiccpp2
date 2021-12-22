#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "class_plant.h"
#include "test_databse.h"

using namespace std;
class invertory
{
public:

	plant null_plant;


	map<int, int> invertory_resourses;
	map<int, int> invertory_seeds;
	vector <plant> invertory_plants;
	databse data;

public:
	
	invertory() {
		null_plant.active = 0;
		null_plant.ActiveSeedId = 0;
		null_plant.plant_id = 0;
		null_plant.time_of_growth = 0;
	};

	plant invertory_search_plant(int id)
	{
		//можно переспеисть с итераторами
		for (plant i : invertory_plants)
		{
			
			if (i.plant_id == id)
			{
				return i;
			}
		}
		//return null_plant;

	}


#pragma region SomeAdd

	void add_plant()
	{
		plant _plant = plant();
		_plant.plant_id = invertory_plants.size() + 1;
		invertory_plants.push_back(_plant);


	};

	void add_resourse(int id, int value)
	{
		if (invertory_resourses[id] == 0)
			invertory_resourses[id] = value;
		else
			invertory_resourses[id] = invertory_resourses[id] + value;

	};

	void add_seed(int id, int value)
	{
		if (invertory_seeds[id] == 0)
			invertory_seeds[id] = value;
		else
			invertory_seeds[id] = invertory_seeds[id] + value;
	};

#pragma endregion

	//без проверок
	void seed_to_pnat(int seed_id, int plant_id,bool god = 0)
	{

			invertory_plants.at(plant_id -1).ActiveSeedId = seed_id;
			invertory_plants.at(plant_id -1).active = true;
			invertory_plants.at(plant_id -1).time_of_growth = data.GO_search_seed(seed_id).time_of_growth;

	};

	//без проверок
	void return_revawds_from_plant(databse db, int plant_id, bool god = 0)
	{
	   //если пришло время сбора
		if (invertory_search_plant(plant_id).time_of_growth == invertory_search_plant(plant_id).time_left || god)
		{
			seed  _seed = db.GO_search_seed(invertory_search_plant(plant_id).ActiveSeedId);
			for (pair <int, int> p : _seed.resourses_reward)
			{
				add_resourse(p.first, p.second);
			}

			for (pair <int, int> p : _seed.seed_reward)
			{
				add_seed(p.first, p.second);
			}
		}
	};

	//без проверок
	void plant_add_tick(int tick = 1, int id = 0)
	{
		if (id != 0)
		{
			for (int i = 0; i < tick; i++)
				invertory_plants.at(id - 1).plant_tick();
		}
		else
		{
			//на все пленты!
			for (int i =0; i< invertory_plants.size(); i++)
				invertory_plants.at(i).plant_tick();
		}

	};


};

