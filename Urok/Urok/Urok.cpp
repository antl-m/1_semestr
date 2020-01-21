#include <iostream>

using namespace std;

int main()
{

	while (1)
	{
		int a[50];
		int b[50];
		int c[50];
		long long int aa, bb, i, aaa, bbb;
		char op;

		for (i = 0; i < 51; ++i)
		{
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		system("CLS");

		cin >> aa >> op >> bb;
		aaa = aa;
		bbb = bb;
		i = 0;

		if (op == '-' & aa < bb)
			cout << '-';

		while (aa > 0)
		{
			a[i] = aa % 10;
			aa = aa / 10;
			++i;
		}

		i = 0;

		while (bb > 0)
		{
			b[i] = bb % 10;
			bb = bb / 10;
			++i;
		}

		if (op == '+')
		{


			i = 0;

			while (i < 50)
			{
				c[i] = (a[i] + b[i]) % 10;
				if ((a[i] + b[i]) >= 10)
					a[i + 1] += 1;
				++i;
			}

			bool flag = true;

			for (i = 50; i >= 0; i--)
			{
				if (flag)
				{
					while (c[i] == 0)
					{
						if (c[i - 1] != 0)
							flag = false; 
						i--;
					}
				}
				cout << c[i];
			}
		}
		else if (op == '-')
		{			
				if (aaa >= bbb)
				{
					i = 0;
					while (i < 50)
					{
						c[i] = a[i] - b[i];
						if ((a[i] - b[i]) < 0)
						{
							a[i + 1] -= 1;
							c[i] += 10;
						}
						i++;
					}
				}
				else if (bbb > aaa)
				{
					i = 0;
					while (i < 50)
					{
						c[i] = b[i] - a[i];
						if ((b[i] - a[i]) < 0)
						{
							b[i + 1] -= 1;
							c[i] += 10;
						}
						i++;
					}
				}


			bool flag = true;

			for (i = 50; i >= 0; i--)
			{
				if (flag)
				{
					while (c[i] == 0)
					{
						if (c[i - 1] != 0)
							flag = false;
						i--;
					}
				}
				cout << c[i];
			}
		}
		cout << endl;
		system("pause");
	}
	return 0;
}