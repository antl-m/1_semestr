
#include <iostream>
using namespace std;

int main()
{
	int num;

	cin >> num;
	
	if (num > 3999 || num < 0) { cout << "Error" << endl; }
	else {
		switch (num / 1000)
		{
		case 3: {cout << "MMM"; break; }
		case 2: {cout << "MM"; break; }
		case 1: {cout << "M"; break; }
		default: break;
		}
		switch ((num % 1000) / 100)
		{
		case 9: {cout << "CM"; break; }
		case 8: {cout << "DCCC"; break; }
		case 7: {cout << "DCC"; break; }
		case 6: {cout << "DC"; break; }
		case 5: {cout << "D"; break; }
		case 4: {cout << "CD"; break; }
		case 3: {cout << "CCC"; break; }
		case 2: {cout << "CC"; break; }
		case 1: {cout << "C"; break; }
		default: break;
		}
		switch ((num % 100) / 10)
		{
		case 9: {cout << "XC"; break; }
		case 8: {cout << "LXXX"; break; }
		case 7: {cout << "LXX"; break; }
		case 6: {cout << "LX"; break; }
		case 5: {cout << "L"; break; }
		case 4: {cout << "XL"; break; }
		case 3: {cout << "XXX"; break; }
		case 2: {cout << "XX"; break; }
		case 1: {cout << "X"; break; }
		default: break;
		}
		switch (num % 10)
		{
		case 9: {cout << "IX"; break; }
		case 8: {cout << "VIII"; break; }
		case 7: {cout << "VII"; break; }
		case 6: {cout << "VI"; break; }
		case 5: {cout << "V"; break; }
		case 4: {cout << "IV"; break; }
		case 3: {cout << "III"; break; }
		case 2: {cout << "II"; break; }
		case 1: {cout << "I"; break; }
		default: break;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}