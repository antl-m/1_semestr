#include <__msvc_all_public_headers.hpp>
#include <deque>

using namespace std;
class matrix
{
public:
	
	deque<deque<double>> val;
	int n;
	int m;
	matrix(int a, int b);
	void random(int x=3);
	double minor(int a, int b);
	matrix inv();
	bool sym(matrix b);
	void input();
	friend matrix rivn(matrix a, matrix b);
	friend matrix  operator* (matrix a, matrix b);
	friend matrix  operator+ (matrix a, matrix b);
	friend matrix  operator- (matrix a, matrix b);
	friend matrix  trans(matrix a);
	friend int det(matrix a);
	friend std::ostream& operator<< (std::ostream &out,matrix & a);

};