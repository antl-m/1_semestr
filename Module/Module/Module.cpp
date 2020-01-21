#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	int count=0, i=0;
	   
	getline(cin, a);

	for (int i = 0; i < a.size(); i++) 
	{
		switch (a[i])
		{
			case'a': { count++; break; }
			case'v': {count++; break; }
			case's': {count++; break; }
			case'm': {count++; break; }
			case'f': {count++; break; }
			case'A': { count++; break; }
			case'V': {count++; break; }
			case'S': {count++; break; }
			case'M': {count++; break; }
			case'F': {count++; break; }
			default: {break; }
		}
	}

	cout << count << endl;
	system("pause");
}