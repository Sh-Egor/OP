double*
inb(int n)
{
	double* cur = (double*)malloc(n*sizeof(double));
	for(int i = 0; i < n; i++){
		cur[i] = 0;
	}
	return cur;
}

void
copyb(double* to, double* from, int n)
{
	for(int i = 0; i < n; i++){
		to[i] = from[i];
	}
}

void
swap(double** mas,int from, int to, int n)
{
	double* cur = inb(n);
	copyb(cur,mas[from],n);
	copyb(mas[from],mas[to],n);
	copyb(mas[to],cur,n);
	free(cur);
}

void
divide(double** A, int num, double count, int n)
{
	for(int i = 0; i < n; i++){
		A[num][i]/=count;
	}
}

void
minusv(double** A, int base, int cur, double count, int n)
{
	for(int i = 0;i < n; i++){
		A[cur][i] = A[cur][i] - A[base][i]*count;
	}
}

void
gauss(double** A, double** B, int n)
{
	double tmp;
	double det = 1.0;
	for(int i = 0; i < n && det; i++){//сравнение double и 0
		if(A[i][i] == 0){
			for(int j = i+1; j < n; j++){
				if(A[j][i] != 0){//сравнение double и 0
					swap(B,i,j,n);
					swap(A,i,j,n);
				}
			}
		}
		det*=A[i][i];
		if(A[i][i] != 0){
			divide(B,i,A[i][i],n);
			divide(A,i,A[i][i],n);
			for(int j = i+1; j < n; j++){
				minusv(B,i,j,A[j][i],n);
				minusv(A,i,j,A[j][i],n);
			}
		}
	}
	if(det != 0){
		for(int i = n-1; i > 0; i--){
			for(int j = i-1; j >= 0; j--){
				minusv(B,i,j,A[j][i],n);
				minusv(A,i,j,A[j][i],n);
				}
			}
	}
}
