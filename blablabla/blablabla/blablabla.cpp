// blablabla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	string a;
    cout  << "Привет, как тебя зовут?"<< endl;
	cin >> a;
	if (a == "Вероника" | a == "Вероничка" | a == "вероничка" | a == "вероника") {
		cout << "Я тебя очень люблю и обожаю)" << endl;
	}
	else {
		cout << "Кто это?" << endl;
	}
	return 0;

}