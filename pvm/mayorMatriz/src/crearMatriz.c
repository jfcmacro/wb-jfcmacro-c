#include <stdlib.h>
#include <time.h>

int** 
crearMatriz(unsigned int n, unsigned int m) {
  int i;
  int j;
  int **matriz;

  srandom(time(NULL));
  matriz = (int **) malloc(sizeof(int *) * n);

  for (i = 0; i < n; i++) {
    matriz[i] = (int *) malloc(sizeof(int) * m);
    for (j = 0; j < n; j++) {
      matriz[i][j] = random();
    }
  }
  return matriz;
}
