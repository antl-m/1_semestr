#include "matrix.h"

matrix::matrix(int a, int b)
{
	deque<double> temp;

	for (int i = 0; i < b; ++i)
	{
		temp.push_back(0);
	}

	for (int i = 0; i < a; ++i)
	{
		val.push_back(temp);
	}

	n = a;
	m = b;
}

matrix  operator* (matrix a, matrix b)
{
	if (a.m != b.n) exit(0);

	matrix c(a.n,b.m);
	double res=0;

	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < b.m; ++j)
		{
			for (int q = 0; q < a.n; ++q)
			{
				res += a.val[i][q] * b.val[q][j];
			}
			
			c.val[i][j]=res;
			res = 0;
		}
	}
	return c;
}

matrix  operator+ (matrix a, matrix b)
{
	if (a.n != b.n ||a.m!=b.m) exit(0);

	matrix c(a.n,a.m);
	int res = 0;

	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			res = a.val[i][j] + b.val[i][j];
			
			c.val[i][j]=res;
			res = 0;
		}
	}
	return c;
}

matrix  operator- (matrix a, matrix b)
{
	if (a.n != b.n || a.m != b.m) exit(0);

	matrix c(a.n,a.m);
	int res = 0;

	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			res = a.val[i][j] - b.val[i][j];

			c.val[i][j]=res;
			res = 0;
		}
	}
	return c;
}

std::ostream& operator<< (std::ostream &out, matrix & a)
{
	for (int i = 0; i < a.n; ++i)
	{
		for (double t : a.val[i])
		{
			out << t << '\t';
		}
		out << endl;
	}
	return out;
}

matrix  trans (matrix a)
{
	matrix c(a.m,a.n);
	double res = 0;

	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			res = a.val[i][j];

			c.val[j][i]=res;
			res = 0;
		}
	}
	return c;
}

int det(matrix a)
{
	if (a.n != a.m) exit(0);

	double res = 0;
	int sign = 1;
	matrix temp(a.n-1,a.m-1);

	if (a.n == 1) { return a.val[0][0]; }

	int m = 0, n = 0;
	for (int i = 0; i < a.m; ++i)
	{
		for (int j = 1; j < a.n; ++j)
		{
			for(int k=0;k<a.m;++k)
			{
				if (k == i)
				{
					continue;
				}
				else
				{
					temp.val[n][m] = a.val[j][k];
					m++;
				}
			}
			n++;
			m = 0;
		}
		n = 0;
		m = 0;
		if (i % 2 == 0) { sign = 1; }
		else { sign = -1; }
		
		res += sign * a.val[0][i]*det(temp);
	}
	
	return res;
}

void matrix::random(int x)
{
	for (int i=0;i<n;++i)
	{
		for (int j = 0; j < m; ++j)
		{
			val[i][j] = rand() % (x + 1);
		}
	}
}

double matrix::minor(int a, int b)
{
	if (n != m) exit(0);

	matrix temp(n - 1, m - 1);
	int r = 0, s = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == a) { continue; }
		for (int j = 0; j < m; ++j)
		{
			if (j == b) { continue; }
			temp.val[r][s] = val[i][j];
			++s;
		}
		s = 0;
		++r;
	}

	int sign;

	sign = pow(-1, a + b);

	return sign * det(temp);
}

matrix matrix::inv()
{
	if (n != m) exit(0);

	double delta = det(*this);
	if (delta == 0) { exit(0); }
	matrix res(n, m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			res.val[i][j] = (this->minor(i, j))/delta;
		}
	}
	return trans(res);
}

matrix rivn(matrix a, matrix b)
{
	if (a.n != b.n || a.m != b.m || a.m != a.n || b.m != b.n) { cout << "error"; exit(0); }

	return a.inv()*b;
}

bool matrix::sym(matrix q)
{
	matrix b(0, 0);
	b = trans(q);

	if (n != b.n || m != b.m) { return 0; }

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (val[i][j] != b.val[i][j]) { return 0; }
		}
	}

	return 1;
}

void matrix::input()
{
	cout << "input " << n * m << " numbers: ";
	int i = 0;
	while (i < n * m) 
	{
		cin >> val[i / m][i % m];
		i++;
	}
}