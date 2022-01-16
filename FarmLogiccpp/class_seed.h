#pragma once
#include <iostream>
#include <map>
#include "class_resourse.h"
#include "enum_types.h"

class seed: public entity
{
public:

    //цена продажи
    int value;
    //время роста
    double time_of_growth = -1;

    //после посадки семя при сборе вовращает другие семена и рессурсы
    //семена садят 
    //ресурсы - нет
    map <int, int> resourses_reward;
    map <int, int> seed_reward;

public:
    seed(int id, string name,
        double time_of_growth)
        :entity(id, name)
    {
        //нулевые начальныые значения
        map <int, int> _t;
        resourses_reward = _t;

        map <int, int> __t;
        seed_reward = __t;

        this->time_of_growth = time_of_growth;
        this->type = types_entitys::t_seed;
    }

    //функции добавления возвращаемых ресурсов  и семян

    void create_ressourse_reward(int rew, int val=1)
    {
        pair<int, int> _p;
        _p.first = rew;
        _p.second = val;
        resourses_reward.insert(_p);
    };

    void create_seed_reward(int rew, int val=1)
    {
        pair<int, int> _p;
        _p.first = rew;
        _p.second = val;
        seed_reward.insert(_p);
    };

    

};

