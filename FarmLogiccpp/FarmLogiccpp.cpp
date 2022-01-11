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

#include <conio.h >//getch

#include "Keys.h"

using namespace std;


void ticker(invertory *inve)
{
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        (*inve).plant_add_tick();
        cout << "th" << endl;


    }

}

int main()
{

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
    inv.hard_seed_to_pnat(201, 2);


    inv.plant_add_tick(3,1);

#pragma endregion

////////////////////////////////////////////////////////////////////

    /*
    int z;
    while (true)
    {

       z = _getch();
       system("cls");
       switch (z)
       {

       case key_inv_plant:
           gameinterface::interface_invertory_plants(db, inv);
           break;
       case key_inv_seed:
           gameinterface::interface_invertory_resourse(db, inv);
           break;
       case key_inv_res:
           gameinterface::interface_invertory_seed(db, inv);
           break;


       }
    
    }

    return 0;
    */


  // cout<< _ModalWindow(i);


 //  cout << ModalWindow(inv.GetInfo_Plants(),"Plants") << endl;
 //  cout << ModalWindow(inv.GetInfo_Seeds(),"Seeds") << endl;
 //  cout << ModalWindow(inv.GetInfo_Resourses(),"Resourses") << endl;
 //  info::show_keys_code()
 //   AdminInterdace();



//        if (int(i) == key_inv_plant)
//            ModalWindow(inv.GetInfo_Plants(), "Plants");
//       if (int(i) == key_inv_res)
//            ModalWindow(inv.GetInfo_Resourses(), "Resourses");
//       if (int(i) == key_inv_seed)
//            ModalWindow(inv.GetInfo_Seeds(), "Seeds");



    //    while(true)

   // info::show_keys_code();

    //info::interface_plants();

    //main_Window(inv.GetInfo_Plants(), "Plants");

    /*

    int j = -4;
    while (true)
    {

        if (j < 0)
        {

            {
                switch (j)
                {
                case -2:
                    j = main_Window(inv.GetInfo_Plants(), "Plants"); //-2
                    if (j > 0)
                    {
                        inv.save_return_revawds_from_plant(db, j); j = -2;
                    }

                    break;
                case -4:
                    j = main_Window(inv.GetInfo_Seeds(), "Seeds"); //-4
                    break;
                case -3:
                    j = main_Window(inv.GetInfo_Resourses(), "Resourses"); //-3
                    break;
                }
            }

        }
        else
        {
            char i = _getch();
            switch (i)
            {
            case key_inv_plant:
                j = main_Window(inv.GetInfo_Plants(), "Plants"); //-2
                break;
            case key_inv_seed:
                j = main_Window(inv.GetInfo_Seeds(), "Seeds"); //-4
                break;
            case key_inv_res:
                j = main_Window(inv.GetInfo_Resourses(), "Resourses"); //-3
                break;
            }
        }
       

    }

    */
    
   //ticker(&inv);


    thread th(ticker, &inv);
 




    Console_Interface inter = Console_Interface(db, inv);


    while (true)
    {
       // system("cls");
        vector <map<string, string>> i = inv.GetInfo_Plants();

        cout << i.at(1).find("progress")->second;

        this_thread::sleep_for(chrono::milliseconds(500));

    }


   // inter.start();
    th.detach();


}

