#include "dpoint.h"
#ifndef MATR_H
#define MATR_H
class matr
{
public:
	double** x;
	int size;
	matr(dpoint);// build gesse matrix
	void backm(const matr& );// gen backmatr
	dpoint operator*(dpoint);
	void show();
	~matr();
};
#endif