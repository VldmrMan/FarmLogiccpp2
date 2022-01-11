#pragma once
#include <iostream>
#include <vector>
#include <map>

#include <thread>
#include <chrono>

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


#pragma region SomeRemove

	void remove_seed(int id, int value = 1)
	{
		if (invertory_seeds.end() != invertory_seeds.find(id))
		{

			if (invertory_seeds.find(id)->second > value)
				invertory_seeds.find(id)->second = invertory_seeds.find(id)->second - value;
			else
				invertory_seeds.erase(invertory_seeds.find(id));
		}
		else
		{
			cout << "cant remove resourses:non founded" << endl;

		}
	}

	void remove_resourse(int id, int  value = 1)
	{

		if (invertory_resourses.end() != invertory_resourses.find(id))
		{

			if (invertory_resourses.find(id)->second > value)
				invertory_resourses.find(id)->second = invertory_resourses.find(id)->second - value;
			else
				invertory_resourses.erase(invertory_resourses.find(id));
		}
		else
		{
			cout << "cant remove resourses:non founded" << endl;

		}
	}

#pragma endregion


#pragma region Functions

	//без проверок
	//меняет статус грядки
	//получает время роста семечка
	void hard_seed_to_pnat(int seed_id, int plant_id)
	{
		plant_id--;
		invertory_plants.at(plant_id ).ActiveSeedId = seed_id;
		invertory_plants.at(plant_id ).active = true;
		invertory_plants.at(plant_id ).time_of_growth = data.GO_search_seed(seed_id).time_of_growth;
	};

	//без проверок
	//используется база!!!!!!!
	void hard_return_revawds_from_plant(databse db, int plant_id)
	{
		plant_id = plant_id - 1;

		seed  _seed = db.GO_search_seed(invertory_plants.at(plant_id).ActiveSeedId);

		for (pair <int, int> p : _seed.resourses_reward)
		{
			add_resourse(p.first, p.second);
		}
		for (pair <int, int> p : _seed.seed_reward)
		{
			add_seed(p.first, p.second);
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
			for (int i = 0; i < invertory_plants.size(); i++)
				invertory_plants.at(i).plant_tick();
		}

	};


	///////////////////////////////////////////////////////////////////////////////////////

	int save_seed_to_plant(int seed_id, int plant_id)
	{
		plant_id--;

		auto x = invertory_seeds.find(seed_id);
		auto y = invertory_seeds.end();
		if (invertory_seeds.find(seed_id) == invertory_seeds.end())
			return 1;
		
		hard_seed_to_pnat(seed_id, plant_id+1);
		remove_seed(seed_id);
		return 0;
	};


	//проверка на созревание
	int save_return_revawds_from_plant(databse db, int plant_id)
	{
		plant_id = plant_id - 1;

		if (invertory_plants.at(plant_id).time_left != invertory_plants.at(plant_id).time_of_growth)
			return 1;
		seed  _seed = db.GO_search_seed(invertory_plants.at(plant_id).ActiveSeedId);
		if (_seed.id == 0 )
			return 1;
		hard_return_revawds_from_plant( db,  plant_id +1 );

		invertory_plants.at(plant_id).active = 0;
		invertory_plants.at(plant_id).ActiveSeedId = 0;
		invertory_plants.at(plant_id).time_of_growth = 0;
		invertory_plants.at(plant_id).time_left = 0;
		invertory_plants.at(plant_id).can_take = 0;
		return 0;
	}

#pragma endregion

#pragma region interactions

	void INV_CALLS(databse db,int move, int arg[] )
	{
		switch (move)
		{
		//add tick
		case 0:
			plant_add_tick();
		break;
		//seed to plant
		case 1:
			save_seed_to_plant(arg[0], arg[1]);
		break;
		//return rewards
		case 2:
			save_return_revawds_from_plant(db, arg[1]);
		break;
		}	
	}

#pragma endregion

#pragma region ToUserInterface

	//функции отчета о состоянии
	vector <map<string, string>> GetInfo_Seeds()
	{
		vector <map<string, string>> info;


		for (pair <int, int> i : invertory_seeds)
		{
				map<string, string> _info;


					pair<string, string> _p;

					_p.first = "id";
					_p.second = to_string(i.first);

					_info.insert(_p);

					_p.first = "value";
					_p.second = to_string(i.second);

					_info.insert(_p);
					info.push_back(_info);


		}
		return info;
	}

	vector <map<string, string>> GetInfo_Resourses()
	{
		vector <map<string, string>> info;

		for (pair <int, int> i : invertory_resourses)
		{
			map<string, string> _info;

			pair<string, string> _p;

			_p.first = "id";
			_p.second = to_string(i.first);

			_info.insert(_p);

			_p.first = "value";
			_p.second = to_string(i.second);

			_info.insert(_p);
			info.push_back(_info);
		}
		return info;
	}

	vector <map<string, string>> GetInfo_Plants()
	{
		vector <map<string, string>> info;

		for (plant i : invertory_plants)
		{
			map<string, string> _info;
			pair<string, string> _p;
					
			_p.first = "id";
			_p.second = to_string(i.plant_id);

			_info.insert(_p);

			_p.first = "active";
			_p.second = to_string(i.active);

			_info.insert(_p);

			_p.first = "seed_id";
			_p.second = to_string(i.ActiveSeedId);

			_info.insert(_p);

			_p.first = "progress";
			_p.second = i.get_progress();
			_info.insert(_p);

			_p.first = "can_take";

		//	if (i.can_take)
			_p.second = to_string(i.can_take);


			_info.insert(_p);

			info.push_back(_info);
		
		}
	
		return info;
	}



#pragma endregion


};

