#include <iostream>
using namespace std;

double
f(double x, double y)
{
	return 5*x*y + x*x*y/2;
}

int
main(void)
{
	double x,y;
	cin >> x >> y;
	double h = 0.00001;
	double g = 0.000011;
	double x1,x2;

	x1 = (f(x+h,y) - f(x,y))/h;
	x2 = (f(x+h,y+g) - f(x,y+g))/h;
	double res = (x2 - x1)/g;
	cout << "res = " << res << endl;
	return 0;
}