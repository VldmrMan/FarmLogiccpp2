#pragma once
//потоковый инпут
#include <iostream>
#include <fstream>

//удобные коллекции
#include <vector>
#include <map>
//перечисления и структуры
#include "enum_event_type_time.h"
#include "struct_dates_of_reward.h"
//базовый класс объектов
#include "class_entity.h"
//классы объектов
#include "class_resourse.h"
#include "class_seed.h"
#include "class_plant.h"
#include "class_house.h"

#include "data_base.h"

#include "class_foo_info.h"

#include "class_event.h"

#include "foo.h"

using namespace std;

int main()
{
	vector <resourse> resourses;
	data_base x = data_base("db_res.txt");
	x.refactoring();
	x.show();

	resourses = x._return_resourses();
	foo::show_all_res(resourses);


}
