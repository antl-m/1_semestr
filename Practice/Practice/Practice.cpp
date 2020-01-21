#include <iostream>
#include "test.h" 
using namespace std;

int task1(int x);
int main()
{
	int x;
	cin >> x;
	int result = task1(x);
	cout << result;
	return 0;
}