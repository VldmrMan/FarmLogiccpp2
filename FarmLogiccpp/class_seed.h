#pragma once
#include <iostream>
#include <map>
#include "class_resourse.h"
#include "enum_types.h"

class seed: public entity
{
public:

    int value;
    double time_of_growth = -1;

    string _res;
    string _seed;

    map <int, int> resourses_reward;
    map <int, int> seed_reward;

public:
    seed(int id, string name,
        double time_of_growth = -1)
        :entity(id, name)
    {
        //нулевые мапы
        map <int, int> _t;
        resourses_reward = _t;

        map <int, int> __t;
        seed_reward = __t;

        this->time_of_growth = time_of_growth;
        this->type = types_entitys::t_seed;
    }
    seed() :entity(-1, "n/a")
    {
    }

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

