#pragma once
//инпут
#include <iostream>
//#include <fstream>

//коллекции
#include <vector>
#include <map>

#include <conio.h >//getch

//базовый класс объектов
//#include "class_entity.h"
//классы объектов
//#include "class_resourse.h"
//#include "class_seed.h"


#include "data_base.h"
//#include "foo_info.h"
#include "test_databse.h"
#include "game_interface.h"
#include "Keys.h"



//using namespace std;

/*
точка входа в программу
*/


int main()
{

    
//тестовые значения
#pragma region load


    databse db;
    db.load();
    invertory inv;
    inv.data = db;

    inv.add_resourse(101, 15);
    inv.add_resourse(102, 15);

    inv.add_seed(201, 5);
    inv.add_seed(202, 5);


    inv.add_plant();
    inv.add_plant();
    inv.add_plant();

    inv.hard_seed_to_pnat(201, 1);
    inv.hard_seed_to_pnat(202, 2);


    inv.plant_add_tick(3,1);

#pragma endregion

    MyWindow W = MyWindow(inv,db);
    W.start();

}

