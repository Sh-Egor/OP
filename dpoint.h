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
	dpoint operator-=(dpoint);
	dpoint grad();
	double sNorm();
	double func(){
		return   (x[1] - 5)*(x[1] - 5)*4 + (x[2] - 6)*(x[2] - 6);
		//return   (x[1]*x[1] + x[2] - 11)*(x[1]*x[1] + x[2] - 11) +     (x[1] + x[2]*x[2] - 7)*(x[1] + x[2]*x[2] - 7);
		//return (x[2] - x[1]*x[1])*(x[2] - x[1]*x[1])*100 + (1 - x[1])*(1 - x[1]) + (x[4] - x[3]*x[3])*(x[4] - x[3]*x[3])*90 + (1 - x[3])*(1 - x[3]) + ((x[2] - 1)*(x[2] - 1) +         (x[4] - 1)*(x[4] - 1))*10.1 + (x[2] - 1)*(x[4] - 1)*19.8; 
		//return pow(x[1]+x[2]*10,2) + pow(x[3]-x[4],2)*5 +           pow(x[2]-x[3]*2,4) + pow(x[1]-x[4],4)*10;     
	}
	~dpoint(){
		free(x);
	}
};