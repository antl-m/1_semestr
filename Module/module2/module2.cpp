#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	
	getline(cin, a);

	bool flag=1;

	for (int i = 0; i < (a.size())/2; i++)
	{
		if (a[i] != a[a.size() - 1 - i])
		{
			flag = 0;
		}
	}

	if (flag)
		cout << "true" << endl;
	else cout << "false" << endl;

	system("pause");
}