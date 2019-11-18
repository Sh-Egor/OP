#include <iostream>
#include <cmath>
using namespace std;

double
f(double x)
{
	//return (x-1)*(x-1);
	//return x*x*x*4 - x*x*8 - x*11 + 5;
	//return x + 3/(x*x);
	//return  (x + 2.5)/(4 - x*x);
	//return -sin(x) - sin(x*3)/3;
	return -sin(x)*2 - sin(x*2) - sin(x*3)*2/3;
}

int
DSK(double* res, double x0, double h)
{
	double a,b;
	int k = 2;
	if(f(x0) > f(x0 + h)){
		a = x0;
	}else{
		if(f(x0 - h) >= f(x0)){
			res[0] = x0 - h;
			res[1] = x0 + h;
			return 1;
		}else{
			b = x0;
			h = -h;
		}
	}
	while(1 && k < 1000000){
		if(f(x0 + h*pow(2,k-2)) <= f(x0 + h*pow(2,k-1))){
			if(h > 0){
				b = x0 + h*pow(2,k-1);
			}else{
				a = x0 + h*pow(2,k-1);
			}
			res[0] = a;
			res[1] = b;
			return 1;	
		}else{
			if(h > 0){
				a = x0 + h*pow(2,k-2);
			}else{
				b = x0 + h*pow(2,k-2);
			}
			k++;
		}
	}
	return 0;
}

int
main(void)
{
	double x0,h;
	double res[2];
	cout << "enter x0 and h:" << endl;
	cin >> x0 >> h;
	DSK(res,x0,h);
	cout << "[" << res[0] << "," << res[1] << "]" << endl;
}