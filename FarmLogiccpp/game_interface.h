#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "test_databse.h"
#include "Keys.h"

#include "class_entity.h"
#include "class_seed.h"
#include "class_resourse.h"

#include "class_invertory.h"
using namespace std;

////////////////////////////////////////////////////////////

int  swap_cursor(bool mode, int cur, int size)
{
	size = size - 1;
	if (mode == 1)
	{
		if (cur + 1 <= size)
			return cur + 1;
		else
			return cur;
	}

	else
	{
		if (cur - 1 >= 0)
			return cur - 1;
		else
			return cur;
	}
};

void main_show(vector<map<string, string>> data, int  CurentCursor, string header)
{


	int iterator = 0;
	cout << "*****" << header << "*****" << endl;
	if (CurentCursor != -1) {
		for (map<string, string> i : data)
		{
			if (iterator != CurentCursor)
				cout << char(symbol_unselect) << " ";
			else
				cout << char(symbol_select) << " ";
			for (pair<string, string> j : i)
			{
				cout << "[" << j.first << "]:[" << j.second << "] ";
			}
			iterator++;
			cout << endl;


		}
	}
	else
		cout << header << " is empty :(" << endl;
	cout << "*****" << header << "*****" << endl;
};

int  main_Window(vector<map<string, string>> data, string header)
{
	//-1 бэк
	//-2 платнт
	//-3 рес
	//-4 сид

	//-5 тики

	int CurentCursor;
	int MaxSize;

	MaxSize = data.size();
	if (MaxSize)
		CurentCursor = 0;
	else
		CurentCursor = -1;//заглушка

	while (true)
	{

		system("cls");


		main_show(data, CurentCursor, header);


		char i = _getch();

		switch (i)
		{
		case key_down:
			CurentCursor = swap_cursor(1, CurentCursor, MaxSize);
			break;
		case key_up:
			CurentCursor = swap_cursor(0, CurentCursor, MaxSize);
			break;
		case key_enther:

			//  data.at(CurentCursor).find("id")->second;
			//	cout << "returned:" << atoi(data.at(CurentCursor).find("id")->second.c_str()) << endl;
			//	system("pause");
			return  atoi(data.at(CurentCursor).find("id")->second.c_str());


		case key_inv_plant:

			return -2;
			break;

		case key_inv_res:

			return -3;
			break;

		case key_inv_seed:

			return -4;
			break;

		case '5':

			return -5;
			break;

		}




	}



};

void modal_show(vector<map<string, string>> data, int  CurentCursor, string header)
{


	int iterator = 0;
	cout << "**************************" << endl;
	cout << "*****" << header << "*****" << endl;
	if (CurentCursor != -1) {
		for (map<string, string> i : data)
		{
			if (iterator != CurentCursor)
				cout << char(symbol_unselect) << " ";
			else
				cout << char(symbol_select) << " ";
			for (pair<string, string> j : i)
			{
				cout << "*[" << j.first << "]:[" << j.second << "] ";
			}
			iterator++;
			cout << endl;


		}
	}
	else
		cout << header << " is empty :(" << endl;
	cout << "*****" << header << "*****" << endl;
};

int  ModalWindow(vector<map<string, string>> data, string header)
{

	int CurentCursor;
	int MaxSize;

	MaxSize = data.size();
	if (MaxSize)
		CurentCursor = 0;
	else
		CurentCursor = -1;//заглушка



	while (true)
	{

		system("cls");


		modal_show(data, CurentCursor, header);


		char i = _getch();

		switch (i)
		{
		case key_down:
			CurentCursor = swap_cursor(1, CurentCursor, MaxSize);
			break;
		case key_up:
			CurentCursor = swap_cursor(0, CurentCursor, MaxSize);
			break;
		case key_enther:
			//data.at(CurentCursor).find("id")->second;
			return  atoi(data.at(CurentCursor).find("id")->second.c_str());

			break;
		}




	}



};


////////////////////////////////////////////////////////////

bool ModalYesNo(string header = "")
{

	char i;

	while (true)
	{
		system("cls");
		cout << "*** *** ***" << endl;

		if (header != "")
			cout << header << endl;

		cout << "   Confirm?" << endl;
		cout << "( yes - " << to_string(key_no) << ") (no -  " << key_no << ")" << endl;
		cout << "*** *** ***" << endl;

		i = _getch();
		if (i == char(key_no))
			return 0;

		if (i == char(key_yes))
			return 1;

	}


};

////////////////////////////////////////////////////////////

//не модельные могут возращать ќ“–»÷ј“≈Ћ№Ќџ… код
//отрицательный код открывает другое кокно


////////////////////////////////////////////////////////////



class Console_Interface
{
	int current_id;

	databse db;
	invertory inv;


	//-1 бэк
	//-2 платнт
	//-3 рес
	//-4 сид
	
public:

	Console_Interface(databse &db, invertory &inv)
	{



		current_id = -2;
		this->db = db;
		this->inv = inv;


	}

public:

	void start()
	{	
		int _buff = current_id;
		while (true)
		{
		
			int _buff;

			switch (current_id)
			{

			case -2:
				_buff = main_Window(inv.GetInfo_Plants(), "Plants");        //-2
				if (_buff > 0)
				{
					if (inv.invertory_plants.at(_buff -1).can_take )
						 inv.save_return_revawds_from_plant(db, _buff);
					else 
					{
						if (inv.invertory_plants.at(_buff - 1).active == 0)
						{
							int seedid = ModalWindow(inv.GetInfo_Seeds(), "Seeds");
							inv.save_seed_to_plant(seedid, _buff);
						}
					}
				}
				else
					if (_buff != -5)
						current_id = _buff;
					else
						inv.plant_add_tick();
				break;

			case -3:
				_buff = main_Window(inv.GetInfo_Resourses(), "Resourses");  //-3
				if (_buff > 0) {
				}
				else
					if (_buff != -5)
						current_id = _buff;
					else
						inv.plant_add_tick();
				break;

			case -4:
				_buff = main_Window(inv.GetInfo_Seeds(), "Seeds");          //-4
				if (_buff > 0) 
				{
				}
				else
					if (_buff != -5)
						current_id = _buff;
					else
						inv.plant_add_tick();
				break;
			}


		
		
		}



	}




};



