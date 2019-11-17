#include <iostream>
#include "dpoint.cpp"
using namespace std;

double
F(dpoint a)
{
	return a.func();
}


double
argmin(dpoint L, dpoint R)
{
	double a = 16;
	double crn = F(L - R*a);
	a /= 2;
	double min = F(L - R*a);
	while(min < crn){
		crn = min;
		a /=2 ;
		min = F(L - R*a);
	}
	return a;
}

int
main(void)
{
	int N;
	int k = 0;
	double eps;
	cout << "Enter V size" << endl;
	cin >> N;
	dpoint start(N);
	cout << "Enter start dot" << endl;
	start.enter();
	cout << "Enter eps" << endl;
	cin >> eps;
	while(start.grad().sNorm() > eps && k < 1000000){
		double a = argmin(start, start.grad());
		start -= start.grad()*a;
		k++;
	}
	start.show();
	cout << "k = " << k << endl;
	cout << F(start) << endl;
	start.grad().show();
	cout << start.grad().sNorm() << endl;
	return 0;
}

