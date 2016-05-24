#include <stdio.h>

short matAdd(double* m1, double* m2, double* ans, short m,short n);
short matMulti(double* mat1, double* mat2, double* ans, short m1,short n1, short m2,short n2);
short matPrint(double* mat,short m, short n);

main(){
	double a[9]={
		1.0, 2.0, 3.0,
		4.0, 5.0, 6.0,
		7.0, 8.0, 9.0};
	double b[9]={
		1.0, 1.0, 1.0,
		1.0, 1.0, 1.0,
		1.0, 1.0, 1.0};
	double c[9];

	matMulti(a,b,c,3,3,3,3);
	matPrint(c, 3, 3);
}

short matAdd(double* m1, double* m2, double* ans, short m,short n){

	short i,j;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			*(ans+i*n+j)=*(m1+i*n+j)+*(m2+i*n+j);
		}
	}


	return 0;
}

short matMulti(double* mat1, double* mat2, double* ans, short m1,short n1, short m2,short n2){

	short i,j,k,l;
	double sum;
	for (i=0;i<m1;i++){
		for (j=0;j<n2;j++){
			sum=0.0;
			for(k=0;k<n1;k++){
				sum=sum+(*(mat1+i*n1+k)) * (*(mat2+k*n2+j));
			}	
			*(ans+i*n2+j)=sum;
		}
	}


	return 0;
}

short matPrint(double* mat, short m, short n){

	short i,j;
	for (i=0;i<m;i++){
		printf("|");
		for (j=0;j<n;j++){
			printf("%20.3f ", *(mat+i*n+j));
		}
		printf("|\n");
	}
	return 0;
}
