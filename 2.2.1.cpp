#include <iostream>
using namespace std;

class dpoint{
private:
	double x;
	double y;
public:
	dpoint();
	dpoint(double a, double b){
		x = a;
		y = b;
	}
	dpoint operator+(dpoint& left, dpoint& right){
		return dpoint(left.x + right.x, left.y + right.y);
	}
	dpoint operator-(dpoint& left, dpoint& right){
		return dpoint(left.x - right.x, left.y - right.y);
	}
	dpoint operator*(dpoint& left, double right){
		return dpoint(left.x*right, left.y*right);
	}
	dpoint operator*(double left, dpoint& right){
		return dpoint(right.x*left, right.y*left);
	}
	dpoint operator/(dpoint& left, double right){
		if(right != 0)
			return dpoint(left.x/right, left.y/right);
		return left;
	}
	~dpoint();
};

double
F(dpoint& a)
{

}

dpoint
grad(dpoint& dot)
{

}

