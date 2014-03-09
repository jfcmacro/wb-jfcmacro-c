#include <stdio.h>

void
imprimirMatriz(FILE* out, int **m, int tamano) {

  int i, j;

  for (i = 0; i < tamano; i++) {
    for (j = 0; j < tamano; j++) {
      fprintf(out, "%d ", m[i][j]);
    }
    fprintf(out, "\n");
  }
  return;
}
