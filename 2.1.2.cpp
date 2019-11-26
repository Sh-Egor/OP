#include <iostream>
#include <valarray>
using namespace std;

int 
main(void) 
{
	int size;
	cout << "Enter V size:" << endl;
	cin >> size;
	valarray<double> b1(size);
	valarray<double> b2(size);
	valarray<double> h(size);
	valarray<double> x(size);
	cout << "Enter b:" << endl;
	for(int i = 0; i < size; i++){
		cin >> b[i];
	}
	cout << "Enter h:" << endl;
	for(int i = 0; i < size; i++){
		cin >> h[i];
	}
	
	return 0;
}