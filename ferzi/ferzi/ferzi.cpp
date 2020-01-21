#include <iostream>
#include <deque>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	long double a, n;

	while (1)
	{
		system("CLS");
		

		cout << "Программа показывает, какие из ферзей\nна заданом поле находятся в позиции атаки друг друга.\nВведите длину стороны поля: ";
		cin >> a;

		cout << endl << "Введите количество ферзей: ";
		cin >> n;

		if (n-(long long int)n!=0 || a - (long long int)a != 0)
		{
			cout << "Error: некорректные входные данные." << endl;
			system("pause");
			continue;
		}else if (n <= 0 || a <= 0)
		{
			cout << "Error: некорректные входные данные." << endl;
			system("pause");
			continue;
		}else if (n > (a * a))
		{
			cout << "Ферзей больше чем клеток поля." << endl;
			system("pause");
			continue;
		}
		

		deque<int> x, y;
		x.push_back(0);
		y.push_back(0);
		long long int nx, ny;
		bool flag=0;

		for (int i = 1; i <= n; i++)
		{
			cout << endl << "Введите координаты " << i << "-го ферзя (через пробел, от 1 до " << a << "): ";
			cin >> nx >> ny;
			
			if (nx > a || nx < 1 || ny > a || ny < 1)
			{
				flag = 1;
			}

			x.push_back(nx);
			y.push_back(ny);
		}

		if (flag) 
		{
			cout << "Ферзь вне поля." << endl;
			system("pause");
			continue;
		}

		bool flag2=0;
	
		for (long long int i = 1; i <= n; i++)
		{
			for (long long int k = 1; k <= n ; k++)
			{
				if (k <= i)
				{
					continue;
				}
				else if (x[i] - x[k] == y[i] - y[k] || x[i] - x[k] == y[k] - y[i])
				{
					flag2 = 0;
					for (long long int r = 1; r <= n; r++)
					{
						if (x[r] > x[i] & x[r] < x[k] || x[r] > x[k] & x[r] < x[i])
						{
							if (y[r] > y[i] & y[r] < y[k] || y[r] > y[k] & y[r] < y[i])
							{
								if (x[i] - x[r] == y[i] - y[r] || x[i] - x[r] == y[r] - y[i]) { flag2 = 1; }
							}
						}
					}
					if (flag2) continue;
					
					cout << "(" << x[i] << "; " << y[i] << ")  <->  (" << x[k] << "; " << y[k] << ")" << endl;
				}
				else if (x[i] == x[k])
				{
					flag2 = 0;
					for (long long int r = 1; r <= n; r++)
					{
						if (y[r] > y[i] & y[r] < y[k] & x[r]==x[i]  || y[r] > y[k] & y[r] < y[i] & x[r] == x[i])
						{
							flag2 = 1;
						}
					}
					if (flag2) continue;

					cout << "(" << x[i] << "; " << y[i] << ")  <->  (" << x[k] << "; " << y[k] << ")" << endl;
				}
				else if (y[i] == y[k])
				{
					flag2 = 0;
					for (long long int r = 1; r <= n; r++)
					{
						if (x[r] > x[i] & x[r] < x[k] & y[r] == y[i] || x[r] > x[k] & x[r] < x[i] & y[r] == y[i])
						{
							flag2 = 1;
						}
					}
					if (flag2) continue;

					cout << "(" << x[i] << "; " << y[i] << ")  <->  (" << x[k] << "; " << y[k] << ")" << endl;
				}
			}
		}
		system("pause");
	}
}