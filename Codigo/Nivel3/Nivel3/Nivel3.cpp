#include <cstdio>
#include <cstdlib>
#include <mkl.h>
#include <ctime>
#include <cmath>

#define N 2000
#define NTEST 100
int main(int argc, char*argv[]){
	double fin, inicio = dsecnd();
	/* BODY */
	double *A = (double*)mkl_malloc(N*N*sizeof(double), 64);
	if (A == (double*)NULL){ perror("Error Malloc"); exit(1); }

	double *B = (double*)mkl_malloc(N*N*sizeof(double), 64);
	if (B == (double*)NULL){ perror("Error Malloc"); exit(1); }

	double *C = (double*)mkl_malloc(N*N*sizeof(double), 64);
	if (C == (double*)NULL){ perror("Error Malloc"); exit(1); }

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)		{
			A[i*N + j] = (double)rand() / (double)RAND_MAX;
			B[i*N + j] = (double)rand() / (double)RAND_MAX;
		}
	}
	inicio = dsecnd();
	for (int c = 0; c < NTEST; c++)
		cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1, A, N, B, N, 0, C, N);
	fin = dsecnd();
	double tiempo = (fin - inicio)/(double)NTEST;
	
	/* END */
	printf("Tiempo: %lf msec\n\n", tiempo*1.0e3);
	printf("Gflops: %lf\n", 2.0*pow((double)N, 3.0)*1.0e-9 / tiempo);
	mkl_free(A);
	mkl_free(B);
	mkl_free(C);

	std::getchar();
	return 0;
}