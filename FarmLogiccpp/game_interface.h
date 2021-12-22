#pragma once
#include <iostream>
#include <map>
#include "test_databse.h"

#include "class_entity.h"
#include "class_seed.h"
#include "class_resourse.h"

#include "class_invertory.h"
using namespace std;

static class gameinterface
{
	databse db;
	invertory inv;
	string prefix = "*";


	char c_back = 'q';   //0
	char c_up   = 'w';	//1
	char c_down = 's';	//2
	char c_enter = 'e';

	

	//булево с выбором
	//айди объеута
	//наименование строкой


public:


	gameinterface(databse db, invertory inv)
	{
		this->inv = inv;
		this->db = db;
	
	}

	//обработка выборов в меню
	int select_control()
	{
		char i;
		cin >> i;

		if (i == c_up)
			return 1;
		if (i == c_down)
			return 2;
		if (i == c_enter)
			return 3;
		if (i == c_back)
			return 0;

	}

	 void paint(vector < 	tuple<bool, int, string>	> data , string header)
	{
		string selectON =   "o";
		string selectOFF =  "x";


		cout << "--- " << header << " ---"<<endl;
		for (tuple<bool, int, string> i : data)
		{
		
			if (get<0>(i))
			cout << selectON;
			else
			cout << selectOFF;

				
			cout<<  " [ " << get<1>(i) << " ]" << get<2>(i) << endl;

				 

		
		}
		cout << "--- --- --- " << endl;


	}

	 void interface_invertory_seed()
	{
		 string header = "seed";
		vector <tuple<bool , int, string>> data;
		int iterator = 0;
		for (pair<int, int> i : inv.invertory_seeds)
		{


			int seed_id = i.first;
			seed _seed = db.GO_search_seed(seed_id);
			tuple<bool, int, string> j;
			j = { 0,iterator , _seed.getinfo() };
			iterator++;
			data.push_back(j);
				
		}
		paint(data, header);


		
	}

	 void interface_invertory_resourse()
	{
		 string header = "resourse";
		 vector <tuple<bool, int, string>> data;
		 int iterator = 0;
		 for (pair<int, int> i : inv.invertory_seeds)
		 {


			 int seed_id = i.first;
			 resourse _seed = db.GO_search_resourse(seed_id);
			 tuple<bool, int, string> j;
			 j = { 0,iterator , _seed.getinfo() };
			 iterator++;
			 data.push_back(j);

		 }
		 paint(data, header);
	}
	
	 void interface_invertory_plants()
	{
		 string header = "plant";
		vector <tuple<bool, int, string>> data;
		int iterator = 0;
		for (plant i : inv.invertory_plants)
		{

			string info = "Plant " + to_string(i.plant_id);
			if (i.active)
			{
				info = db.GO_search_seed(i.ActiveSeedId).getinfo();
				info = info + i.get_progress();
							
			}

				tuple<bool, int, string> j;
				j = { 0, iterator , info };
				iterator++;
				data.push_back(j);

		}
		paint(data,header);

	}


};

