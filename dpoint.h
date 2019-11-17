#ifndef DPOINT_H
#define DPOINT_H
class dpoint{
public:
	double* x;
	int size;
	dpoint(int S){
		x = (double*)malloc((S)*sizeof(double));
		size = S;
	}
	dpoint(const dpoint& R){
		size = R.size;
		x = (double*)malloc((size)*sizeof(double));
		for(int i = 0; i < size; i++){
			x[i] = R.x[i];
		}
	}
	void enter();
	void show();
	dpoint operator*(double);
	dpoint operator-(dpoint);
	dpoint operator+(dpoint);
	dpoint operator-=(dpoint);
	dpoint operator+=(dpoint);
	dpoint grad();
	double sNorm();
	double func();
	~dpoint(){
		free(x);
	}
};
double F(dpoint);
#endif