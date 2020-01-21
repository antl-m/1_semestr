#include <__msvc_all_public_headers.hpp>

using namespace std;

int big(string str);
int smal(string str);
int count(string str, int (*f)(string));
int arrsum(int* arr, int i=0);
void task3(string file);
void task4(string file);

int main()
{
	int key;

	while (1)
	{
		cout << "Input number of task: ";
		cin >> key;

		switch (key) {
		case 1:
		{
			int (*f1)(string);
			int (*f2)(string);

			f1 = big;
			f2 = smal;
			string str;

			cout << "Input your string: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, str);

			cout << abs(count(str, f1) - count(str, f2)) <<endl;
			break;
		}
		case 2:
		{
			int arr[10];
			cout << "Input your array(10 elements): ";
			cin.ignore(INT_MAX, '\n');
			cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8] >> arr[9];
			cout << arrsum(arr)<< endl;
			break;
		}
		case 3:
		{
			string file = "C:/Users/Antl_M/Desktop/file.txt";

			task3(file);
			break;
		}
		case 4:
		{
			string file2 = "C:/Users/Antl_M/Desktop/names.txt";

			task4(file2);
			break;
		}
		default: goto stop;
		}
		cout << endl;
	}

	stop:

	return 0;
}

int big(string str)
{
	int res = 0;

	for (char a : str)
	{
		if (a >= 'A' && a <= 'Z')
		{
			++res;
		}
	}
	return res;
}

int smal(string str)
{
	int res = 0;

	for (char a : str)
	{
		if (a >= 'a' && a <= 'z')
		{
			++res;
		}
	}
	return res;
}

int count(string str, int (*f)(string))
{
	return f(str);
}

int arrsum(int* arr, int i)
{
	int res;
	res = arr[i];

	if (i < 9)
	{
		return res + arrsum(arr, i + 1);
	}
	else
	{
		if(res%3==0)
		{
			cout << "3: yes" << endl;
		}
		if (res % 4 == 0)
		{
			cout << "4: yes" << endl;
		}
		if (res % 12 == 0)
		{
			cout << "12: yes" << endl;
		}
		return res;
	}
}

void task3(string file)
{
	ifstream fin;
	ofstream fout;
	fin.open(file);
	fout.open("C:/Users/Antl_M/Desktop/result.txt");
	string name, maxname, minname;
	double a, b, c, d, max = 0, min = INT_MAX, sum=0, count=0;

	while (fin >> name)
	{
		count+=4;
		fin >> a >> b >> c >> d;
		sum += a + b + c + d;
		fout << name << '\t' << (a + b + c + d) / 4 <<'\t'<< (((a + b + c + d) / 4) / 12) * 5<<endl;

		if(a>max)
		{
			max = a;
			maxname = name;
		}
		if (b > max)
		{
			max = b;
			maxname = name;
		}
		if (c > max)
		{
			max = c;
			maxname = name;
		}
		if (d > max)
		{
			max = d;
			maxname = name;
		}

		if (a <min)
		{
			min = a;
			minname = name;
		}
		if (b<min)
		{
			min = b;
			minname = name;
		}
		if (c <min)
		{
			min = c;
			minname = name;
		}
		if (d <min)
		{
			min = d;
			minname = name;
		}
	}
	fout << endl;

	double avrg = sum / count;

	fout << maxname << '\t' << max << endl;
	fout << minname << '\t' << min << endl << endl;
	fout << avrg << '\t' << (avrg / 12) * 5 << endl;

	if (fin.is_open() && fout.is_open())
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Error" << endl;
	}

	fin.close();
	fout.close();

}

void task4(string file)
{
	ifstream fin;
	fin.open(file);
	string AA, BB;
	string cur = "";
	deque<string> A, B;

	getline(fin, AA);
	getline(fin, BB);
	for (char m: AA)
	{
		if ( m ==' '||m=='\n'||m=='\t')
		{
			if (cur.size() != 0)
			{
				A.push_back(cur);
				cur = "";
			}
		}
		else
		{
			cur = cur + m;
		}

		if (m == AA[AA.size() - 1])
		{
			A.push_back(cur);
		}
	}
	cur = "";
	for (char m : BB)
	{
		if (m == ' ' || m == '\n' || m == '\t')
		{
			if (cur.size() != 0)
			{
				B.push_back(cur);
				cur = "";
			}
		}
		else
		{
			cur = cur + m;
		}

		if (m == BB[BB.size() - 1])
		{
			B.push_back(cur);
		}
	}

	for (string a : A)
	{
		cout << a << ' ';
	}
	bool flag = 1;
	for (string a : B)
	{
		flag = 1;
		for (string b: A)
		{
			if (a == b)
			{
				flag = 0;
			}
		}
		if (flag)
		{
			cout << a << ' ';
		}
	}

	cout << endl << "Input searchable name: ";
	string search;
	cin >> search;

	bool f1, f2;
	f1 = 0;
	f2 = 0;

	for (string a : A)
	{
		if (search == a)
		{
			f1 = 1;
		}
	}
	for (string a : B)
	{
		if (search == a)
		{
			f2 = 1;
		}
	}
	if (f1 || f2)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

	cout << endl;

	fin.close();
}