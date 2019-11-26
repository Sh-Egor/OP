#include <iostream>
#include <stdio.h>
#include "dpoint.cpp"
#include "matr.cpp"
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
	FILE* out = fopen("data.txt","w");
	fclose(out);
	cout << "Enter V size" << endl;
	cin >> N;
	dpoint start(N);
	cout << "Enter start dot" << endl;
	start.enter();
	cout << "Enter eps" << endl;
	cin >> eps;
	addFile(start);
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
		addFile(start);
		k++;
	}
	start.show();
	cout << "k = " << k << endl;
	cout << F(start) << endl;
	return 0;
}

