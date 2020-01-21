#include <__msvc_all_public_headers.hpp>
#include"funcs.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << timeinfo->tm_hour << endl;
	cout << timeinfo->tm_mday << endl;
	cout << timeinfo->tm_min << endl;
	cout << timeinfo->tm_mon << endl;
	cout << asctime(timeinfo) << endl;

	setlocale(LC_ALL, "rus");

	string name = "C:/Base.txt";
	open(name);

	return 0;
}

//qwe wer, ert rty, 12:05, 12.10