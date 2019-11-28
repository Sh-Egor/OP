#include <iostream>
#include <cmath>
#include <valarray>
using namespace std;

double
second_norm(valarray<double> x)
{
	double res = 0;
	for(int i = 0; i < x.size(); i++){
		res += x[i]*x[i];
	}
	return sqrt(res);
}

double
f(valarray<double>  x)
{
	return   (x[0] - 5)*(x[0] - 5)*4 + (x[1] - 6)*(x[1] - 6);
	//return   (x[0]*x[0] + x[1] - 11)*(x[0]*x[0] + x[1] - 11) +       (x[0] + x[1]*x[1] - 7)*(x[0] + x[1]*x[1] - 7);
	//return (x[1] - x[0]*x[0])*(x[1] - x[0]*x[0])*100 + (1 - x[0])*(1 - x[0]) + (x[3] - x[2]*x[2])*(x[3] - x[2]*x[2])*90 + (1 - x[2])*(1 - x[2]) + ((x[1] - 1)*(x[1] - 1) +         (x[3] - 1)*(x[3] - 1))*10.1 + (x[1] - 1)*(x[3] - 1)*19.8; 
	//return pow(x[0]+x[1]*10,2) + pow(x[2]-x[3],2)*5 + pow(x[1]-x[2]*2,4) + pow(x[0]-x[3],4)*10;     
}

valarray<double>
search(valarray<double>  src, valarray<double>  h)
{
	valarray<double> dst(src.size());
	double fb,f0;
	dst = src;
	fb = f(dst);
	for(int i = 0; i < src.size(); i++){
		valarray<double> tmp(src.size());
		tmp = dst;
		tmp[i] += h[i];
		if(f(tmp) < fb){
			dst = tmp;
			fb = f(tmp);
		}else{
			tmp[i] -= h[i]*2;
			if(f(tmp) < fb){
				dst = tmp;
				fb = f(tmp);
			}
		}
	}
	return dst;
}

int 
main(void) 
{
	int size;
	cout << "Enter V size:" << endl;
	cin >> size;
	double eps;
	double z = 0.1;
	cout << "Enter eps:" << endl;
	cin >> eps;
	valarray<double> b1(size);
	valarray<double> b2(size);
	valarray<double> h(size);
	valarray<double> x(size);
	valarray<double> xk(size);
	cout << "Enter b:" << endl;
	for(int i = 0; i < size; i++){
		cin >> b1[i];
	}
	cout << "Enter h:" << endl;
	for(int i = 0; i < size; i++){
		cin >> h[i];
	}
	while(second_norm(h) >= eps){
		xk = b1;
		b2 = search(xk,h);
		do{
			xk += b2;
			xk += b2;
			xk -= b1;
			x = search(xk,h);
			b1 = b2;
			if(f(x) <= f(b1)){
				b2 = x;
			}
		}while(f(x) <= f(b1));
		for(int i = 0; i < h.size(); i++)
			h[i] *= z;
	}
	for(int i = 0; i < b1.size(); i++){
		cout << b1[i] << " ";
	}
	cout << endl << f(b1) << endl;
	return 0;
}