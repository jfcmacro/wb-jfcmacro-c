/* Problema de las comparaciones con reales */
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {

  float i = 0.0;      // Valor indice
  float delta = 0.01; // delta
 
  // Se inicia el ciclo
  for (i = 0.0; i != 10.0; i+=delta) {
    printf("i: %f\n", i);
  }

  exit(0);
}
