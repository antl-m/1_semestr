#include <__msvc_all_public_headers.hpp>

using namespace std;

int main()
{
	
	return 0;
}

//char* invert(char* num);
//int main()
//{
//	char str[] = "111";
//	cout << invert(str);
//}
//
//void sort(int* arr, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] > arr[i - 1])
//		{
//			int temp = arr[i];
//			arr[i] = arr[i - 1];
//			arr[i - 1] = temp;
//		}
//	}
//
//}
//
////  C:\users\desktop\papka\ivanov.exe
//
//void upper(char* str)
//{
//	int len = 0;
//	for (; str[len]; len++);
//	int i = 0;
//
//	if (isalpha(str[0])) str[0] = toupper(str[0]);
//
//	for (int i =1; i < len; i++)
//	{
//		if (isalpha(str[i]) && str[i - 1] == ' ')  str[i] = toupper(str[i]);
//	}
//	
//}
//
//char* invert(char* num)
//{
//	int res=0;
//	int len = 0;
//	for (; num[len]; len++);
//	for (int i = len - 1; i >= 0; i--)
//	{
//		res += (num[i] - '0') * pow(2, len - 1 - i);
//	}
//
//	int size = 0;
//	for (int temp = res; temp > 0; temp /= 10) size++;
//
//	char* str = new char[size+1];
//	str[size] = '\0';
//	while (res > 0)
//	{
//		str[size-1] = res % 10+'0';
//		size--;
//		res /= 10;
//	}
//	return str;
//}

//struct domino
//{
//	int l;
//	int r;
//};
//
//bool check(domino rad[], const int size);
//
//int main()
//{
//	const int n = 20;
//	domino rad[n];
//
//	int a;
//	srand(time(0));
//	a = rand() % 20;
//	cout << a << endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		rad[i].l = rand() % 7;
//		rad[i].r = rand() % 7;
//	}
//
//	cout << check(rad, n);
//
//	return 0;
//}
//
//bool check(domino rad[], const int size)
//{
//	bool res = 0;
//	for (int i = 0; i < size-1; i++)
//	{
//		if (rad[i].r == rad[i + 1].l) { res = 1; }
//		else { res = 0; }
//	}
//	return res;
//}

//int main()
//{
//	long long int chys, znam;
//	cin >> chys >> znam;
//
//	long long int a, b, temp;
//	/*if (chys > znam) { a = chys; b = znam; }
//	else { a = znam; b = chys; }*/
//	a = chys; b = znam;
//	for (; a % b != 0;)
//	{
//		temp = b;
//		b = a % b;
//		a = temp;
//	}
//	cout << chys / b << '/' << znam / b;
//}

//int p(int n);
//void task16();
//
//int main()
//{
//	task16();
//	return 0;
//}
//
//int p(int n) {
//	int res = 0;
//	bool arr[16];
//	for (int i = 0; i < 16; i++) arr[i] = false;
//	while (n != 0) {
//		arr[n % 16] = true;
//		n /= 16;
//	}
//	for (int i = 0; i < 16; i++) if(arr[i]) ++res;
//	return res;
//}
//void task16() {
//
//	string input;
//	cin >> input;
//
//	int i, res, a;
//	res = 0;
//	for (i = 0; input[i]; i++)
//	{
//		if (isdigit(input[i])) a = input[i] - '0';
//		else a = toupper(input[i]) - 'A'+10;
//		res = res * 16 + a;
//	}
//	cout << res;
//}

//int main()
//{
//	char str[512] = "I`m OK! I`m not alcoholic.";
//
//	cout << str<<endl;
//
//	for (int i = 0; str[i]; i++)
//	{
//		if (isalpha(str[i]))
//		{
//			if (isupper(str[i])) str[i]=tolower(str[i]);
//			else  str[i]=toupper(str[i]);
//		}
//	}
//
//	cout << str;
//return 0;
//}

//int main()
//{
//	FILE* file;
//	file = fopen("C:/Users/Antl_M/Desktop/Lesson.txt", "r");
//
//	size_t size=0;
//
//	while (!feof(file))
//	{
//		char* line= new char[BUFSIZ];
//		fgets(line, BUFSIZ, file);
//		int i = 0;
//		for (; line[i]; i++);
//		if (i > size) size = i;
//	}
//	fclose(file);
//	cout << size;
//}

//int main()
//{
//	char* str=new char[BUFSIZ];
//	cin.getline(str, BUFSIZ);
//	bool isn=0, isa=0;
//	int i = 0;
//	int res = 0;
//	for (; str[i]; i++)
//	{
//		if (isalnum(str[i]))
//		{
//			if (isalpha(str[i])) isa = 1;
//			if (isdigit(str[i])) isn = 1;
//		}
//		else
//		{
//			if (isa && !isn)res++;
//			isa = 0;
//			isn = 0;
//		}
//	}
//	if (isa && !isn)res++;
//	cout << res;
//	return 0;
//}

//void foo(char* str);
//int find(char* s, char* c);
//int main()
//{
//	char a[2000] = "ф ф ф ф ф ф ф ф ф ф ффф  фффф     фф";
//	foo(a);
//	//if (find(a, b)) cout << "nope";
//}
//
//void foo(char* str)
//{
//	int res = 0;
//	char b[200] = "";
//	char temp[20] = "~";
//	for (int i = 0; i < strlen(str); i++) {
//		if (str[i] == ' ') {
//			char t[2] = { '~','\0' };
//			strcat(temp, t);
//			if (find(b, temp)==0&& temp[1] != '~') {
//				res++;
//				strcat(b, temp);
//			}
//			strcpy(temp, "~");
//		}
//		else {
//			char t[2] = { str[i],'\0' };
//			strcat(temp, t);
//		}
//	}
//	char t[2] = { '~','\0' };
//	strcat(temp, t);
//	if (find(b, temp)==0 && temp[1] != '~') res++;
//	cout << res;
//}
//
//int find(char* s, char* c)
//{
//	int lenC, lenS;
//	for (lenC = 0; c[lenC]; lenC++);
//	for (lenS = 0; s[lenS]; lenS++);
//	for (int i = 0, j; i <= lenS - lenC; i++)
//	{
//		j = 0;
//		for (; s[i + j] == c[j]; j++);
//		if (j == lenC)  return 1;
//	}
//	return 0;
//}