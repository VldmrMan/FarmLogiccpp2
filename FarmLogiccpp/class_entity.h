#pragma once

#include <iostream>
#include "enum_types.h"
#include <string>


using namespace std;


class entity
{
public:

	int id = 0;
	types_entitys type ;
	std::string name = "0";

public:
	entity(int _id, std::string _name)
	{
		this->type = types_entitys::t_entiy;
		this->id = _id;
		this->name = _name;

	}

	string getinfo()
	{	
		string info = "";
		info = (this->name) + "(" + to_string(this->id) + ")";
		//string _x = to_string(this->id   );
	
//		info = name + _x;
		return info;
		
	}
		

	
	void show_info()
	{


		cout << "***************************" << endl;

		if (type == types_entitys::t_entiy)
		{
			cout << "type: " << "t_entiy" << "(" << this->type << ")" << endl;
		}
		if (type == types_entitys::t_plant)
		{
			cout << "type: " << "t_plant" << "(" << this->type << ")" << endl;
		}
		if (type == types_entitys::t_resourse)
		{
			cout << "type: " << "t_resourse" << "(" << this->type << ")" << endl;
		}
		if (type == types_entitys::t_seed)
		{
			cout << "type: " << "t_seed" << "(" << this->type <<  ")"<< endl;
		}
		cout << "id: " << this->id << " name : " << this->name << endl;





	}


};



