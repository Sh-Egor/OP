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

int
argmin(dpoint R, int i, double h)
{
	double a = 1;
	dpoint tmpl(R);
	dpoint tmpr(R);
	double pos, neg;
	tmpl.x[i] -= h;
	tmpr.x[i] += h;
	if(F(tmpl) < F(R)){
		a = -1;
		dpoint cur(R);
		while(F(tmpl) < F(cur)){
			cur = tmpl;
			tmpl.x[i] -= h;
			a--;
		}
		return a + 1;
	}else if (F(tmpr) < F(R)){
		dpoint cur(R);
		while(F(tmpr) < F(cur)){
			cur = tmpr;
			tmpr.x[i] += h;
			a++;
		}
		return a - 1;
	}
	return 0;
}

int
main(void)
{
	int n;
	double eps;
	double z = 0.5;
	FILE* out = fopen("data.txt","w");
	fclose(out);
	cout << "Enter V size:" << endl;
	cin >> n;
	cout << "Enter eps:" << endl;
	cin >> eps;
	dpoint x(n);
	cout << "Enter start dot:" << endl;
	x.enter();
	dpoint h(n);
	cout << "Enter h dot:" << endl;
	h.enter();
	dpoint x1(x);
	int k = 1;
	addFile(x);
	while((h.sNorm() > eps || !(x == x1)) && k < 35){
		x1 = x;
		for(int i = 0; i < x.size; i++){
			int a = argmin(x,i,h.x[i]);
			x.x[i] += h.x[i]*a;
		}
		h *= z;
		k++;
	/*	cout << "__________________" << endl;
		x.show();
		x1.show();
		h.show();*/
		addFile(x);
	}
	x.show();
	cout << F(x) << endl;
	return 0;
}