#pragma once

#include <iostream>
#include "enum_types.h"
#include <string>


using namespace std;

//базовый класс объекта
//от него наследуются все объекты в игре


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
		return info;		
	}
		


};



