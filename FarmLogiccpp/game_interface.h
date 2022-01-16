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

////////////////////////////////////////////////////////////

//не модельные могут возращать ќ“–»÷ј“≈Ћ№Ќџ… код
//отрицательный код открывает другое кокно


////////////////////////////////////////////////////////////

std::mutex mt; //объ€вление мьютекса

class MyWindow
{

public:

	vector<map<string, string>> data;
	string header;

	bool periodic_update = true;

	int current_cursor;
	char current_screen;


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
			mt.lock();

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
			mt.unlock();

		}

		void Show()
		{
			mt.lock();
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

							cout << "[" << j.first << "]:[" << j.second << "::" << name << "] ";
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
			mt.unlock();
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
			mt.lock();
			if (data.size() - 1 > current_cursor)
				current_cursor++;
			mt.unlock();
		}

		void Cursor_up()
		{
			mt.lock();
			if (current_cursor > 0)
				current_cursor--;

			mt.unlock();
		}

		void start()
		{

			thread th(&MyWindow::periodic_show, this);

			current_screen = key_inv_plant;

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
			mt.lock();
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
			mt.unlock();
		}

		void Do()
		{
			if (current_cursor == -1)
				return;		//возможные ошибки
			if (data.at(current_cursor).find("id") == data.at(current_cursor).end())
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
					if (_seed != 0)
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
			int old_cursor = current_cursor;
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

			while (choised_id == -1)
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
			current_cursor = old_cursor;
			current_screen = old_screen;
			periodic_update = true;



			return choised_id;

		}
	


};

