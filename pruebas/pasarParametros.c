#include <stdio.h>
int
f(void *p) {

  int valor = (int) p;

  return valor;
}

int
main() {

  int valor = 10;

  fprintf(stdout, "Valor retornado: %d\n", f((void *) valor));
}
