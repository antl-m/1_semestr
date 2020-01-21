#include <iostream>
using namespace std;

int main()
{
	char a[] = "abcde\b\b\b\b\b\bqwert";
	cout << a;
	for (char c : a)
		cout << c;

	return 0;
}
