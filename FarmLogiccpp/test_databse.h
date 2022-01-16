#pragma once

#include <vector>
#include "class_entity.h"
#include "class_seed.h"
#include "class_resourse.h"



class databse
{

	public:

	entity	   null_entity = entity(0, "null");
	seed	   null_seed = seed(0, "null",-1);
	resourse   null_resourse = resourse(0, "null");

	vector <entity> GO_entity;
	vector <seed> GO_seeds;
	vector <resourse> GO_resourses;

    public:
		databse()
		{
		};


	string get_name(int id)
	{
		string ret = "";
		for (entity i : GO_entity)
		{
			if (i.id == id)
				return i.name;
		}
		
		return "unfounded";
	}

	entity   GO_search_entity(int id   )
	{
		for (entity i : GO_entity)
		{
			if (i.id == id)
			{
				return i;
			}

		};
		return null_entity;
	};

	seed     GO_search_seed(int id   )
	{
		for (seed i : GO_seeds)
		{
			if (i.id == id)
			{
				return i;
			}

		};
		return null_seed;
	};
	
	resourse GO_search_resourse(int id )
	{
		for (resourse i : GO_resourses)
		{
			if (i.id == id)
			{
				return i;
			}
		};
		return null_resourse;
	};

	void load()
	{
		//seed 201-299
		//resourses 101-199
		seed x = seed(201, "Wheat seed", 50);
		x.create_ressourse_reward(101);
		x.create_seed_reward(201);

		seed y = seed(202, "Wood seed", 100);
		y.create_ressourse_reward(102);
		y.create_seed_reward(202);



		GO_seeds.push_back(x);
		GO_seeds.push_back(y);

		resourse xx = resourse(101, "Wheat");
		resourse xy = resourse(102, "Wood");

		GO_resourses.push_back(xx);
		GO_resourses.push_back(xy);



		GO_entity.push_back(x);
		GO_entity.push_back(y);
		GO_entity.push_back(xx);
		GO_entity.push_back(xy);


	};
	
};

