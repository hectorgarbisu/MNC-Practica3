#include <cstdio>
#include <cstdlib>

#include <mkl.h>

int min(int argc, char*argv[]){
	double fin, inicio = dsecnd();
	inicio = dsecnd();
	printf("Hola, weqeq");
	fin = dsecnd();
	prinf("Tiempo: %lf usec\n", (fin - inicio)*1.0e6);
	std::getchar();
	return 0;
}