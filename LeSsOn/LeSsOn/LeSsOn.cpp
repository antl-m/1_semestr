#include <__msvc_all_public_headers.hpp>

using namespace std;

void f1();
int f12(int,int m=1);
void f2();
vector <string> f22(string);
void f3();
bool f4(string, string);
void f5(string, int);
int num(deque<string>);
deque<string> mass;

int main()
{
	int key;
	
	while (1) 
	{
		system("CLS");

		cout << "Input num of func(1-5): " << endl;
		
		cin >> key;

		switch (key)
		{
		case 1: {f1(); break; }
		case 2: {f2(); break; }
		case 3: {f3(); break; }
		case 4: 
		{
			cout << "Enter word and pattern: ";
			string a, b;
			cin >> a >> b;
			cout << f4(a, b) << endl;
			break; 
		}
		case 5: {
			string str;
			int n;
			cin  >> str>> n;
			f5(str, n);
			break; }
		default: {break; }
		}

		if (key == 0) { break; }

		system("pause");
	}
	return 0;
}

void f1()
{
	cout << "enter your number: ";
	int n, res;
	cin >> n;
	res = f12(n);
	cout << res + 1 << endl;
}

int f12(int n, int m)
{

	if (m + m +1>= n) { return 1; }

	int res=0;
	
	for (int i = m + 1; i + m+1 <= n; i++)
	{
		res += f12(n-i, i);
	}

	return res;
}

void f2()
{
	cout << "enter your string: ";
	string s;
	cin >> s;
	vector <string> ss = f22(s);
	for (int i = 0, n1 = ss.size(); i < n1; ++i) cout << ss[i] << endl;
}

vector <string> f22(string s) 
{
	vector <string> res;
	if (s.size() == 1) 
	{
		res.push_back(s);
		return res;
	}
	for (int i = 0, n = s.size(); i < n; ++i) 
	{
		string t = s;
		vector <string> temp = f22(t.erase(i, 1));
		for (int j = 0, n2 = temp.size(); j < n2; j++) 
		{
			res.push_back(s[i] + temp[j]);
		}
	}
	return res;
}

string IntToString(int a) {
	string rez = "";
	string rez2 = a > 0 ? "" : "-";
	if (a < 0)a *= -1;
	while (a > 0) {
		rez += a % 10 + 48;
		a /= 10;
	}
	for (int i = rez.size() - 1; i >= 0; i--) rez2 += rez[i];
	return rez2;
}

void f3() 
{
	int sum = 0;
	int last;
	string mon = "";
	vector <int> nominals;
	while (1) {
		cin >> last;
		if (last <= 0) break;
		sum += last;
		nominals.push_back(last);
	}
	last = nominals.back();
	nominals.pop_back();
	sum -= last;
	if (sum * 2 < last) {
		cout << -1;
		return;
	}


	deque<bool> arr;

	for (int i = 0; i < 2 * nominals.size(); ++i)
	{
		arr.push_back(false);
	}

	int n = 2 * nominals.size();
	for (int i = 0; i < n; i++) arr[i] = false;
	arr[0] = true;
	int res = n + 1;
	while (1) {
		// chek on 0
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (arr[i]) {
				ok = true;
				break;
			}
		}
		if (!ok) break;
		// chek on mon
		int coutn = 0;
		int sum2 = 0;
		string qmon = "";
		for (int i = 0; i < n; i++) {
			if (arr[i]) {
				coutn++;
				if (qmon == "") qmon = IntToString(nominals[i / 2]) + " ";
				else qmon += "+ " + IntToString(nominals[i / 2]) + " ";
				sum2 += nominals[i / 2];
			}
		}
		if (sum2 == last) {
			if (res > coutn) {
				res = coutn;
				mon = qmon;
			}
		}
		// +1
		for (int i = 0; i < n; i++) {
			if (arr[i]) {
				arr[i] = false;
			}
			else {
				arr[i] = true;
				break;
			}
		}
	}
	if (res == n + 1) cout << "0" << endl;
	else {
		cout << res << endl;
		cout << last << " = " << mon << endl;
	}

}

bool f4(string slovo, string shabl)
{
	bool res = 0;
	bool f1 = 1;
	int a, b, miss;
	miss = 0;
	for (a = 0, b = 0; a < slovo.size() && b < shabl.size();)
	{
		if(slovo[a]==shabl[b] || shabl[b]=='?')
		{
			

			a++;
			b++;

			if (shabl[b] == '*') { f1 = 0; a--; }

			res = 1;


		}
		else if (shabl[b]=='*')
		{
			
			while (shabl[b + 1] == '*') { b++; }
			
			b++;

			if (b >= shabl.size())
			{
				res = 1;
				f1 = 0;
				break;
			}

			

			a = slovo.size() - 1;
			while(a >=0)
			{
				if (slovo[a] == shabl[b]|| shabl[b] == '?')
				{
					bool f2 = 0;
					for (int i = 0; i < a; i++)
					{
						if (slovo[i] == slovo[a]) 
						{
							f2 = 1;
						}
					}

					if (f2)
					{
						a--;
						continue;
					}

					a++;
					b++;
					res = 1;
					break;
				}
				else
				{
					a--;
					res = 0;
				}
			}
		}
		else { res = 0; a++; b++; }
		
	}

	for (int k = 0; k < shabl.size(); k++)
	{
		if (shabl[k] == '?')
		{
			miss++;
		}
	}

	if ((a<slovo.size() && b>=shabl.size())&&f1) { res = 0; }
	
	if ((a>=slovo.size() && b<shabl.size())&&f1) { res = 0; }

	if (miss > slovo.size()) { res = 0; }
	
	return res;
}

void f5(string str, int n)
{
	//123131445255255656 7

	if (str.size() <= n) {return;}

	deque<string> code;
	string part = "";
	bool flag = 0;
	int i, j;
	for (i = 0; i < str.size(); i++)
	{
		flag = 0;
		
		part = "";
		for (j = i + 1; j < str.size();)
		{
			metka:
			if (str[i] == str[j])
			{
				part += str[i];
				i++;
				j++;
				flag = 1;

				if (num(code) + part.size() >= n)
				{
					break;
				}
			}
			else if (flag)
			{
				break;
			}
			else
			{
				j++;
			}
		}

		if (j - i <= part.size())
		{
			code.push_back(part);
		}
		else if (part.size() != 0)
		{
			i--;

			if (j < str.size() - 1)
			{
				part = "";
				goto metka;
			}
		}
	}

	if (num(code) == n) {

		for (string a : code)
		{
			cout << a;
		}
		cout << endl;
	}
	else
	{
		cout << "NO\n";
	}
}

int num(deque<string> a)
{
	int res = 0;
	for (string b : a)
	{
		for (char c : b)
		{
			res++;
		}
	}

	return res;
}