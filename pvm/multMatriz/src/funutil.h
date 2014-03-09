#ifndef FUNUTIL 
#define FUNUTIL 
#include <stdio.h>

int** crearMatriz(int n, int m);
void logPVM(int tid, const char *info);
void imprimirMatriz(FILE *out, int **m, int tamano);
int** crearMatrizLimitada(unsigned int n, unsigned int m, int limSup, int limInf);

#endif
