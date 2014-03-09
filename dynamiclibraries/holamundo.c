#include <stdio.h>

static int valor = 0;

void
holamundo() {
  
  valor++;
  fprintf(stdout, "Hola Mundo\n");
}

int
vecesValor() {
  return valor;
}
