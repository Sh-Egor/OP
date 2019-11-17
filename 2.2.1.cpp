#include <iostream>
#include <cmath>
#include "dpoint.h"
using namespace std;

double
F(dpoint a)
{
	return a.func();
}

void
dpoint::enter(){
	for(int i = 1; i <= size; i++){
		cin >> x[i];
	}
}

void
dpoint::show(){
	for(int i = 1; i <= size; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

dpoint 
dpoint::operator*(double mult){
	dpoint res(size);
	for(int i = 1; i <= size; i++){
		res.x[i] = x[i]*mult;
	}
	return res;
}

dpoint 
dpoint::operator-(dpoint R){
	dpoint res(size);
	for(int i = 1; i <= size; i++){
		res.x[i] = x[i] - R.x[i];
	}
	return res;
}

dpoint
dpoint::operator-=(dpoint R)
{
	for(int i = 1; i <= size; i++){
		x[i] -= R.x[i];
	}
	return *this;
}

dpoint 
dpoint::grad(){
	double h = 0.000001;
	dpoint res(size);
	for(int i = 1; i <= size; i++){
		dpoint tmp(*this); 
		tmp.x[i] += h;
		res.x[i] = (F(tmp) - F(*this))/h;
	}
	return res;
}

double 
dpoint::sNorm(){
	double res = 0;
	for(int i = 1; i <= size; i++){
		res += x[i]*x[i];
	}
	return sqrt(res);
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

