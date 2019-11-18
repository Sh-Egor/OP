#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double
F(double x)
{
	//return (x-1)*(x-1);
	//return x*x*x*4 - x*x*8 - x*11 + 5;
	//return x + 3/(x*x);
	//return  (x + 2.5)/(4 - x*x);
	//return -sin(x) - sin(x*3)/3;
	return -sin(x)*2 - sin(x*2) - sin(x*3)*2/3;
}

double
minimize(double* x)
{
	double min;
	int ind;
	min = F(x[1]);
	ind = 1;
	for (int i = 2; i < 4; ++i){
		if(F(x[i]) < min){
			min = F(x[i]);
			ind = i;
		}
	}
	return x[ind];
}

double
Formula(double* x)
{
	double res = 0.5;
	double top = 1.0;
	double bot = 1.0;
	top =                                                                (x[2] + x[3])*(x[2] - x[3])*F(x[1]) +                        (x[3] + x[1])*(x[3] - x[1])*F(x[2]) +                        (x[1] + x[2])*(x[1] - x[2])*F(x[3]);  
	bot =                                                                (x[2] - x[3])*F(x[1]) +                                      (x[3] - x[1])*F(x[2]) +                                      (x[1] - x[2])*F(x[3]);   
	res = res*top/bot;
	return res;
}

void
resort(double* x)
{
	for (int i = 1; i < 5; i++){
        for (int j = 1; j < 5 - i; j++){
            if (x[j] > x[j + 1]){
                double temp;
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}

void
renum(double* x)
{
	for (int i = 1; i < 5; i++){
        for (int j = 1; j < 5 - i; j++){
            if (F(x[j]) > F(x[j + 1])){
                double temp;
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 4 - i; j++){
            if (x[j] > x[j + 1]){
                double temp;
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
}

int
main(void)
{
	double a,b,eps;
	printf("Enter a,b, eps\n");
	scanf("%lf %lf %lf",&a, &b, &eps);
	double x[5];
	x[1] = a;
	x[3] = b;
	x[2] = 0.5*(x[1]+x[3]);
	x[0] = minimize(x);
	x[4] = Formula(x);
	int k = 0;
	while(fabs(x[4] - x[0]) > eps && k < 10){
		resort(x);
		renum(x);
		x[0] = minimize(x);
		x[4] = Formula(x);
		k++;
	}
	printf("%lf\n",x[4]);
	return 0;
}