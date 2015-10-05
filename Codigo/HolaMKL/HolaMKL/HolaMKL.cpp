#include <cstdio>
#include <cstdlib>
#include <mkl.h>

int main(int argc, char*argv[]){
	double fin, inicio = dsecnd();
	inicio = dsecnd();
	/* BODY */
	double A[4] = { 1.0, 2.0, 3.0, 4.0 };
	double B[4] = { 5.0, 6.0, 7.0, 8.0 };
	// calculo de la norma o modulo
	double norma = cblas_dnrm2(4, A, 1); // ese 1 es el incremento
	printf("Norma de A: %lf\n", norma); 
	norma = cblas_dnrm2(4, B, 1); 
	printf("Norma de B: %lf\n", norma);
	// calculo de p escalar
	double pescalar = cblas_ddot(4, A, 1, B, 1);
	cblas_daxpy(4, 2.0, A, 1, B, 1);
	printf("Suma ponderada:\n");
	for (int i = 0; i < 4; i++) printf("%lf\n", B[i]);
	fin = dsecnd();
	std::getchar();
	return 0;
}