#pragma once
#include <iostream>
#include "class_entity.h"
#include "enum_types.h"

using namespace std;

class resourse: public entity
{
public:
    int value = 0;
    //возможная стоимость продажи
    resourse(int id, std::string name) :entity(id, name)
    {
        this->type = types_entitys::t_resourse;
    }

};

