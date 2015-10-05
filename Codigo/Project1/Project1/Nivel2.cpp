#include <cstdio>
#include <cstdlib>
#include <mkl.h>

int main(int argc, char*argv[]){
	double fin, inicio = dsecnd();
	inicio = dsecnd();
	/* BODY */
	double A[9] = {1.0, 2.0, 3.0, 4.0, 5, 6, 7, 8, 9};
	double B[3] = { 10.0, 11.0, 12.0 };
	double C[3];
	// calculo de la norma o modulo
	cblas_dgemv(CblasRowMajor,CblasNoTrans,3,3,1.0,A,3,B,1,0.0,C,1); // RowMajor dice que se codifica por filas, CblasNoTrans no es transpose
	for (int i = 0; i < 3; i++) printf("%lf\n", C[i]);
	fin = dsecnd();
	printf("Tiempo: %lf msec\n\n",(fin-inicio)*1.0e3);
	cblas_dgemv(CblasRowMajor, CblasTrans, 3, 3, 1.0, A, 3, B, 1, 0.0, C, 1); // RowMajor dice que se codifica por filas, CblasNoTrans no es transpose
	for (int i = 0; i < 3; i++) printf("%lf\n", C[i]);
	fin = dsecnd();
	printf("Tiempo: %lf msec\n\n", (fin - inicio)*1.0e3);
	std::getchar();
	return 0;
}