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
#include "test_databse.h"
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

class MyWindow
{

public:

	vector<map<string, string>> data;
	string header;


	bool periodic_update = true;


	int current_cursor;
	char current_screen;
	//1 гр€дки
	//2 ресурсы
	//3 сем€на
	invertory inv;
	databse db;

	MyWindow(invertory &inv, databse &db)
	{
		this->inv = inv;
		this->db = db;
		current_cursor = 0;
		current_screen = 1;

	}


	void swap_screen(char i)
	{

		switch (i)
		{

		case key_inv_plant:
			data = inv.GetInfo_Plants();
			if (data.size() != 0)
			{
				current_cursor = 0;
				current_screen = key_inv_plant;
			}
			else
			{
				current_cursor = -1;
				current_screen = key_inv_plant;
			}
			break;

		case key_inv_seed:
			data = inv.GetInfo_Seeds();
			if (data.size() != 0)
			{
				current_cursor = 0;
				current_screen = key_inv_seed;
			}
			else
			{
				current_cursor = -1;
				current_screen = key_inv_seed;
			}
			break;


		case key_inv_res:
			data = inv.GetInfo_Resourses();
			if (data.size() != 0)
			{
				current_cursor = 0;
				current_screen = key_inv_res;
			}
			else
			{
				current_cursor = -1;
				current_screen = key_inv_res;
			}
			break;


		}


	}

	void Show()
	{
		system("cls");
		int iterator = 0;
		cout << "*****" << header << "*****" << endl;
		if (current_cursor != -1) {
			for (map<string, string> i : data)
			{







				if (iterator != current_cursor)
					cout << char(symbol_unselect) << " ";
				else
					cout << char(symbol_select) << " ";
				for (pair<string, string> j : i)
				{

					if (j.first == "id")						
					{
						string name = db.get_name(stoi(j.second));
						
						cout << "[" << j.first << "]:[" << j.second << "::"<< name << "] ";
					}

					else
					{



					if (j.first == "seed_id")
					{
						string name = db.get_name(stoi(j.second));

						cout << "[" << j.first << "]:[" << j.second << "::" << name << "] ";
					}
					else
						cout << "[" << j.first << "]:[" << j.second << "] ";
					}



				}
				iterator++;
				cout << endl;
			}
		}
		else
			cout << header << " is empty :(" << endl;
		cout << "*****" << header << "*****" << endl;
	}

	void periodic_show()
	{

		while (true)
		{

			if (periodic_update)
			{

				update();
				Show();//показать
			}
			this_thread::sleep_for(time_screen_update);
		}


	}
		
	void Cursor_Down()
	{
		if (data.size()-1 > current_cursor)
			current_cursor++;
	}

	void Cursor_up()
	{
		if (current_cursor > 0)
			current_cursor--;
	}

	void start()
	{

		current_screen = key_inv_plant;

		thread th(&MyWindow::periodic_show, this);
		th.detach();


		while (true)
		{

			char i = _getch();

			switch (i)
			{
			case key_down:
				Cursor_Down();
				break;
			case key_up:
				Cursor_up();
				break;
			case key_inv_plant:
				swap_screen(key_inv_plant);
				break;
			case key_inv_seed:
				swap_screen(key_inv_seed);
				break;
			case key_inv_res:
				swap_screen(key_inv_res);
				break;
			case key_enther:
				Do();
				break;

			}



		}

	};

	void update()
	{	
			switch (current_screen)
			{

			case key_inv_plant:
				data = inv.GetInfo_Plants();
				header = "Plants";
				break;

			case key_inv_seed:
				data = inv.GetInfo_Seeds();
				header = "Seeds";
				break;


			case key_inv_res:
				header = "Resoursses";
				data = inv.GetInfo_Resourses();
				break;

			}
			
	}

	void Do()
	{
		if (current_cursor == -1)
			return;		//возможные ошибки
		if  ( data.at(current_cursor).find("id") == data.at(current_cursor).end())
			 return;	//возможные ошибки

		if (current_screen == key_inv_plant)
		{

			int  id = stoi(data.at(current_cursor).find("id")->second); //айди гр€дки
			int can_take = stoi(data.at(current_cursor).find("can_take")->second);
			if (can_take)
			{
				inv.save_return_revawds_from_plant(db, id);
				return;
			}
			int active = stoi(data.at(current_cursor).find("active")->second);
			if (!active)
			{
				int _seed = ShowModal(key_inv_seed);
				if (_seed!=0)
					inv.save_seed_to_plant(_seed, id);

				
			}


		}
	
	
	}

	int GetChisedId()
	{
	
		return stoi(data.at(current_cursor).find("id")->second);
		
	}

	int ShowModal(char screen)
	{
		int old_cursor  = current_cursor;
		char old_screen = current_screen;
		int choised_id = -1;
		//приостановить поток апдейта экрана
		periodic_update = false;

		string old_header = header;

		switch (screen)
		{
		
		case key_inv_plant:
			header = "Choise Plant";
			break;


		case key_inv_seed:
			header = "Choise Seed";
			break;


		case key_inv_res:
			header = "Choise Resourse:";
			break;
		
		}

		swap_screen(screen);
		
	//аналогично обычному show но не не может закрытьс€ без возврата значени€

		while (choised_id ==  -1)
		{
			Show();
			int c = _getch();
			switch (c)
			{
			case key_down:
				Cursor_Down();
				break;
			case key_up:
				Cursor_up();
				break;

			case key_enther:
				choised_id = GetChisedId();
				break;

			case key_back:
				choised_id = 0;
				break;

			}
		}
		
		header = old_header;
		current_cursor = old_cursor ;
		current_screen =  old_screen ;
		periodic_update = true;



		return choised_id;
	
	}



};

