#pragma once


#include "test_databse.h"

#include "class_entity.h"
#include "class_seed.h"
#include "class_resourse.h"

#include "class_invertory.h"





static class info
{

public:

#pragma region show_info_db
	
	static void database_showinfo_entity(databse t, int id = 0)
	{

		if (id == 0)
		{
			for (entity i : t.GO_entity)
			{
				cout << "\t***" << endl
					<< " id " << i.id
					<< " name: " << i.name
					<< " type: " << i.type
					<< endl;
			}
		}
		else
		{
			for (entity i : t.GO_entity)
			{
				if (i.id == i.id)
				{
					cout
						<< " id " << i.id
						<< " name: " << i.name
						<< " type: " << i.type
						<< endl;
				}
			}
		}

	}

	static void database_showinfo_seed(databse t, int id = 0)
	{
		if (id == 0)
		{
			for (seed i : t.GO_seeds)
			{
				cout << "\t***" << endl
					<< "Id: " << i.id
					<< " name: " << i.name
					<< " type: " << i.type << endl
					<< "Resorse reward: "
					;

				for (pair<int, int> x : i.resourses_reward)
				{
					cout << x.first << ":" << x.second << ", ";

				}
				cout << endl << "Seed reward: ";
				for (pair<int, int> x : i.seed_reward)
				{
					cout << x.first << ":" << x.second << ", ";

				}
				cout << endl;
			}
		}
		else
		{
			for (seed i : t.GO_seeds)
			{
				if (i.id == id)
				{
					cout
						<< "\t***" << endl
						<< "Id: " << i.id
						<< " name: " << i.name
						<< " type: " << i.type << endl
						<< "Resorse reward: "
						;

					for (pair<int, int> x : i.resourses_reward)
					{
						cout << x.first << ":" << x.second << ", ";

					}
					cout << endl << "Seed reward: ";
					for (pair<int, int> x : i.seed_reward)
					{
						cout << x.first << ":" << x.second << ", ";

					}
					cout << endl;
				}
			}
		}

	}

	static void database_showinfo_resourse(databse t, int id = 0)
	{

		if (id == 0)
		{
			for (resourse i : t.GO_resourses)
			{
				cout << "\t***" << endl
					<< " id " << i.id
					<< " name: " << i.name
					<< " type: " << i.type
					<< endl;
			}
		}
		else
		{

			for (resourse i : t.GO_resourses)
			{
				if (i.id == id)
				{
					cout
						<< " id " << i.id
						<< " name: " << i.name
						<< " type: " << i.type
						<< endl;
				}
			}

		}
	}

#pragma endregion

#pragma region show_info_ivertory
	//hight detals
	static void invertory_showinfo_seeds(invertory inv,databse db)
	{
		cout << "\t*** Invertory Seeds: ***" << endl;
		for (pair<int, int> seeds : inv.invertory_seeds)
		{
			seed _seed = db.GO_search_seed(seeds.first);
			cout << "Seed: " << _seed.name << " (" << _seed.id << ") Value:"<< seeds.second << endl;
			cout << "\t Time of growth: " << _seed.time_of_growth << endl;
			cout << "\t Rewards:" << endl;


	
			for (pair<int, int> _resourse : _seed.resourses_reward)
			{
				resourse _res = db.GO_search_resourse(_resourse.first);
				cout << "\t\t Resourse :" << _res .name << " (" <<_res.id<<") Value: " <<_resourse.second<< endl;
			}


			for (pair<int, int> _seed : _seed.seed_reward)
			{
				seed _res = db.GO_search_seed(_seed.first);
				cout << "\t\t Seed :" << _res.name << " (" << _res.id << ") Value: " << _seed.second << endl;
			}
		

		}
		cout << "\t*** *** *** ***" << endl <<endl;
	}

	static void invertory_showinfo_resourses(invertory inv, databse db)
	{
		cout << "\t*** Invertory Resourses: ***" << endl;
		for (pair<int, int> resourses : inv.invertory_resourses)
		{
			resourse _resourse = db.GO_search_resourse(resourses.first);

			cout << "Resourse: " << _resourse.name << "(" << _resourse.id << ") Value: " << resourses.second<<endl;
		}
		cout << "\t*** *** *** ***" << endl << endl;

	}

	static void invertory_showinfo_plants(invertory inv, databse db)
	{
		cout << "\t*** Plants : ***" << endl;
		for (int i = 0; i< inv.invertory_plants.size(); i++)
		{

			plant _plant = inv.invertory_plants.at(i);
			cout << "Plant ID: " << _plant .plant_id<<endl;
			cout << "Actve: " << _plant.active << endl;
			cout << "Seed ID: " << _plant.ActiveSeedId << endl;

			if (_plant.ActiveSeedId != 0)
			{
				
				seed _seed = db.GO_search_seed(_plant.ActiveSeedId);
				cout << "Seed: " << _seed.name << " (" << _seed.id << ")"<< endl;
				cout << "\t Time of growth: " << _seed.time_of_growth << endl;
				cout << "\t Rewards:" << endl;



				for (pair<int, int> _resourse : _seed.resourses_reward)
				{
					resourse _res = db.GO_search_resourse(_resourse.first);
					cout << "\t\t Resourse :" << _res.name << " (" << _res.id << ") Value: " << _resourse.second << endl;
				}


				for (pair<int, int> _seed : _seed.seed_reward)
				{
					seed _res = db.GO_search_seed(_seed.first);
					cout << "\t\t Seed :" << _res.name << " (" << _res.id << ") Value: " << _seed.second << endl;
				}


			}

			cout << "\t***" << endl;

		}
		cout << "\t*** *** *** ***" << endl << endl;
	}

#pragma endregion

#pragma region show_interface
	//low detals
	static void interface_invertory(invertory inv, databse db)
	{
		cout << "\t ***invertory***" << endl;
		cout << "\t Resourses:" << endl;
		for (pair<int, int> i : inv.invertory_resourses)
			cout << db.GO_search_resourse(i.first).name << "(" << i.first << ")" << " x " << i.second << endl;
		cout << "\t Seeds:" << endl;
		for (pair<int, int> i : inv.invertory_seeds)
			cout << db.GO_search_seed(i.first).name << "(" << i.first << ")" << " x " << i.second << endl;
		cout << "*** *** *** *** ***" << endl;

	}

	static void interface_plants(invertory inv, databse db)
	{

		cout << "\t ***plants***" << endl;
		for (plant p : inv.invertory_plants)
		{
			cout << "ID:" << p.plant_id << " Active : " << p.active << endl;
			cout << "Seed: " << db.GO_search_seed(p.ActiveSeedId).name << "(" << db.GO_search_seed(p.ActiveSeedId).id << ")\t";

			if (p.active)
			{
				double percent = (p.time_of_growth / 100.0);
				percent = (p.time_left) / percent;
				cout << "TGrowth: " << p.time_of_growth << " Tleft: " << p.time_left << " [" << percent << "%]" << endl;
			}
			else
				cout << endl;

		}

	}


#pragma endregion

	/*
	//unused
	static void interface_plants_detal(invertory inv, databse db)
	{

		cout << "\t ***plants***" << endl;
		for (plant p : inv.invertory_plants)
		{
			cout << "ID:" << p.plant_id << " Active : " << p.active << endl;
			cout << "Seed: " << db.GO_search_seed(p.ActiveSeedId).name << "(" << db.GO_search_seed(p.ActiveSeedId).id << ")" << endl;

			if (p.active)
			{
				double percent = (p.time_of_growth / 100.0);
				percent = (p.time_left) / percent;
				cout << "TGrowth: " << p.time_of_growth << " Tleft: " << p.time_left << " [" << percent << "%]" << endl;
			}

		}

	}
*/

};