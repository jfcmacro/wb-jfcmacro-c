#include <stdio.h>

int
main() {

  int nProceso;

  scanf("%d\n", &nProceso);

  int vector[nProceso];

  fprintf(stdout, "sizeof(int) %d Salida: %d\n", sizeof(int), sizeof(vector));
  return 0;
}
