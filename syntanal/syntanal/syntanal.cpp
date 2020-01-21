#include <iostream>
#include <deque>
#include <cmath>

using namespace std;
struct var
{
	char name;
	double val;
};

double analize();
double numan();
void varan();


deque<var> vars;
char a, b;

int main()
{
	

	while (1) 
	{
		a = cin.get();

		if (a >= 'A' & a <= 'Z' || a >= 'a' & a <= 'z')
		{
			b = cin.get();
			if (b == '=')
			{
				varan();
				//cin.ignore(INT_MAX, '\n');
				continue;
			}
			else
			{
				cin.putback(b);
				cin.putback(a);
				cout << " = " << analize()<<endl ;
				//cin.ignore(INT_MAX, '\n');
				continue;
			}
		} else { cin.putback(a); }

		cout << " = " << analize()<<endl;
		

		cin.ignore(INT_MAX, '\n');
		
	}

	
	return 0;
}	

double analize()
{

	deque<double> nums;
	deque<char> symbs;

	bool f1 = 0;

	while (a!=')' && a!= '\n')
	{
		

		if (f1) { cin.putback(a); f1 = 0; }

		a = cin.get();

		

		if (a >= 'A' & a <= 'Z' || a >= 'a' & a <= 'z')
		{
			b = cin.get();
			
			if (b == '*' || b == '+' || b == '-' || b == '/' || b=='\n' || b == ')' || b == '(')
			{
				bool flag = 1;
				for (int i = 0; i < vars.size(); i++)
				{
					if (a == vars[i].name) { nums.push_back(vars[i].val); symbs.push_back(' '); cin.putback(b); flag = 0; }
				}
				if (flag) { cout << "ERROR" << endl; return 666; }
				//cin.putback(b);
				continue;
			}
			else { cout << "ERROR" << endl; return 666; }
		}

		//if (a >= 'A' & a <= 'Z' || a >= 'a' & a <= 'z')
		//{
		//	bool flag = 1;
		//	for (int i = 0; i < vars.size(); i++)
		//	{
		//		if (a == vars[i].name) { nums.push_back(vars[i].val); symbs.push_back(' '); cin.putback(b); flag = 0; }
		//	}
		//	//if (flag) { cout << "ERROR" << endl; return 666; }
		//	a = cin.get();
		//	if (a == '*' || a == '+' || a == '-' || a == '/' || a == '\n') { cin.putback(a); continue; }
		//	else if (a == ')' || a == '\n') { break; }
		//	else { cout << "ERROR" << endl; return 666; }
		//}

 		if (a >= '0' && a <= '9')
		{
			nums.push_back(numan()); symbs.push_back(' ');
			a = cin.get();
			if (a == '*' || a == '+' || a == '-' || a == '/' || a=='\n') { cin.putback(a); continue; }
			else if (a == ')' || a == '\n') { break; }
			else { cout << "ERROR" << endl; return 666; }
		}

		if (a == '*' || a == '+' || a == '-' || a == '/') { symbs.push_back(a); nums.push_back(-1); }

		if (a == '(') { nums.push_back(analize()); symbs.push_back(' '); a = cin.get(); f1 = 1; continue; }
	}

	

	for (int i = 0; i < nums.size(); i++)
	{
		if (symbs[i] == '*')
		{
			nums[i - 1] = nums[i - 1] * nums[i + 1];
			nums.erase(nums.begin() + i, nums.begin() + i + 2);
			symbs.erase(symbs.begin() + i, symbs.begin() + i +2);
			

			i--;
		}
		else if (symbs[i] == '/')
		{
			nums[i - 1] = nums[i - 1] / nums[i + 1];
			nums.erase(nums.begin() + i, nums.begin() + i + 2);
			symbs.erase(symbs.begin() + i, symbs.begin() + i + 2);
			i--;
		}
	}
	
	double res = 0;
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
		{
			if (nums[i] != -1)
			{
				res = res + nums[i];
			}
		}
		else 
		{
			if (nums[i] != -1)
			{
				if (symbs[i - 1] == '+') { res = res + nums[i]; continue; }
				else if (symbs[i - 1] == '-') { res = res - nums[i]; continue; }
			}
		}
	}
	return res;
}

double numan() 
{
	double num = 0;
	
	while (a >= '0' && a <= '9')
	{
		num = 10 * num + a - '0';
		a = cin.get();
	}
	if (a == '.') 
	{
		a = cin.get();
		int i=1;
		while (a >= '0' && a <= '9')
		{
			num = num + (a - '0')/pow(10, i);
			a = cin.get();
			i++;
		}
	}
	cin.putback(a);
	
	return num;
}

void varan()
{
	var temp;

	temp.name = a;
	temp.val = analize();

	vars.push_back(temp);

	cout << "Success" << endl;
}

//(a-b)*(a+b)