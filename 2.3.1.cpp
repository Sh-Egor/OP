#include <iostream>
#include "dpoint.cpp"
#include "matr.cpp"
using namespace std;

double
argmin(dpoint L, dpoint R)
{
	double a = 256;
	double crn = F(L + R*a);
	a /= 2;
	double min = F(L + R*a);
	while(min < crn && a > 0.001){
		crn = min;
		a /=2 ;
		min = F(L + R*a);
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
		matr H(start);
		matr H1(start);
		H1.backm(H);
		dpoint p(start.size);
		for(int i = 0; i < p.size; i++){
			p.x[i] = 0;
		}
		p -= H1*(start.grad());
		double a = argmin(start, p);
		start += p*a;
		k++;
	}
	start.show();
	cout << "k = " << k << endl;
	cout << F(start) << endl;
	return 0;
}

