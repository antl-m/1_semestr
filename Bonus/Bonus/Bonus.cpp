//#include <__msvc_all_public_headers.hpp>
#include "matrix.h"
using namespace std;

void shvydke(int arr[], int n, int l, int r);


int main()
{	/*
	// ÑÎĞÒÓÂÀÍÍß ÂÑÒÀÂÊÀÌÈ________________________________________________________________________________________________________

	int arr[20];
	int n = 20;
	int j = 0, temp=0, key=0;

	for (int i = 0; i < 20; ++i) { arr[i] = rand() % 10; }
	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl;
	
	for (int i = 1; i < n;++i)
	{
		key = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > key) 
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}

	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl<<endl;

	// ÑÎĞÒÓÂÀÍÍß ÂÈÁÎĞÎÌ__________________________________________________________________________________________________________
	
	for (int i = 0; i < 20; ++i) { arr[i] = rand() % 20; }
	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl << endl;

	// ØÂÈÄÊÅ ÑÎĞÒÓÂÀÍÍß___________________________________________________________________________________________________________
	for (int i = 0; i < 20; ++i) { arr[i] = rand() % 30; }
	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl;

	shvydke(arr, n, 0, n - 1);

	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl << endl;

	// ÏÎĞÎÇĞßÄÍÅ ÑÎĞÒÓÂÀÍÍß(íà áàç³ ñîğòóâàííÿ âèáîğîì)___________________________________________________________________________
	for (int i = 0; i < 20; ++i) { arr[i] = rand() %10000; }
	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl;

	int max=0;
	
	for (int a : arr)
	{
		if (a > max) { max = a; }
	}
	
	for (int base = 1; base < max; base *= 10)
	{
		for (int i = 0; i < n; i++)
		{
			int temp = 0;

			for (int j = i + 1; j < n; j++)
			{
				if ((arr[i]/base)%(10*base) > (arr[j]/base) % (10 * base))
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	for (int a : arr)
	{
		cout << a << ' ';
	}   cout << endl << endl;
	*/

	
	// MATRIX______________________________________________________________________________________________________________________
	// ñòâîğşş ³ çàïîâíşş

	matrix a(3, 3), b(3, 3);
	
	a.random(5);
	b.random(5);

	matrix x(0, 0);
	x = rivn(a, b);
	cout << "A:\n"<< a<< endl<< "B:\n" << b << endl;
	cout << "A*X=B\nX:\n" << x << endl;

	matrix c = a * x;
	cout << c;
	
}

void shvydke(int arr[],int n,int l,	int r) 
{
	int il = l,
		ir = r;

	int middle = (r + l) / 2;

	int x = arr[middle];
	int y;

	do
	{
		while (arr[il] < x)
		{
			il++;
		}

		while (x < arr[ir])
		{
			ir--;
		}

		if (il <= ir)
		{
			y = arr[il];
			arr[il] = arr[ir];
			arr[ir] = y;

			il++;
			ir--;
		}
	} while (il < ir);

	if (l < ir)
	{
		shvydke(arr, n, l, ir);
	}

	if (il < r)
	{
		shvydke(arr, n, il, r);
	}
}
