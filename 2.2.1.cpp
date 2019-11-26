#include <iostream>
#include <stdio.h>
#include "dpoint.cpp"
using namespace std;

void
addFile(dpoint dot)
{
	FILE* out = fopen("data.txt","a+");
	fprintf(out, "%lf %lf %lf\n",dot.x[0],dot.x[1],F(dot));
	fclose(out);
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
	FILE* out = fopen("data.txt","w");
	fclose(out);
	double eps;
	cout << "Enter V size" << endl;
	cin >> N;
	dpoint start(N);
	cout << "Enter start dot" << endl;
	start.enter();
	cout << "Enter eps" << endl;
	cin >> eps;
	addFile(start);
	while(start.grad().sNorm() > eps && k < 1000000){
		double a = argmin(start, start.grad());
		start -= start.grad()*a;
		addFile(start);
		k++;
	}
	start.show();
	cout << "k = " << k << endl;
	cout << F(start) << endl;
	start.grad().show();
	cout << start.grad().sNorm() << endl;
	return 0;
}
