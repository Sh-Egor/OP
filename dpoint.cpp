#include <cmath>
#include <iostream>
#include "dpoint.h"
using namespace std;

void
dpoint::enter()
{
	for(int i = 0; i < size; i++){
		cin >> x[i];
	}
}

void
dpoint::show()
{
	for(int i = 0; i < size; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}

dpoint 
dpoint::operator*(double mult)
{
	dpoint res(size);
	for(int i = 0; i < size; i++){
		res.x[i] = x[i]*mult;
	}
	return res;
}

dpoint 
dpoint::operator-(dpoint R)
{
	dpoint res(size);
	for(int i = 0; i < size; i++){
		res.x[i] = x[i] - R.x[i];
	}
	return res;
}

dpoint 
dpoint::operator+(dpoint R)
{
	dpoint res(size);
	for(int i = 0; i < size; i++){
		res.x[i] = x[i] + R.x[i];
	}
	return res;
}

dpoint
dpoint::operator-=(dpoint R)
{
	for(int i = 0; i < size; i++){
		x[i] -= R.x[i];
	}
	return *this;
}

dpoint
dpoint::operator+=(dpoint R)
{
	for(int i = 0; i < size; i++){
		x[i] += R.x[i];
	}
	return *this;
}

dpoint 
dpoint::grad()
{
	double h = 0.000001;
	dpoint res(size);
	for(int i = 0; i < size; i++){
		dpoint tmp(*this); 
		tmp.x[i] += h;
		res.x[i] = (F(tmp) - F(*this))/h;
	}
	return res;
}

double 
dpoint::sNorm()
{
	double res = 0;
	for(int i = 0; i < size; i++){
		res += x[i]*x[i];
	}
	return sqrt(res);
}

double
dpoint::func()
{
	return   (x[0] - 5)*(x[0] - 5)*4 + (x[1] - 6)*(x[1] - 6);
	//return   (x[0]*x[0] + x[1] - 11)*(x[0]*x[0] + x[1] - 11) +       (x[0] + x[1]*x[1] - 7)*(x[0] + x[1]*x[1] - 7);
	//return (x[1] - x[0]*x[0])*(x[1] - x[0]*x[0])*100 + (1 - x[0])*(1 - x[0]) + (x[3] - x[2]*x[2])*(x[3] - x[2]*x[2])*90 + (1 - x[2])*(1 - x[2]) + ((x[1] - 1)*(x[1] - 1) +         (x[3] - 1)*(x[3] - 1))*10.1 + (x[1] - 1)*(x[3] - 1)*19.8; 
	//return pow(x[0]+x[1]*10,2) + pow(x[2]-x[3],2)*5 + pow(x[1]-x[2]*2,4) + pow(x[0]-x[3],4)*10;     
}

double
F(dpoint a)
{
	return a.func();
}