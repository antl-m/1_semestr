#include "library.h"
using namespace std;
double sin(double x, double eps)
{

	double res = 0;
	double temp = 1;
	for (int n = 0; abs(temp) > eps; ++n)
	{
		temp = (pow(-1, n) * (pow(x, 2 * n + 1) / fact(2 * n + 1)));
		res += temp;;
	}

	return res;
}

double fact(double num)
{
	if (num < 0) return 0;

	else if (num == 0) return 1;

	else return num * fact(num - 1);
}

double exp(double x, double eps)
{

	double res = 0;
	double temp = 1;
	for (int n = 0; abs(temp) > eps; ++n)
	{
		temp = pow(x, n) / fact(n);
		res += temp;;
	}

	return res;
}
