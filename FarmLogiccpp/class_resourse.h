#pragma once
#include <iostream>
#include "class_entity.h"
#include "enum_types.h"

using namespace std;

class resourse: public entity
{
    int value = 0;

    public:

    resourse(int id, std::string name) :entity(id, name)
    {
        this->type = types_entitys::t_resourse;
    }
    resourse():entity(-1,"n/a")
    {
    }
    


};

