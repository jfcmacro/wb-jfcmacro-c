#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>

void
setMatriz(double *posInicial, int fil, int i, int j, double valor) {
  *(posInicial + (sizeof(double)*(i*fil + j))) = valor;
}

double
getMatriz(double *posInicial, int fil, int i, int j, double valor) {
  return *(posInicial + (sizeof(double)*(i*fil + j)));
}

int
main(int argc, char *argv[]){

  int col = 0;
  int fil = 0;
  int i; 
  int j;
  double *matriz;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <fil> <col>", argv[0]);
    exit(1);
  }

  col = strtol(argv[1], NULL, 10);
  fil = strtol(argv[2], NULL, 10);

  if ((col <= 0) && (fil <= 0)) {
    fprintf(stderr, "Col or fil is zero or less that zero\n");
    exit(1);
  }

  matriz = (double *) malloc(sizeof(double) * col * fil);

  for (i = 0; i < fil; i++) {

    for (j = 0; j < col; j++) {
      setMatriz(matriz, fil, i, j, 0.0);
    }
  }

  setMatriz(matriz, fil, 1, 1, 1.1);
  setMatriz(matriz, fil, 0, 1, 0.1);
  setMatriz(matriz, fil, 1, 0, 1.0);
  setMatriz(matriz, fil, 0, 0, 0.0);

  fprintf(stdout, "Valor matriz(1,1) %f", getMatriz(matriz, fil, 1, 1, 1.1));

  exit(0);
}
