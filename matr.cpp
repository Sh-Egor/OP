#include "matr.h"
#include "dpoint.h"
#include "gauss.cpp"


void
matr::show()
{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << x[i][j] << " ";
		}
		cout << " | " << endl;
	}
}
/*
	Gen Hesse matrix
*/
matr::matr(dpoint dot)
{
	size = dot.size;
	x = (double**)malloc(size*sizeof(double*));
	for(int i = 0; i < size; i++){
		x[i] = (double*)malloc(size*sizeof(double));
	}
	double h = 0.00000001;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			/*magic mixed derivative formula*/
			double res = 0;
			dpoint t(dot);
			res += F(t);
			t.x[i] += h;
			res -= F(t);
			t.x[j] += h;
			res += F(t);
			t.x[i] -= h;
			res -= F(t);
			res = res/(h*h);
			x[i][j] = res;
		}
	}
}

void
matr::backm(const matr& H)
{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			x[i][j] = 0;
		}
		x[i][i] = 1;
	}
	gauss(H.x,x,size);}

matr::~matr()
{
	for(int i = 0; i < size; i++){
		free(x[i]);
	}
	free(x);
}

dpoint
matr::operator*(dpoint R)
{
	dpoint res(R.size);
	for(int i = 0; i < size; i++){
		res.x[i] = 0;
		for(int j = 0; j < size; j++){
			res.x[i] += x[i][j]*R.x[j];
		}
	}
	return res;
}