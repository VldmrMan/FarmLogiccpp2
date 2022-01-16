#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include "class_seed.h"
#include "class_resourse.h"


using namespace std;

//старая версия для загрузки из файла
//не используется

class file_data_base
{
public:

    vector<map<string, string>> data;
    string t;
    ifstream fin;
    file_data_base(string way)
    {
        //конструктор - путь до файла
        fin = ifstream(way, ios::in);
    }

    string string_get_key(string _str)
    {
        int founded = 0;
        string __str = "";
        for (int i = 0; i < _str.size(); i++)
        {
            if (_str[i] == '"')
            {
                founded++;
            }
            switch (founded)
            {
            case 0:
                break;
            case 1:
            {
                if (_str[i] != '"')
                {
                    __str.push_back(_str[i]);
                }
                break;
            }
            case 2:
                return __str;
                break;
            }

        }
        return "";
    }

    string string_get_value(string _str)
    {
        int founded = 0;
        string __str = "";
        for (int i = 0; i < _str.size(); i++)
        {
            if (_str[i] == '"')
            {
                founded++;
            }
            switch (founded)
            {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
            {
                if (_str[i] != '"')
                {
                    __str.push_back(_str[i]);
                }
                break;
            }
            case 4:
                return __str;
                break;
            }

        }
        return "";
    }

    string string_get_type(string _str)
    {
        int founded = 0;
        for (int i = 0; i < _str.size(); i++)
        {

            if (_str[i] == '"')
            {
                founded++;
            }

            switch (_str[i])
            {
            case '[':
                return "m+";
                break;
            case ']':
                return "m-";
                break;
            case '{':
                return "v+";
                break;
            case '}':
                return "v-";
                break;
            default:
                break;

            }

        }
        switch (founded)
        {
        }
        return "s";
    }

    void refactoring()
    {

        map <string, string> thismap;
        string line;
        string _type;

        if (!fin.is_open()) // если файл не открыт
            cout << "err non founded file!\n"; // сообщить об этом 
        else
            while (getline(fin, line))
            {
                _type = string_get_type(line);

                if (_type == "m+")
                    cout << "start" << endl;
                if (_type == "m-")
                    cout << "finish" << endl;


                if (_type == "v+")
                    thismap.clear();
                if (_type == "v-")
                    this->data.push_back(thismap);
                if (_type == "s")
                    thismap[string_get_key(line)] = string_get_value(line);


            }

        //  Что делаем
        //1 записываем новый объект    
        //  сигнатура [
        //2 записываем свойство объекта
        // 
        //3 окончить запись
        //  сигнатура ]
        // 

    }

    void show()
    {
        for (map<string, string>_m : data)
        {
            cout << "**************" << endl;
            for (auto i : _m)
            {
                cout << "k:" << i.first << "\t";
                cout << "v:" << i.second << endl;
            }

        }

    }


};



