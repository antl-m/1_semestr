#include <__msvc_all_public_headers.hpp>

using namespace std;

int main()
{
		time_t seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);
		cout << timeinfo->tm_hour << endl;
		cout << timeinfo->tm_mday  << endl;
		cout << timeinfo->tm_min << endl;
		cout << timeinfo->tm_mon << endl;
		cout << asctime(timeinfo) << endl;

	return 0;
}