#pragma once

#include <iostream>
#include <vector>
#include "class_resourse.h"

static class foo
{
public:
	static void show_all_res(vector<resourse> _data)
	{

		cout << "***************************" << endl;
		cout << "*********resourses*********" << endl;
		cout << "***************************" << endl;
		int i = 1;
		for (resourse this_res : _data)
		{
			cout << "\t" << "*" << i << "*" << endl;
			this_res.show();


		}
		i++;
	
	};

};

