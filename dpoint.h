class dpoint{
public:
	double* x;
	int size;
	dpoint(int S){
		x = (double*)malloc((S + 1)*sizeof(double));
		size = S;
	}
	dpoint(const dpoint& R){
		size = R.size;
		x = (double*)malloc((size + 1)*sizeof(double));
		for(int i = 1; i <= size; i++){
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