#include "funcs.h"

using namespace std;

int main()
{
	string file = "C:/Users/Antl_M/Desktop/countries.txt";
	
	bool exit = 0;


	while (1)
	{
		int key;

		cout << "Input number(1-6) of function (0 to exit): ";

		cin >> key;

		cout << endl;

		switch (key)
		{
		case 1: maxmin(file); break;
		case 2: MAXMIN(file); break;
		case 3: sortby(file); break;
		case 4: litoover30(file); break;
		case 5: zymaminus(file); break;
		case 6: search(file); break;
		case 0: exit = 1; break;
		}

		if (exit) { break; }
	}
	
	return 0;
}