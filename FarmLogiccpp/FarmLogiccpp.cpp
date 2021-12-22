#pragma once
//потоковый инпут
#include <iostream>
#include <fstream>

//удобные коллекции
#include <vector>
#include <map>

//базовый класс объектов
#include "class_entity.h"
//классы объектов
#include "class_resourse.h"
#include "class_seed.h"

#include "data_base.h"

#include "foo_info.h"

#include "test_databse.h"

#include "game_interface.h"


using namespace std;




int main()
{

    //-858993360 граница памяти
    databse db;
    db.load();
    invertory inv;
    inv.data = db;

    inv.add_resourse(101, 5);
    inv.add_resourse(101, 5);
    inv.add_resourse(102, 5);

    inv.add_seed(201, 5);
    inv.add_seed(202, 6);


    inv.add_plant();
    inv.add_plant();
    inv.add_plant();

    inv.seed_to_pnat(201, 1);

    inv.plant_add_tick(3,1);




    gameinterface _interface (db,inv);
    _interface.interface_invertory_plants();
    _interface.interface_invertory_resourse();
    _interface.interface_invertory_seed();
    
    return 0;


}

