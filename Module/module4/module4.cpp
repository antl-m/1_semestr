
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double fact(long double num);

int main()
{
	
	long double eps, res=0, n=0, x=3;

	cin >> eps;
	
	bool flag=1;

	while (flag)
	{
		res += pow(-1, n) * (pow(x, 2 * n + 1) / fact(2 * n + 1));

		if (abs(res - sin(x)) < eps)
		{
			flag = 0;
		}
		else { n++; }
	}
	
	cout << setprecision(8) << res << endl << sin(x);
	system("pause");
	return 0;
}

long double fact(long double num)
{
	if (num < 0) return 0;

	else if (num == 0) return 1;

	else return num * fact(num - 1);
}