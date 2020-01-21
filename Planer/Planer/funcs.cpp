#include <__msvc_all_public_headers.hpp>
#include"funcs.h"

using namespace std;

ifstream fin;
ofstream fout;



void open(string n)
{
	fin.open(n);
}

void mainmenu(string name)
{
	string res;
	fin >> res;

	if (res == "")
	{
		cout << "Введите имя:  ";
		cin >> res;
		cin.ignore(INT_MAX, '\n');
		Fclear(name);
		fout << res << endl;
	}
	else { Fclear(name); }

	cout << "Привет, " << res<<'!'<<endl;

	cout << "Выбери режим:" << endl;
	cout << "1. edit" << endl;
	cout << "2. view" << endl;
	
	int key;
	cin.ignore(INT_MAX, '\n');
	cin >> key;

	if (key == 1)
	{
		edit(name);
	}
}

void edit(string n)
{
	cout << "Выбери режим:" << endl;
	cout << "1. add" << endl;
	cout << "2. delete" << endl;
	cout << "3. back" << endl;

	int key;
	cin.ignore(INT_MAX, '\n');
	cin >> key;

	if (key == 1) 
	{
		add();
	}
	else if (key == 2)
	{
		clear(n);
	}
}

void clear(string n)
{
	close();
	open(n);

}

void add()
{
	cout << "Чтобы добавить заметку введите ее в виде: <текст>,[место],[часы:минуты],<число.месяц>" << endl;
	
}

void Fout(string name) 
{
	close();
	fout.open(name, ios::app);
}

void close()
{
	fin.close();
	fout.close();
}

string convert(string line)
{
	string res = line;
	
	for (int i = 0; i< res.size(); i++)
	{
		if (res[i] == ' ')
		{
			res[i] = '_';
		}
	}
	
	
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] == '_')
		{
			res[i] = ' ';
			continue;
		}
		else if(res[i] == ' ')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	

	return res;
}

string unconvert(string line)
{
	string res = line;

	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] == '_')
		{
			res[i] = ' ';
		}
	}

	return res;
}
